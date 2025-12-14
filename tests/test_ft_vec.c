/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   test_ft_vec.c                                      :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                                  +#+#+#+#+#+      +#+        */
/*   Created: 2025/12/14 15:30:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 15:30:00 by yiyuli         ###      ########.fr      */
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

/* ==================== ft_vec_new tests ==================== */

TEST(test_vec_new_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 10);
    ASSERT_NOT_NULL(vec);
    ASSERT_NOT_NULL(vec->data);
    ASSERT_EQ(vec->len, 0);
    ASSERT_EQ(vec->cap, 10);
    ASSERT_EQ(vec->elem_size, sizeof(int));
    ft_vec_free(vec);
}

TEST(test_vec_new_zero_elem_size)
{
    t_vec *vec = ft_vec_new(0, 10);
    ASSERT_NULL(vec);
}

TEST(test_vec_new_zero_capacity_defaults_to_8)
{
    t_vec *vec = ft_vec_new(sizeof(int), 0);
    ASSERT_NOT_NULL(vec);
    ASSERT_EQ(vec->cap, 8);
    ft_vec_free(vec);
}

TEST(test_vec_new_large_elem_size)
{
    typedef struct { char data[1024]; } big_struct;
    t_vec *vec = ft_vec_new(sizeof(big_struct), 4);
    ASSERT_NOT_NULL(vec);
    ASSERT_EQ(vec->elem_size, sizeof(big_struct));
    ft_vec_free(vec);
}

TEST(test_vec_new_capacity_one)
{
    t_vec *vec = ft_vec_new(sizeof(int), 1);
    ASSERT_NOT_NULL(vec);
    ASSERT_EQ(vec->cap, 1);
    ft_vec_free(vec);
}

/* ==================== ft_vec_push tests ==================== */

TEST(test_vec_push_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;
    int result = ft_vec_push(vec, &val);
    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->len, 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 42);
    ft_vec_free(vec);
}

TEST(test_vec_push_null_vec)
{
    int val = 42;
    int result = ft_vec_push(NULL, &val);
    ASSERT_EQ(result, 0);
}

TEST(test_vec_push_null_elem)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int result = ft_vec_push(vec, NULL);
    ASSERT_EQ(result, 0);
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

TEST(test_vec_push_triggers_growth)
{
    t_vec *vec = ft_vec_new(sizeof(int), 2);
    int val;

    val = 1; ft_vec_push(vec, &val);
    val = 2; ft_vec_push(vec, &val);
    ASSERT_EQ(vec->cap, 2);

    val = 3; ft_vec_push(vec, &val);
    ASSERT(vec->cap > 2);
    ASSERT_EQ(vec->len, 3);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 2), 3);
    ft_vec_free(vec);
}

TEST(test_vec_push_many_elements)
{
    t_vec *vec = ft_vec_new(sizeof(int), 1);
    int i;

    i = 0;
    while (i < 1000)
    {
        ASSERT_EQ(ft_vec_push(vec, &i), 1);
        i++;
    }
    ASSERT_EQ(vec->len, 1000);

    i = 0;
    while (i < 1000)
    {
        ASSERT_EQ(*(int *)ft_vec_get(vec, i), i);
        i++;
    }
    ft_vec_free(vec);
}

TEST(test_vec_push_preserves_order)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int vals[] = {10, 20, 30, 40, 50};
    int i;

    i = 0;
    while (i < 5)
    {
        ft_vec_push(vec, &vals[i]);
        i++;
    }

    i = 0;
    while (i < 5)
    {
        ASSERT_EQ(*(int *)ft_vec_get(vec, i), vals[i]);
        i++;
    }
    ft_vec_free(vec);
}

/* ==================== ft_vec_pop tests ==================== */

TEST(test_vec_pop_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;
    int out;

    ft_vec_push(vec, &val);
    int result = ft_vec_pop(vec, &out);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(out, 42);
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

TEST(test_vec_pop_null_vec)
{
    int out;
    int result = ft_vec_pop(NULL, &out);
    ASSERT_EQ(result, 0);
}

TEST(test_vec_pop_empty_vec)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int out;
    int result = ft_vec_pop(vec, &out);
    ASSERT_EQ(result, 0);
    ft_vec_free(vec);
}

TEST(test_vec_pop_null_out)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int result = ft_vec_pop(vec, NULL);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

TEST(test_vec_pop_multiple)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val, out;

    val = 1; ft_vec_push(vec, &val);
    val = 2; ft_vec_push(vec, &val);
    val = 3; ft_vec_push(vec, &val);

    ft_vec_pop(vec, &out);
    ASSERT_EQ(out, 3);
    ft_vec_pop(vec, &out);
    ASSERT_EQ(out, 2);
    ft_vec_pop(vec, &out);
    ASSERT_EQ(out, 1);
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

/* ==================== ft_vec_get tests ==================== */

TEST(test_vec_get_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int *ptr = ft_vec_get(vec, 0);

    ASSERT_NOT_NULL(ptr);
    ASSERT_EQ(*ptr, 42);
    ft_vec_free(vec);
}

TEST(test_vec_get_null_vec)
{
    void *ptr = ft_vec_get(NULL, 0);
    ASSERT_NULL(ptr);
}

TEST(test_vec_get_out_of_bounds)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);

    ASSERT_NULL(ft_vec_get(vec, 1));
    ASSERT_NULL(ft_vec_get(vec, 100));
    ASSERT_NULL(ft_vec_get(vec, (size_t)-1));
    ft_vec_free(vec);
}

TEST(test_vec_get_empty_vec)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    ASSERT_NULL(ft_vec_get(vec, 0));
    ft_vec_free(vec);
}

TEST(test_vec_get_modify_through_pointer)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int *ptr = ft_vec_get(vec, 0);
    *ptr = 100;

    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 100);
    ft_vec_free(vec);
}

/* ==================== ft_vec_set tests ==================== */

TEST(test_vec_set_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;
    int new_val = 100;

    ft_vec_push(vec, &val);
    int result = ft_vec_set(vec, 0, &new_val);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 100);
    ft_vec_free(vec);
}

TEST(test_vec_set_null_vec)
{
    int val = 42;
    int result = ft_vec_set(NULL, 0, &val);
    ASSERT_EQ(result, 0);
}

TEST(test_vec_set_null_elem)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int result = ft_vec_set(vec, 0, NULL);

    ASSERT_EQ(result, 0);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 42);
    ft_vec_free(vec);
}

TEST(test_vec_set_out_of_bounds)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int result = ft_vec_set(vec, 1, &val);

    ASSERT_EQ(result, 0);
    ft_vec_free(vec);
}

TEST(test_vec_set_empty_vec)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;
    int result = ft_vec_set(vec, 0, &val);
    ASSERT_EQ(result, 0);
    ft_vec_free(vec);
}

/* ==================== ft_vec_reserve tests ==================== */

TEST(test_vec_reserve_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int result = ft_vec_reserve(vec, 100);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->cap, 100);
    ft_vec_free(vec);
}

TEST(test_vec_reserve_null_vec)
{
    int result = ft_vec_reserve(NULL, 100);
    ASSERT_EQ(result, 0);
}

TEST(test_vec_reserve_smaller_cap_does_nothing)
{
    t_vec *vec = ft_vec_new(sizeof(int), 10);
    int result = ft_vec_reserve(vec, 5);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->cap, 10);
    ft_vec_free(vec);
}

TEST(test_vec_reserve_equal_cap_does_nothing)
{
    t_vec *vec = ft_vec_new(sizeof(int), 10);
    int result = ft_vec_reserve(vec, 10);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->cap, 10);
    ft_vec_free(vec);
}

TEST(test_vec_reserve_preserves_data)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val;
    int i;

    i = 0;
    while (i < 4)
    {
        val = i * 10;
        ft_vec_push(vec, &val);
        i++;
    }

    ft_vec_reserve(vec, 100);

    i = 0;
    while (i < 4)
    {
        ASSERT_EQ(*(int *)ft_vec_get(vec, i), i * 10);
        i++;
    }
    ft_vec_free(vec);
}

/* ==================== ft_vec_clear tests ==================== */

TEST(test_vec_clear_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    ft_vec_push(vec, &val);
    ft_vec_clear(vec);

    ASSERT_EQ(vec->len, 0);
    ASSERT_EQ(vec->cap, 4);
    ft_vec_free(vec);
}

TEST(test_vec_clear_null_vec)
{
    ft_vec_clear(NULL);
    /* Should not crash */
}

TEST(test_vec_clear_empty_vec)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    ft_vec_clear(vec);
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

TEST(test_vec_clear_reuse)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val;

    val = 1; ft_vec_push(vec, &val);
    val = 2; ft_vec_push(vec, &val);
    ft_vec_clear(vec);

    val = 100; ft_vec_push(vec, &val);
    ASSERT_EQ(vec->len, 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 100);
    ft_vec_free(vec);
}

/* ==================== ft_vec_free tests ==================== */

TEST(test_vec_free_null)
{
    ft_vec_free(NULL);
    /* Should not crash */
}

TEST(test_vec_free_basic)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    ft_vec_free(vec);
    /* Should not leak - verified by leaks tool */
}

/* ==================== ft_vec_insert tests ==================== */

TEST(test_vec_insert_at_beginning)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val;

    val = 2; ft_vec_push(vec, &val);
    val = 3; ft_vec_push(vec, &val);
    val = 1; ft_vec_insert(vec, 0, &val);

    ASSERT_EQ(vec->len, 3);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 1), 2);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 2), 3);
    ft_vec_free(vec);
}

TEST(test_vec_insert_at_middle)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val;

    val = 1; ft_vec_push(vec, &val);
    val = 3; ft_vec_push(vec, &val);
    val = 2; ft_vec_insert(vec, 1, &val);

    ASSERT_EQ(vec->len, 3);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 1), 2);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 2), 3);
    ft_vec_free(vec);
}

TEST(test_vec_insert_at_end)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val;

    val = 1; ft_vec_push(vec, &val);
    val = 2; ft_vec_push(vec, &val);
    val = 3; ft_vec_insert(vec, 2, &val);

    ASSERT_EQ(vec->len, 3);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 2), 3);
    ft_vec_free(vec);
}

TEST(test_vec_insert_null_vec)
{
    int val = 42;
    int result = ft_vec_insert(NULL, 0, &val);
    ASSERT_EQ(result, 0);
}

TEST(test_vec_insert_null_elem)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int result = ft_vec_insert(vec, 0, NULL);
    ASSERT_EQ(result, 0);
    ft_vec_free(vec);
}

TEST(test_vec_insert_out_of_bounds)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;

    ft_vec_push(vec, &val);
    int result = ft_vec_insert(vec, 5, &val);

    ASSERT_EQ(result, 0);
    ASSERT_EQ(vec->len, 1);
    ft_vec_free(vec);
}

TEST(test_vec_insert_empty_vec)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val = 42;
    int result = ft_vec_insert(vec, 0, &val);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(vec->len, 1);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 42);
    ft_vec_free(vec);
}

TEST(test_vec_insert_triggers_growth)
{
    t_vec *vec = ft_vec_new(sizeof(int), 2);
    int val;

    val = 1; ft_vec_push(vec, &val);
    val = 2; ft_vec_push(vec, &val);
    val = 0; ft_vec_insert(vec, 0, &val);

    ASSERT(vec->cap > 2);
    ASSERT_EQ(vec->len, 3);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 0);
    ft_vec_free(vec);
}

TEST(test_vec_insert_many)
{
    t_vec *vec = ft_vec_new(sizeof(int), 1);
    int i;
    int val;

    i = 0;
    while (i < 100)
    {
        val = i;
        ft_vec_insert(vec, 0, &val);
        i++;
    }

    ASSERT_EQ(vec->len, 100);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 0), 99);
    ASSERT_EQ(*(int *)ft_vec_get(vec, 99), 0);
    ft_vec_free(vec);
}

/* ==================== Complex data type tests ==================== */

typedef struct s_point
{
    int x;
    int y;
    char name[32];
} t_point;

TEST(test_vec_struct_type)
{
    t_vec *vec = ft_vec_new(sizeof(t_point), 4);
    t_point p1 = {10, 20, "origin"};
    t_point p2 = {30, 40, "target"};
    t_point *ptr;

    ft_vec_push(vec, &p1);
    ft_vec_push(vec, &p2);

    ptr = ft_vec_get(vec, 0);
    ASSERT_EQ(ptr->x, 10);
    ASSERT_EQ(ptr->y, 20);
    ASSERT(strcmp(ptr->name, "origin") == 0);

    ptr = ft_vec_get(vec, 1);
    ASSERT_EQ(ptr->x, 30);
    ASSERT_EQ(ptr->y, 40);
    ft_vec_free(vec);
}

TEST(test_vec_char_type)
{
    t_vec *vec = ft_vec_new(sizeof(char), 4);
    char c;
    char *ptr;

    c = 'H'; ft_vec_push(vec, &c);
    c = 'i'; ft_vec_push(vec, &c);
    c = '!'; ft_vec_push(vec, &c);

    ptr = ft_vec_get(vec, 0);
    ASSERT_EQ(*ptr, 'H');
    ptr = ft_vec_get(vec, 1);
    ASSERT_EQ(*ptr, 'i');
    ptr = ft_vec_get(vec, 2);
    ASSERT_EQ(*ptr, '!');
    ft_vec_free(vec);
}

TEST(test_vec_pointer_type)
{
    t_vec *vec = ft_vec_new(sizeof(char *), 4);
    char *s1 = "hello";
    char *s2 = "world";
    char **ptr;

    ft_vec_push(vec, &s1);
    ft_vec_push(vec, &s2);

    ptr = ft_vec_get(vec, 0);
    ASSERT(strcmp(*ptr, "hello") == 0);
    ptr = ft_vec_get(vec, 1);
    ASSERT(strcmp(*ptr, "world") == 0);
    ft_vec_free(vec);
}

/* ==================== Stress tests ==================== */

TEST(test_vec_stress_push_pop)
{
    t_vec *vec = ft_vec_new(sizeof(int), 1);
    int i;
    int val;
    int out;

    i = 0;
    while (i < 10000)
    {
        val = i;
        ft_vec_push(vec, &val);
        i++;
    }
    ASSERT_EQ(vec->len, 10000);

    i = 9999;
    while (i >= 0)
    {
        ft_vec_pop(vec, &out);
        ASSERT_EQ(out, i);
        i--;
    }
    ASSERT_EQ(vec->len, 0);
    ft_vec_free(vec);
}

TEST(test_vec_alternating_push_pop)
{
    t_vec *vec = ft_vec_new(sizeof(int), 4);
    int val, out;
    int i;

    i = 0;
    while (i < 100)
    {
        val = i;
        ft_vec_push(vec, &val);
        val = i + 1;
        ft_vec_push(vec, &val);
        ft_vec_pop(vec, &out);
        ASSERT_EQ(out, i + 1);
        i++;
    }
    ASSERT_EQ(vec->len, 100);
    ft_vec_free(vec);
}

/* ==================== Main ==================== */

void run_all_tests(void)
{
    printf("\n\033[1m=== ft_vec_new tests ===\033[0m\n");
    RUN_TEST(test_vec_new_basic);
    RUN_TEST(test_vec_new_zero_elem_size);
    RUN_TEST(test_vec_new_zero_capacity_defaults_to_8);
    RUN_TEST(test_vec_new_large_elem_size);
    RUN_TEST(test_vec_new_capacity_one);

    printf("\n\033[1m=== ft_vec_push tests ===\033[0m\n");
    RUN_TEST(test_vec_push_basic);
    RUN_TEST(test_vec_push_null_vec);
    RUN_TEST(test_vec_push_null_elem);
    RUN_TEST(test_vec_push_triggers_growth);
    RUN_TEST(test_vec_push_many_elements);
    RUN_TEST(test_vec_push_preserves_order);

    printf("\n\033[1m=== ft_vec_pop tests ===\033[0m\n");
    RUN_TEST(test_vec_pop_basic);
    RUN_TEST(test_vec_pop_null_vec);
    RUN_TEST(test_vec_pop_empty_vec);
    RUN_TEST(test_vec_pop_null_out);
    RUN_TEST(test_vec_pop_multiple);

    printf("\n\033[1m=== ft_vec_get tests ===\033[0m\n");
    RUN_TEST(test_vec_get_basic);
    RUN_TEST(test_vec_get_null_vec);
    RUN_TEST(test_vec_get_out_of_bounds);
    RUN_TEST(test_vec_get_empty_vec);
    RUN_TEST(test_vec_get_modify_through_pointer);

    printf("\n\033[1m=== ft_vec_set tests ===\033[0m\n");
    RUN_TEST(test_vec_set_basic);
    RUN_TEST(test_vec_set_null_vec);
    RUN_TEST(test_vec_set_null_elem);
    RUN_TEST(test_vec_set_out_of_bounds);
    RUN_TEST(test_vec_set_empty_vec);

    printf("\n\033[1m=== ft_vec_reserve tests ===\033[0m\n");
    RUN_TEST(test_vec_reserve_basic);
    RUN_TEST(test_vec_reserve_null_vec);
    RUN_TEST(test_vec_reserve_smaller_cap_does_nothing);
    RUN_TEST(test_vec_reserve_equal_cap_does_nothing);
    RUN_TEST(test_vec_reserve_preserves_data);

    printf("\n\033[1m=== ft_vec_clear tests ===\033[0m\n");
    RUN_TEST(test_vec_clear_basic);
    RUN_TEST(test_vec_clear_null_vec);
    RUN_TEST(test_vec_clear_empty_vec);
    RUN_TEST(test_vec_clear_reuse);

    printf("\n\033[1m=== ft_vec_free tests ===\033[0m\n");
    RUN_TEST(test_vec_free_null);
    RUN_TEST(test_vec_free_basic);

    printf("\n\033[1m=== ft_vec_insert tests ===\033[0m\n");
    RUN_TEST(test_vec_insert_at_beginning);
    RUN_TEST(test_vec_insert_at_middle);
    RUN_TEST(test_vec_insert_at_end);
    RUN_TEST(test_vec_insert_null_vec);
    RUN_TEST(test_vec_insert_null_elem);
    RUN_TEST(test_vec_insert_out_of_bounds);
    RUN_TEST(test_vec_insert_empty_vec);
    RUN_TEST(test_vec_insert_triggers_growth);
    RUN_TEST(test_vec_insert_many);

    printf("\n\033[1m=== Complex data type tests ===\033[0m\n");
    RUN_TEST(test_vec_struct_type);
    RUN_TEST(test_vec_char_type);
    RUN_TEST(test_vec_pointer_type);

    printf("\n\033[1m=== Stress tests ===\033[0m\n");
    RUN_TEST(test_vec_stress_push_pop);
    RUN_TEST(test_vec_alternating_push_pop);
}

int main(void)
{
    printf("\n\033[1;36m╔══════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║       ft_vec Unit Test Suite         ║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════╝\033[0m\n");

    run_all_tests();

    printf("\n\033[1m════════════════════════════════════════\033[0m\n");
    printf("\033[1mResults: \033[32m%d passed\033[0m, \033[31m%d failed\033[0m\n",
           g_tests_passed, g_tests_failed);
    printf("\033[1m════════════════════════════════════════\033[0m\n\n");

    return (g_tests_failed > 0 ? 1 : 0);
}
