/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   test_ft_deque.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/15 19:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 19:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* ==================== Test Framework ==================== */

static int g_tests_passed = 0;
static int g_tests_failed = 0;

#define TEST(name) static void name(void)
#define RUN_TEST(name) do { \
	printf("  %-50s ", #name); \
	name(); \
	printf("\033[32m[PASS]\033[0m\n"); \
	g_tests_passed++; \
} while(0)

#define ASSERT(cond) do { \
	if (!(cond)) { \
		printf("\033[31m[FAIL]\033[0m\n"); \
		printf("    Assertion failed: %s\n", #cond); \
		printf("    File: %s, Line: %d\n", __FILE__, __LINE__); \
		g_tests_failed++; \
		return; \
	} \
} while(0)

#define ASSERT_EQ(a, b) ASSERT((a) == (b))
#define ASSERT_NE(a, b) ASSERT((a) != (b))
#define ASSERT_NULL(a) ASSERT((a) == NULL)
#define ASSERT_NOT_NULL(a) ASSERT((a) != NULL)

/* ==================== ft_deque_new tests ==================== */

TEST(test_deque_new_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 10);
	ASSERT_NOT_NULL(d);
	ASSERT_NOT_NULL(d->data);
	ASSERT_EQ(d->len, 0);
	ASSERT_EQ(d->cap, 10);
	ASSERT_EQ(d->elem_size, sizeof(int));
	ASSERT_EQ(d->head, 0);
	ASSERT_EQ(d->tail, 0);
	ft_deque_free(d);
}

TEST(test_deque_new_zero_elem_size)
{
	t_deque *d = ft_deque_new(0, 10);
	ASSERT_NULL(d);
}

TEST(test_deque_new_zero_capacity_defaults_to_8)
{
	t_deque *d = ft_deque_new(sizeof(int), 0);
	ASSERT_NOT_NULL(d);
	ASSERT_EQ(d->cap, 8);
	ft_deque_free(d);
}

TEST(test_deque_new_large_elem_size)
{
	typedef struct { char data[1024]; } big_struct;
	t_deque *d = ft_deque_new(sizeof(big_struct), 4);
	ASSERT_NOT_NULL(d);
	ASSERT_EQ(d->elem_size, sizeof(big_struct));
	ft_deque_free(d);
}

TEST(test_deque_new_capacity_one)
{
	t_deque *d = ft_deque_new(sizeof(int), 1);
	ASSERT_NOT_NULL(d);
	ASSERT_EQ(d->cap, 1);
	ft_deque_free(d);
}

/* ==================== ft_deque_push_back tests ==================== */

TEST(test_deque_push_back_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	int result = ft_deque_push_back(d, &val);
	ASSERT_EQ(result, 1);
	ASSERT_EQ(d->len, 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 42);
	ft_deque_free(d);
}

TEST(test_deque_push_back_null_deque)
{
	int val = 42;
	int result = ft_deque_push_back(NULL, &val);
	ASSERT_EQ(result, 0);
}

TEST(test_deque_push_back_null_elem)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int result = ft_deque_push_back(d, NULL);
	ASSERT_EQ(result, 0);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_push_back_triggers_growth)
{
	t_deque *d = ft_deque_new(sizeof(int), 2);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	ASSERT_EQ(d->cap, 2);

	val = 3; ft_deque_push_back(d, &val);
	ASSERT(d->cap > 2);
	ASSERT_EQ(d->len, 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

TEST(test_deque_push_back_many_elements)
{
	t_deque *d = ft_deque_new(sizeof(int), 1);
	int i;

	i = 0;
	while (i < 1000)
	{
		ASSERT_EQ(ft_deque_push_back(d, &i), 1);
		i++;
	}
	ASSERT_EQ(d->len, 1000);

	i = 0;
	while (i < 1000)
	{
		ASSERT_EQ(*(int *)ft_deque_get(d, i), i);
		i++;
	}
	ft_deque_free(d);
}

/* ==================== ft_deque_push_front tests ==================== */

TEST(test_deque_push_front_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	int result = ft_deque_push_front(d, &val);
	ASSERT_EQ(result, 1);
	ASSERT_EQ(d->len, 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 42);
	ft_deque_free(d);
}

TEST(test_deque_push_front_null_deque)
{
	int val = 42;
	int result = ft_deque_push_front(NULL, &val);
	ASSERT_EQ(result, 0);
}

TEST(test_deque_push_front_null_elem)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int result = ft_deque_push_front(d, NULL);
	ASSERT_EQ(result, 0);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_push_front_multiple)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 3; ft_deque_push_front(d, &val);
	val = 2; ft_deque_push_front(d, &val);
	val = 1; ft_deque_push_front(d, &val);

	ASSERT_EQ(d->len, 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

TEST(test_deque_push_front_triggers_growth)
{
	t_deque *d = ft_deque_new(sizeof(int), 2);
	int val;

	val = 1; ft_deque_push_front(d, &val);
	val = 2; ft_deque_push_front(d, &val);
	ASSERT_EQ(d->cap, 2);

	val = 3; ft_deque_push_front(d, &val);
	ASSERT(d->cap > 2);
	ASSERT_EQ(d->len, 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 3);
	ft_deque_free(d);
}

/* ==================== Mixed push_front/push_back tests ==================== */

TEST(test_deque_mixed_push)
{
	t_deque *d = ft_deque_new(sizeof(int), 8);
	int val;

	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);
	val = 1; ft_deque_push_front(d, &val);
	val = 4; ft_deque_push_back(d, &val);
	val = 0; ft_deque_push_front(d, &val);

	ASSERT_EQ(d->len, 5);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 0);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 3), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 4), 4);
	ft_deque_free(d);
}

TEST(test_deque_wraparound)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;
	int i;

	i = 0;
	while (i < 4)
	{
		val = i;
		ft_deque_push_back(d, &val);
		i++;
	}

	ft_deque_pop_front(d, NULL);
	ft_deque_pop_front(d, NULL);

	val = 10;
	ft_deque_push_back(d, &val);
	val = 11;
	ft_deque_push_back(d, &val);

	ASSERT_EQ(d->len, 4);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 10);
	ASSERT_EQ(*(int *)ft_deque_get(d, 3), 11);
	ft_deque_free(d);
}

/* ==================== ft_deque_pop_front tests ==================== */

TEST(test_deque_pop_front_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	int out;

	ft_deque_push_back(d, &val);
	int result = ft_deque_pop_front(d, &out);

	ASSERT_EQ(result, 1);
	ASSERT_EQ(out, 42);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_front_null_deque)
{
	int out;
	int result = ft_deque_pop_front(NULL, &out);
	ASSERT_EQ(result, 0);
}

TEST(test_deque_pop_front_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int out;
	int result = ft_deque_pop_front(d, &out);
	ASSERT_EQ(result, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_front_null_out)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	int result = ft_deque_pop_front(d, NULL);

	ASSERT_EQ(result, 1);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_front_multiple)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val, out;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_pop_front(d, &out);
	ASSERT_EQ(out, 1);
	ft_deque_pop_front(d, &out);
	ASSERT_EQ(out, 2);
	ft_deque_pop_front(d, &out);
	ASSERT_EQ(out, 3);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

/* ==================== ft_deque_pop_back tests ==================== */

TEST(test_deque_pop_back_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	int out;

	ft_deque_push_back(d, &val);
	int result = ft_deque_pop_back(d, &out);

	ASSERT_EQ(result, 1);
	ASSERT_EQ(out, 42);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_back_null_deque)
{
	int out;
	int result = ft_deque_pop_back(NULL, &out);
	ASSERT_EQ(result, 0);
}

TEST(test_deque_pop_back_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int out;
	int result = ft_deque_pop_back(d, &out);
	ASSERT_EQ(result, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_back_null_out)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	int result = ft_deque_pop_back(d, NULL);

	ASSERT_EQ(result, 1);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_pop_back_multiple)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val, out;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_pop_back(d, &out);
	ASSERT_EQ(out, 3);
	ft_deque_pop_back(d, &out);
	ASSERT_EQ(out, 2);
	ft_deque_pop_back(d, &out);
	ASSERT_EQ(out, 1);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

/* ==================== ft_deque_front tests ==================== */

TEST(test_deque_front_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	int *ptr = ft_deque_front(d);

	ASSERT_NOT_NULL(ptr);
	ASSERT_EQ(*ptr, 42);
	ft_deque_free(d);
}

TEST(test_deque_front_null_deque)
{
	void *ptr = ft_deque_front(NULL);
	ASSERT_NULL(ptr);
}

TEST(test_deque_front_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	void *ptr = ft_deque_front(d);
	ASSERT_NULL(ptr);
	ft_deque_free(d);
}

TEST(test_deque_front_after_push_front)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 0; ft_deque_push_front(d, &val);

	ASSERT_EQ(*(int *)ft_deque_front(d), 0);
	ft_deque_free(d);
}

/* ==================== ft_deque_back tests ==================== */

TEST(test_deque_back_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	int *ptr = ft_deque_back(d);

	ASSERT_NOT_NULL(ptr);
	ASSERT_EQ(*ptr, 42);
	ft_deque_free(d);
}

TEST(test_deque_back_null_deque)
{
	void *ptr = ft_deque_back(NULL);
	ASSERT_NULL(ptr);
}

TEST(test_deque_back_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	void *ptr = ft_deque_back(d);
	ASSERT_NULL(ptr);
	ft_deque_free(d);
}

TEST(test_deque_back_multiple)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ASSERT_EQ(*(int *)ft_deque_back(d), 3);
	ft_deque_free(d);
}

/* ==================== ft_deque_get tests ==================== */

TEST(test_deque_get_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	int *ptr = ft_deque_get(d, 0);

	ASSERT_NOT_NULL(ptr);
	ASSERT_EQ(*ptr, 42);
	ft_deque_free(d);
}

TEST(test_deque_get_null_deque)
{
	void *ptr = ft_deque_get(NULL, 0);
	ASSERT_NULL(ptr);
}

TEST(test_deque_get_out_of_bounds)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);

	ASSERT_NULL(ft_deque_get(d, 1));
	ASSERT_NULL(ft_deque_get(d, 100));
	ASSERT_NULL(ft_deque_get(d, (size_t)-1));
	ft_deque_free(d);
}

TEST(test_deque_get_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ASSERT_NULL(ft_deque_get(d, 0));
	ft_deque_free(d);
}

TEST(test_deque_get_wrapped)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	ft_deque_pop_front(d, NULL);
	val = 3; ft_deque_push_back(d, &val);
	val = 4; ft_deque_push_back(d, &val);
	val = 0; ft_deque_push_front(d, &val);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 0);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 3), 4);
	ft_deque_free(d);
}

/* ==================== ft_deque_swap tests ==================== */

TEST(test_deque_swap_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);

	ft_deque_swap(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 1);
	ft_deque_free(d);
}

TEST(test_deque_swap_null_deque)
{
	ft_deque_swap(NULL);
}

TEST(test_deque_swap_single_element)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	ft_deque_swap(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 42);
	ft_deque_free(d);
}

TEST(test_deque_swap_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ft_deque_swap(d);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_swap_multiple)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_swap(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

TEST(test_deque_swap_large_elem)
{
	typedef struct { char data[128]; int id; } big_struct;
	t_deque *d = ft_deque_new(sizeof(big_struct), 4);
	big_struct s1 = {{0}, 1};
	big_struct s2 = {{0}, 2};

	strcpy(s1.data, "first");
	strcpy(s2.data, "second");

	ft_deque_push_back(d, &s1);
	ft_deque_push_back(d, &s2);

	ft_deque_swap(d);

	big_struct *ptr = ft_deque_get(d, 0);
	ASSERT_EQ(ptr->id, 2);
	ASSERT(strcmp(ptr->data, "second") == 0);

	ptr = ft_deque_get(d, 1);
	ASSERT_EQ(ptr->id, 1);
	ASSERT(strcmp(ptr->data, "first") == 0);
	ft_deque_free(d);
}

/* ==================== ft_deque_rotate tests ==================== */

TEST(test_deque_rotate_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_rotate(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 1);
	ft_deque_free(d);
}

TEST(test_deque_rotate_null_deque)
{
	ft_deque_rotate(NULL);
}

TEST(test_deque_rotate_single_element)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	ft_deque_rotate(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 42);
	ft_deque_free(d);
}

TEST(test_deque_rotate_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ft_deque_rotate(d);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_rotate_full_cycle)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;
	int i;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	i = 0;
	while (i < 3)
	{
		ft_deque_rotate(d);
		i++;
	}

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

/* ==================== ft_deque_rrotate tests ==================== */

TEST(test_deque_rrotate_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_rrotate(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 2);
	ft_deque_free(d);
}

TEST(test_deque_rrotate_null_deque)
{
	ft_deque_rrotate(NULL);
}

TEST(test_deque_rrotate_single_element)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	ft_deque_rrotate(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 42);
	ft_deque_free(d);
}

TEST(test_deque_rrotate_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ft_deque_rrotate(d);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_rrotate_full_cycle)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;
	int i;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	i = 0;
	while (i < 3)
	{
		ft_deque_rrotate(d);
		i++;
	}

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

TEST(test_deque_rotate_rrotate_inverse)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_rotate(d);
	ft_deque_rrotate(d);

	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 3);
	ft_deque_free(d);
}

/* ==================== ft_deque_is_empty tests ==================== */

TEST(test_deque_is_empty_true)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ASSERT_EQ(ft_deque_is_empty(d), 1);
	ft_deque_free(d);
}

TEST(test_deque_is_empty_false)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	ft_deque_push_back(d, &val);
	ASSERT_EQ(ft_deque_is_empty(d), 0);
	ft_deque_free(d);
}

TEST(test_deque_is_empty_null)
{
	ASSERT_EQ(ft_deque_is_empty(NULL), 1);
}

TEST(test_deque_is_empty_after_clear)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	ft_deque_push_back(d, &val);
	ft_deque_clear(d);
	ASSERT_EQ(ft_deque_is_empty(d), 1);
	ft_deque_free(d);
}

/* ==================== ft_deque_is_full tests ==================== */

TEST(test_deque_is_full_true)
{
	t_deque *d = ft_deque_new(sizeof(int), 2);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);

	ASSERT_EQ(ft_deque_is_full(d), 1);
	ft_deque_free(d);
}

TEST(test_deque_is_full_false)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;
	ft_deque_push_back(d, &val);
	ASSERT_EQ(ft_deque_is_full(d), 0);
	ft_deque_free(d);
}

TEST(test_deque_is_full_null)
{
	ASSERT_EQ(ft_deque_is_full(NULL), 0);
}

TEST(test_deque_is_full_empty)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ASSERT_EQ(ft_deque_is_full(d), 0);
	ft_deque_free(d);
}

/* ==================== ft_deque_clear tests ==================== */

TEST(test_deque_clear_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val = 42;

	ft_deque_push_back(d, &val);
	ft_deque_push_back(d, &val);
	ft_deque_clear(d);

	ASSERT_EQ(d->len, 0);
	ASSERT_EQ(d->head, 0);
	ASSERT_EQ(d->tail, 0);
	ASSERT_EQ(d->cap, 4);
	ft_deque_free(d);
}

TEST(test_deque_clear_null_deque)
{
	ft_deque_clear(NULL);
}

TEST(test_deque_clear_empty_deque)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ft_deque_clear(d);
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_clear_reuse)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	ft_deque_clear(d);

	val = 100; ft_deque_push_back(d, &val);
	ASSERT_EQ(d->len, 1);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 100);
	ft_deque_free(d);
}

/* ==================== ft_deque_free tests ==================== */

TEST(test_deque_free_null)
{
	ft_deque_free(NULL);
}

TEST(test_deque_free_basic)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	ft_deque_free(d);
}

/* ==================== push_swap simulation tests ==================== */

TEST(test_pushswap_pb_operation)
{
	t_deque *a = ft_deque_new(sizeof(int), 8);
	t_deque *b = ft_deque_new(sizeof(int), 8);
	int val, tmp;

	val = 1; ft_deque_push_back(a, &val);
	val = 2; ft_deque_push_back(a, &val);
	val = 3; ft_deque_push_back(a, &val);

	ft_deque_pop_front(a, &tmp);
	ft_deque_push_front(b, &tmp);

	ASSERT_EQ(a->len, 2);
	ASSERT_EQ(b->len, 1);
	ASSERT_EQ(*(int *)ft_deque_front(a), 2);
	ASSERT_EQ(*(int *)ft_deque_front(b), 1);

	ft_deque_free(a);
	ft_deque_free(b);
}

TEST(test_pushswap_sa_operation)
{
	t_deque *a = ft_deque_new(sizeof(int), 8);
	int val;

	val = 2; ft_deque_push_back(a, &val);
	val = 1; ft_deque_push_back(a, &val);
	val = 3; ft_deque_push_back(a, &val);

	ft_deque_swap(a);

	ASSERT_EQ(*(int *)ft_deque_get(a, 0), 1);
	ASSERT_EQ(*(int *)ft_deque_get(a, 1), 2);
	ASSERT_EQ(*(int *)ft_deque_get(a, 2), 3);

	ft_deque_free(a);
}

TEST(test_pushswap_ra_operation)
{
	t_deque *a = ft_deque_new(sizeof(int), 8);
	int val;

	val = 1; ft_deque_push_back(a, &val);
	val = 2; ft_deque_push_back(a, &val);
	val = 3; ft_deque_push_back(a, &val);

	ft_deque_rotate(a);

	ASSERT_EQ(*(int *)ft_deque_get(a, 0), 2);
	ASSERT_EQ(*(int *)ft_deque_get(a, 1), 3);
	ASSERT_EQ(*(int *)ft_deque_get(a, 2), 1);

	ft_deque_free(a);
}

TEST(test_pushswap_rra_operation)
{
	t_deque *a = ft_deque_new(sizeof(int), 8);
	int val;

	val = 1; ft_deque_push_back(a, &val);
	val = 2; ft_deque_push_back(a, &val);
	val = 3; ft_deque_push_back(a, &val);

	ft_deque_rrotate(a);

	ASSERT_EQ(*(int *)ft_deque_get(a, 0), 3);
	ASSERT_EQ(*(int *)ft_deque_get(a, 1), 1);
	ASSERT_EQ(*(int *)ft_deque_get(a, 2), 2);

	ft_deque_free(a);
}

/* ==================== Complex data type tests ==================== */

typedef struct s_point
{
	int x;
	int y;
	char name[32];
} t_point;

TEST(test_deque_struct_type)
{
	t_deque *d = ft_deque_new(sizeof(t_point), 4);
	t_point p1 = {10, 20, "origin"};
	t_point p2 = {30, 40, "target"};
	t_point *ptr;

	ft_deque_push_back(d, &p1);
	ft_deque_push_back(d, &p2);

	ptr = ft_deque_get(d, 0);
	ASSERT_EQ(ptr->x, 10);
	ASSERT_EQ(ptr->y, 20);
	ASSERT(strcmp(ptr->name, "origin") == 0);

	ptr = ft_deque_get(d, 1);
	ASSERT_EQ(ptr->x, 30);
	ASSERT_EQ(ptr->y, 40);
	ft_deque_free(d);
}

TEST(test_deque_char_type)
{
	t_deque *d = ft_deque_new(sizeof(char), 4);
	char c;
	char *ptr;

	c = 'H'; ft_deque_push_back(d, &c);
	c = 'i'; ft_deque_push_back(d, &c);
	c = '!'; ft_deque_push_back(d, &c);

	ptr = ft_deque_get(d, 0);
	ASSERT_EQ(*ptr, 'H');
	ptr = ft_deque_get(d, 1);
	ASSERT_EQ(*ptr, 'i');
	ptr = ft_deque_get(d, 2);
	ASSERT_EQ(*ptr, '!');
	ft_deque_free(d);
}

TEST(test_deque_pointer_type)
{
	t_deque *d = ft_deque_new(sizeof(char *), 4);
	char *s1 = "hello";
	char *s2 = "world";
	char **ptr;

	ft_deque_push_back(d, &s1);
	ft_deque_push_back(d, &s2);

	ptr = ft_deque_get(d, 0);
	ASSERT(strcmp(*ptr, "hello") == 0);
	ptr = ft_deque_get(d, 1);
	ASSERT(strcmp(*ptr, "world") == 0);
	ft_deque_free(d);
}

/* ==================== Stress tests ==================== */

TEST(test_deque_stress_push_pop)
{
	t_deque *d = ft_deque_new(sizeof(int), 1);
	int i;
	int val;
	int out;

	i = 0;
	while (i < 10000)
	{
		val = i;
		ft_deque_push_back(d, &val);
		i++;
	}
	ASSERT_EQ(d->len, 10000);

	i = 0;
	while (i < 10000)
	{
		ft_deque_pop_front(d, &out);
		ASSERT_EQ(out, i);
		i++;
	}
	ASSERT_EQ(d->len, 0);
	ft_deque_free(d);
}

TEST(test_deque_alternating_push_pop)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val, out;
	int i;

	i = 0;
	while (i < 100)
	{
		val = i;
		ft_deque_push_back(d, &val);
		val = i + 1;
		ft_deque_push_front(d, &val);
		ft_deque_pop_back(d, &out);
		ASSERT_EQ(out, i);
		i++;
	}
	ASSERT_EQ(d->len, 100);
	ft_deque_free(d);
}

TEST(test_deque_stress_rotate)
{
	t_deque *d = ft_deque_new(sizeof(int), 100);
	int i;
	int val;

	i = 0;
	while (i < 100)
	{
		val = i;
		ft_deque_push_back(d, &val);
		i++;
	}

	i = 0;
	while (i < 1000)
	{
		ft_deque_rotate(d);
		i++;
	}

	ASSERT_EQ(d->len, 100);
	ft_deque_free(d);
}

TEST(test_deque_grow_preserves_wrapped_data)
{
	t_deque *d = ft_deque_new(sizeof(int), 4);
	int val;

	val = 1; ft_deque_push_back(d, &val);
	val = 2; ft_deque_push_back(d, &val);
	val = 3; ft_deque_push_back(d, &val);

	ft_deque_pop_front(d, NULL);
	ft_deque_pop_front(d, NULL);

	val = 4; ft_deque_push_back(d, &val);
	val = 5; ft_deque_push_back(d, &val);
	val = 6; ft_deque_push_back(d, &val);

	ASSERT_EQ(d->len, 4);
	ASSERT_EQ(*(int *)ft_deque_get(d, 0), 3);
	ASSERT_EQ(*(int *)ft_deque_get(d, 1), 4);
	ASSERT_EQ(*(int *)ft_deque_get(d, 2), 5);
	ASSERT_EQ(*(int *)ft_deque_get(d, 3), 6);
	ft_deque_free(d);
}

/* ==================== Main ==================== */

void run_all_tests(void)
{
	printf("\n\033[1m=== ft_deque_new tests ===\033[0m\n");
	RUN_TEST(test_deque_new_basic);
	RUN_TEST(test_deque_new_zero_elem_size);
	RUN_TEST(test_deque_new_zero_capacity_defaults_to_8);
	RUN_TEST(test_deque_new_large_elem_size);
	RUN_TEST(test_deque_new_capacity_one);

	printf("\n\033[1m=== ft_deque_push_back tests ===\033[0m\n");
	RUN_TEST(test_deque_push_back_basic);
	RUN_TEST(test_deque_push_back_null_deque);
	RUN_TEST(test_deque_push_back_null_elem);
	RUN_TEST(test_deque_push_back_triggers_growth);
	RUN_TEST(test_deque_push_back_many_elements);

	printf("\n\033[1m=== ft_deque_push_front tests ===\033[0m\n");
	RUN_TEST(test_deque_push_front_basic);
	RUN_TEST(test_deque_push_front_null_deque);
	RUN_TEST(test_deque_push_front_null_elem);
	RUN_TEST(test_deque_push_front_multiple);
	RUN_TEST(test_deque_push_front_triggers_growth);

	printf("\n\033[1m=== Mixed push tests ===\033[0m\n");
	RUN_TEST(test_deque_mixed_push);
	RUN_TEST(test_deque_wraparound);

	printf("\n\033[1m=== ft_deque_pop_front tests ===\033[0m\n");
	RUN_TEST(test_deque_pop_front_basic);
	RUN_TEST(test_deque_pop_front_null_deque);
	RUN_TEST(test_deque_pop_front_empty_deque);
	RUN_TEST(test_deque_pop_front_null_out);
	RUN_TEST(test_deque_pop_front_multiple);

	printf("\n\033[1m=== ft_deque_pop_back tests ===\033[0m\n");
	RUN_TEST(test_deque_pop_back_basic);
	RUN_TEST(test_deque_pop_back_null_deque);
	RUN_TEST(test_deque_pop_back_empty_deque);
	RUN_TEST(test_deque_pop_back_null_out);
	RUN_TEST(test_deque_pop_back_multiple);

	printf("\n\033[1m=== ft_deque_front tests ===\033[0m\n");
	RUN_TEST(test_deque_front_basic);
	RUN_TEST(test_deque_front_null_deque);
	RUN_TEST(test_deque_front_empty_deque);
	RUN_TEST(test_deque_front_after_push_front);

	printf("\n\033[1m=== ft_deque_back tests ===\033[0m\n");
	RUN_TEST(test_deque_back_basic);
	RUN_TEST(test_deque_back_null_deque);
	RUN_TEST(test_deque_back_empty_deque);
	RUN_TEST(test_deque_back_multiple);

	printf("\n\033[1m=== ft_deque_get tests ===\033[0m\n");
	RUN_TEST(test_deque_get_basic);
	RUN_TEST(test_deque_get_null_deque);
	RUN_TEST(test_deque_get_out_of_bounds);
	RUN_TEST(test_deque_get_empty_deque);
	RUN_TEST(test_deque_get_wrapped);

	printf("\n\033[1m=== ft_deque_swap tests ===\033[0m\n");
	RUN_TEST(test_deque_swap_basic);
	RUN_TEST(test_deque_swap_null_deque);
	RUN_TEST(test_deque_swap_single_element);
	RUN_TEST(test_deque_swap_empty_deque);
	RUN_TEST(test_deque_swap_multiple);
	RUN_TEST(test_deque_swap_large_elem);

	printf("\n\033[1m=== ft_deque_rotate tests ===\033[0m\n");
	RUN_TEST(test_deque_rotate_basic);
	RUN_TEST(test_deque_rotate_null_deque);
	RUN_TEST(test_deque_rotate_single_element);
	RUN_TEST(test_deque_rotate_empty_deque);
	RUN_TEST(test_deque_rotate_full_cycle);

	printf("\n\033[1m=== ft_deque_rrotate tests ===\033[0m\n");
	RUN_TEST(test_deque_rrotate_basic);
	RUN_TEST(test_deque_rrotate_null_deque);
	RUN_TEST(test_deque_rrotate_single_element);
	RUN_TEST(test_deque_rrotate_empty_deque);
	RUN_TEST(test_deque_rrotate_full_cycle);
	RUN_TEST(test_deque_rotate_rrotate_inverse);

	printf("\n\033[1m=== ft_deque_is_empty tests ===\033[0m\n");
	RUN_TEST(test_deque_is_empty_true);
	RUN_TEST(test_deque_is_empty_false);
	RUN_TEST(test_deque_is_empty_null);
	RUN_TEST(test_deque_is_empty_after_clear);

	printf("\n\033[1m=== ft_deque_is_full tests ===\033[0m\n");
	RUN_TEST(test_deque_is_full_true);
	RUN_TEST(test_deque_is_full_false);
	RUN_TEST(test_deque_is_full_null);
	RUN_TEST(test_deque_is_full_empty);

	printf("\n\033[1m=== ft_deque_clear tests ===\033[0m\n");
	RUN_TEST(test_deque_clear_basic);
	RUN_TEST(test_deque_clear_null_deque);
	RUN_TEST(test_deque_clear_empty_deque);
	RUN_TEST(test_deque_clear_reuse);

	printf("\n\033[1m=== ft_deque_free tests ===\033[0m\n");
	RUN_TEST(test_deque_free_null);
	RUN_TEST(test_deque_free_basic);

	printf("\n\033[1m=== push_swap simulation tests ===\033[0m\n");
	RUN_TEST(test_pushswap_pb_operation);
	RUN_TEST(test_pushswap_sa_operation);
	RUN_TEST(test_pushswap_ra_operation);
	RUN_TEST(test_pushswap_rra_operation);

	printf("\n\033[1m=== Complex data type tests ===\033[0m\n");
	RUN_TEST(test_deque_struct_type);
	RUN_TEST(test_deque_char_type);
	RUN_TEST(test_deque_pointer_type);

	printf("\n\033[1m=== Stress tests ===\033[0m\n");
	RUN_TEST(test_deque_stress_push_pop);
	RUN_TEST(test_deque_alternating_push_pop);
	RUN_TEST(test_deque_stress_rotate);
	RUN_TEST(test_deque_grow_preserves_wrapped_data);
}

int main(void)
{
	printf("\n\033[1;36m╔══════════════════════════════════════╗\033[0m\n");
	printf("\033[1;36m║      ft_deque Unit Test Suite        ║\033[0m\n");
	printf("\033[1;36m╚══════════════════════════════════════╝\033[0m\n");

	run_all_tests();

	printf("\n\033[1m════════════════════════════════════════\033[0m\n");
	printf("\033[1mResults: \033[32m%d passed\033[0m, \033[31m%d failed\033[0m\n",
		   g_tests_passed, g_tests_failed);
	printf("\033[1m════════════════════════════════════════\033[0m\n\n");

	return (g_tests_failed > 0 ? 1 : 0);
}
