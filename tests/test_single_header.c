/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyuli <yy@eyuan.me>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:00:00 by claude            #+#    #+#             */
/*   Updated: 2026/01/09 00:00:00 by claude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_IMPLEMENTATION
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

static int	g_tests_passed = 0;
static int	g_tests_failed = 0;

static void	test(int condition, const char *name)
{
	if (condition)
	{
		g_tests_passed++;
		printf("  [OK] %s\n", name);
	}
	else
	{
		g_tests_failed++;
		printf("  [FAIL] %s\n", name);
	}
}

static void	test_ft_is(void)
{
	printf("\n=== ft_is (character classification) ===\n");
	test(ft_isalpha('a') != 0, "ft_isalpha('a')");
	test(ft_isalpha('Z') != 0, "ft_isalpha('Z')");
	test(ft_isalpha('5') == 0, "ft_isalpha('5') == 0");
	test(ft_isdigit('5') != 0, "ft_isdigit('5')");
	test(ft_isdigit('a') == 0, "ft_isdigit('a') == 0");
	test(ft_isalnum('a') != 0, "ft_isalnum('a')");
	test(ft_isalnum('5') != 0, "ft_isalnum('5')");
	test(ft_isascii(65) != 0, "ft_isascii(65)");
	test(ft_isprint(' ') != 0, "ft_isprint(' ')");
}

static void	test_ft_str(void)
{
	char	buf[100];

	printf("\n=== ft_str (string functions) ===\n");
	test(ft_strlen("hello") == 5, "ft_strlen(\"hello\") == 5");
	test(ft_strlen("") == 0, "ft_strlen(\"\") == 0");
	test(ft_strchr("hello", 'l') != NULL, "ft_strchr finds 'l'");
	test(ft_strrchr("hello", 'l') != NULL, "ft_strrchr finds last 'l'");
	test(ft_strncmp("abc", "abc", 3) == 0, "ft_strncmp equal");
	test(ft_strncmp("abc", "abd", 3) < 0, "ft_strncmp less");
	ft_strlcpy(buf, "test", sizeof(buf));
	test(strcmp(buf, "test") == 0, "ft_strlcpy");
	test(ft_toupper('a') == 'A', "ft_toupper('a') == 'A'");
	test(ft_tolower('A') == 'a', "ft_tolower('A') == 'a'");
	test(ft_atoi("42") == 42, "ft_atoi(\"42\") == 42");
	test(ft_atoi("-123") == -123, "ft_atoi(\"-123\") == -123");
}

static void	test_ft_mem(void)
{
	char	buf[100];

	printf("\n=== ft_mem (memory functions) ===\n");
	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	test(strcmp(buf, "AAAAA") == 0, "ft_memset");
	ft_bzero(buf, 3);
	test(buf[0] == 0 && buf[1] == 0 && buf[2] == 0, "ft_bzero");
	ft_memcpy(buf, "hello", 6);
	test(strcmp(buf, "hello") == 0, "ft_memcpy");
	test(ft_memchr("hello", 'l', 5) != NULL, "ft_memchr finds 'l'");
	test(ft_memcmp("abc", "abc", 3) == 0, "ft_memcmp equal");
}

static void	test_ft_printf(void)
{
	int	ret;

	printf("\n=== ft_printf ===\n");
	printf("  Testing ft_printf output: ");
	ret = ft_printf("Number: %d", 42);
	printf("\n");
	test(ret == 10, "ft_printf returns correct length");
	printf("  Testing ft_printf string: ");
	ret = ft_printf("%s", "hello");
	printf("\n");
	test(ret == 5, "ft_printf string works");
}

static void	test_ft_lst(void)
{
	t_list	*lst;
	t_list	*node;

	printf("\n=== ft_lst (linked list) ===\n");
	lst = NULL;
	node = ft_lstnew("first");
	test(node != NULL, "ft_lstnew creates node");
	ft_lstadd_front(&lst, node);
	test(lst == node, "ft_lstadd_front");
	test(ft_lstsize(lst) == 1, "ft_lstsize == 1");
	node = ft_lstnew("second");
	ft_lstadd_back(&lst, node);
	test(ft_lstsize(lst) == 2, "ft_lstsize == 2 after add_back");
	test(ft_lstlast(lst) == node, "ft_lstlast");
	ft_lstclear(&lst, NULL);
	test(lst == NULL, "ft_lstclear");
}

static void	test_ft_vec(void)
{
	t_vec	*v;
	int		val;
	int		*ptr;

	printf("\n=== ft_vec (dynamic array) ===\n");
	v = ft_vec_new(sizeof(int), 4);
	test(v != NULL, "ft_vec_new");
	val = 42;
	test(ft_vec_push(v, &val) == 1, "ft_vec_push");
	val = 100;
	ft_vec_push(v, &val);
	test(v->len == 2, "vec->len == 2");
	ptr = ft_vec_get(v, 0);
	test(ptr != NULL && *ptr == 42, "ft_vec_get[0] == 42");
	ptr = ft_vec_get(v, 1);
	test(ptr != NULL && *ptr == 100, "ft_vec_get[1] == 100");
	ft_vec_free(v);
	printf("  [OK] ft_vec_free\n");
	g_tests_passed++;
}

static void	test_ft_deque(void)
{
	t_deque	*d;
	int		val;
	int		out;

	printf("\n=== ft_deque (double-ended queue) ===\n");
	d = ft_deque_new(sizeof(int), 4);
	test(d != NULL, "ft_deque_new");
	val = 1;
	ft_deque_push_back(d, &val);
	val = 2;
	ft_deque_push_back(d, &val);
	val = 0;
	ft_deque_push_front(d, &val);
	test(d->len == 3, "deque->len == 3");
	test(*(int *)ft_deque_front(d) == 0, "ft_deque_front == 0");
	test(*(int *)ft_deque_back(d) == 2, "ft_deque_back == 2");
	ft_deque_pop_front(d, &out);
	test(out == 0, "ft_deque_pop_front");
	ft_deque_free(d);
	printf("  [OK] ft_deque_free\n");
	g_tests_passed++;
}

static void	test_ft_vec_math(void)
{
	t_vec2	v2a;
	t_vec2	v2b;
	t_vec2	v2r;
	t_vec3	v3a;
	t_vec3	v3b;
	t_vec3	v3r;

	printf("\n=== ft_vec_math (2D/3D vectors) ===\n");
	v2a = ft_vec2_new(3.0, 4.0);
	test(fabs(ft_vec2_len(v2a) - 5.0) < 0.0001, "ft_vec2_len(3,4) == 5");
	v2b = ft_vec2_new(1.0, 1.0);
	v2r = ft_vec2_add(v2a, v2b);
	test(fabs(v2r.x - 4.0) < 0.0001 && fabs(v2r.y - 5.0) < 0.0001,
		"ft_vec2_add");
	test(fabs(ft_vec2_dot(v2a, v2b) - 7.0) < 0.0001, "ft_vec2_dot");
	v3a = ft_vec3_new(1.0, 0.0, 0.0);
	v3b = ft_vec3_new(0.0, 1.0, 0.0);
	v3r = ft_vec3_cross(v3a, v3b);
	test(fabs(v3r.z - 1.0) < 0.0001, "ft_vec3_cross i x j = k");
	test(fabs(ft_vec3_len(ft_vec3_new(1, 2, 2)) - 3.0) < 0.0001,
		"ft_vec3_len(1,2,2) == 3");
}

int	main(void)
{
	printf("===========================================\n");
	printf("   Single-Header Library Smoke Tests\n");
	printf("===========================================\n");
	test_ft_is();
	test_ft_str();
	test_ft_mem();
	test_ft_printf();
	test_ft_lst();
	test_ft_vec();
	test_ft_deque();
	test_ft_vec_math();
	printf("\n===========================================\n");
	printf("Results: %d passed, %d failed\n", g_tests_passed, g_tests_failed);
	printf("===========================================\n");
	return (g_tests_failed > 0);
}
