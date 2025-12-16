/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   test_ft_vec_math.c                                 :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <math.h>
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
#define ASSERT_NEAR(a, b, epsilon) ASSERT(fabs((a) - (b)) < (epsilon))
#define EPSILON 1e-6

/* ==================== ft_vec2_new tests ==================== */

TEST(test_vec2_new_basic)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	ASSERT_NEAR(v.x, 3.0, EPSILON);
	ASSERT_NEAR(v.y, 4.0, EPSILON);
}

TEST(test_vec2_new_zero)
{
	t_vec2 v = ft_vec2_new(0.0, 0.0);
	ASSERT_NEAR(v.x, 0.0, EPSILON);
	ASSERT_NEAR(v.y, 0.0, EPSILON);
}

TEST(test_vec2_new_negative)
{
	t_vec2 v = ft_vec2_new(-5.0, -10.0);
	ASSERT_NEAR(v.x, -5.0, EPSILON);
	ASSERT_NEAR(v.y, -10.0, EPSILON);
}

/* ==================== ft_vec2_add tests ==================== */

TEST(test_vec2_add_basic)
{
	t_vec2 a = ft_vec2_new(1.0, 2.0);
	t_vec2 b = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_add(a, b);
	ASSERT_NEAR(result.x, 4.0, EPSILON);
	ASSERT_NEAR(result.y, 6.0, EPSILON);
}

TEST(test_vec2_add_zero)
{
	t_vec2 a = ft_vec2_new(5.0, 10.0);
	t_vec2 b = ft_vec2_new(0.0, 0.0);
	t_vec2 result = ft_vec2_add(a, b);
	ASSERT_NEAR(result.x, 5.0, EPSILON);
	ASSERT_NEAR(result.y, 10.0, EPSILON);
}

TEST(test_vec2_add_negative)
{
	t_vec2 a = ft_vec2_new(10.0, 20.0);
	t_vec2 b = ft_vec2_new(-5.0, -15.0);
	t_vec2 result = ft_vec2_add(a, b);
	ASSERT_NEAR(result.x, 5.0, EPSILON);
	ASSERT_NEAR(result.y, 5.0, EPSILON);
}

/* ==================== ft_vec2_sub tests ==================== */

TEST(test_vec2_sub_basic)
{
	t_vec2 a = ft_vec2_new(5.0, 10.0);
	t_vec2 b = ft_vec2_new(2.0, 3.0);
	t_vec2 result = ft_vec2_sub(a, b);
	ASSERT_NEAR(result.x, 3.0, EPSILON);
	ASSERT_NEAR(result.y, 7.0, EPSILON);
}

TEST(test_vec2_sub_same_vector)
{
	t_vec2 a = ft_vec2_new(5.0, 10.0);
	t_vec2 result = ft_vec2_sub(a, a);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

/* ==================== ft_vec2_scale tests ==================== */

TEST(test_vec2_scale_basic)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_scale(v, 2.0);
	ASSERT_NEAR(result.x, 6.0, EPSILON);
	ASSERT_NEAR(result.y, 8.0, EPSILON);
}

TEST(test_vec2_scale_zero)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_scale(v, 0.0);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

TEST(test_vec2_scale_negative)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_scale(v, -1.0);
	ASSERT_NEAR(result.x, -3.0, EPSILON);
	ASSERT_NEAR(result.y, -4.0, EPSILON);
}

/* ==================== ft_vec2_dot tests ==================== */

TEST(test_vec2_dot_basic)
{
	t_vec2 a = ft_vec2_new(3.0, 4.0);
	t_vec2 b = ft_vec2_new(2.0, 1.0);
	double result = ft_vec2_dot(a, b);
	ASSERT_NEAR(result, 10.0, EPSILON);
}

TEST(test_vec2_dot_perpendicular)
{
	t_vec2 a = ft_vec2_new(1.0, 0.0);
	t_vec2 b = ft_vec2_new(0.0, 1.0);
	double result = ft_vec2_dot(a, b);
	ASSERT_NEAR(result, 0.0, EPSILON);
}

TEST(test_vec2_dot_self)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	double result = ft_vec2_dot(v, v);
	ASSERT_NEAR(result, 25.0, EPSILON);
}

/* ==================== ft_vec2_len tests ==================== */

TEST(test_vec2_len_basic)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	double len = ft_vec2_len(v);
	ASSERT_NEAR(len, 5.0, EPSILON);
}

TEST(test_vec2_len_zero)
{
	t_vec2 v = ft_vec2_new(0.0, 0.0);
	double len = ft_vec2_len(v);
	ASSERT_NEAR(len, 0.0, EPSILON);
}

TEST(test_vec2_len_unit)
{
	t_vec2 v = ft_vec2_new(1.0, 0.0);
	double len = ft_vec2_len(v);
	ASSERT_NEAR(len, 1.0, EPSILON);
}

/* ==================== ft_vec2_len_sq tests ==================== */

TEST(test_vec2_len_sq_basic)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	double len_sq = ft_vec2_len_sq(v);
	ASSERT_NEAR(len_sq, 25.0, EPSILON);
}

TEST(test_vec2_len_sq_zero)
{
	t_vec2 v = ft_vec2_new(0.0, 0.0);
	double len_sq = ft_vec2_len_sq(v);
	ASSERT_NEAR(len_sq, 0.0, EPSILON);
}

/* ==================== ft_vec2_norm tests ==================== */

TEST(test_vec2_norm_basic)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_norm(v);
	ASSERT_NEAR(result.x, 0.6, EPSILON);
	ASSERT_NEAR(result.y, 0.8, EPSILON);
	ASSERT_NEAR(ft_vec2_len(result), 1.0, EPSILON);
}

TEST(test_vec2_norm_zero)
{
	t_vec2 v = ft_vec2_new(0.0, 0.0);
	t_vec2 result = ft_vec2_norm(v);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

TEST(test_vec2_norm_already_unit)
{
	t_vec2 v = ft_vec2_new(1.0, 0.0);
	t_vec2 result = ft_vec2_norm(v);
	ASSERT_NEAR(result.x, 1.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

/* ==================== ft_vec2_dist tests ==================== */

TEST(test_vec2_dist_basic)
{
	t_vec2 a = ft_vec2_new(0.0, 0.0);
	t_vec2 b = ft_vec2_new(3.0, 4.0);
	double dist = ft_vec2_dist(a, b);
	ASSERT_NEAR(dist, 5.0, EPSILON);
}

TEST(test_vec2_dist_same_point)
{
	t_vec2 a = ft_vec2_new(5.0, 10.0);
	double dist = ft_vec2_dist(a, a);
	ASSERT_NEAR(dist, 0.0, EPSILON);
}

/* ==================== ft_vec2_lerp tests ==================== */

TEST(test_vec2_lerp_zero)
{
	t_vec2 a = ft_vec2_new(0.0, 0.0);
	t_vec2 b = ft_vec2_new(10.0, 20.0);
	t_vec2 result = ft_vec2_lerp(a, b, 0.0);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

TEST(test_vec2_lerp_one)
{
	t_vec2 a = ft_vec2_new(0.0, 0.0);
	t_vec2 b = ft_vec2_new(10.0, 20.0);
	t_vec2 result = ft_vec2_lerp(a, b, 1.0);
	ASSERT_NEAR(result.x, 10.0, EPSILON);
	ASSERT_NEAR(result.y, 20.0, EPSILON);
}

TEST(test_vec2_lerp_half)
{
	t_vec2 a = ft_vec2_new(0.0, 0.0);
	t_vec2 b = ft_vec2_new(10.0, 20.0);
	t_vec2 result = ft_vec2_lerp(a, b, 0.5);
	ASSERT_NEAR(result.x, 5.0, EPSILON);
	ASSERT_NEAR(result.y, 10.0, EPSILON);
}

/* ==================== ft_vec2_rotate tests ==================== */

TEST(test_vec2_rotate_90_degrees)
{
	t_vec2 v = ft_vec2_new(1.0, 0.0);
	t_vec2 result = ft_vec2_rotate(v, M_PI / 2.0);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 1.0, EPSILON);
}

TEST(test_vec2_rotate_180_degrees)
{
	t_vec2 v = ft_vec2_new(1.0, 0.0);
	t_vec2 result = ft_vec2_rotate(v, M_PI);
	ASSERT_NEAR(result.x, -1.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
}

TEST(test_vec2_rotate_zero)
{
	t_vec2 v = ft_vec2_new(3.0, 4.0);
	t_vec2 result = ft_vec2_rotate(v, 0.0);
	ASSERT_NEAR(result.x, 3.0, EPSILON);
	ASSERT_NEAR(result.y, 4.0, EPSILON);
}

/* ==================== ft_vec3_new tests ==================== */

TEST(test_vec3_new_basic)
{
	t_vec3 v = ft_vec3_new(1.0, 2.0, 3.0);
	ASSERT_NEAR(v.x, 1.0, EPSILON);
	ASSERT_NEAR(v.y, 2.0, EPSILON);
	ASSERT_NEAR(v.z, 3.0, EPSILON);
}

TEST(test_vec3_new_zero)
{
	t_vec3 v = ft_vec3_new(0.0, 0.0, 0.0);
	ASSERT_NEAR(v.x, 0.0, EPSILON);
	ASSERT_NEAR(v.y, 0.0, EPSILON);
	ASSERT_NEAR(v.z, 0.0, EPSILON);
}

/* ==================== ft_vec3_add tests ==================== */

TEST(test_vec3_add_basic)
{
	t_vec3 a = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 b = ft_vec3_new(4.0, 5.0, 6.0);
	t_vec3 result = ft_vec3_add(a, b);
	ASSERT_NEAR(result.x, 5.0, EPSILON);
	ASSERT_NEAR(result.y, 7.0, EPSILON);
	ASSERT_NEAR(result.z, 9.0, EPSILON);
}

/* ==================== ft_vec3_sub tests ==================== */

TEST(test_vec3_sub_basic)
{
	t_vec3 a = ft_vec3_new(5.0, 7.0, 9.0);
	t_vec3 b = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 result = ft_vec3_sub(a, b);
	ASSERT_NEAR(result.x, 4.0, EPSILON);
	ASSERT_NEAR(result.y, 5.0, EPSILON);
	ASSERT_NEAR(result.z, 6.0, EPSILON);
}

/* ==================== ft_vec3_scale tests ==================== */

TEST(test_vec3_scale_basic)
{
	t_vec3 v = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 result = ft_vec3_scale(v, 2.0);
	ASSERT_NEAR(result.x, 2.0, EPSILON);
	ASSERT_NEAR(result.y, 4.0, EPSILON);
	ASSERT_NEAR(result.z, 6.0, EPSILON);
}

/* ==================== ft_vec3_dot tests ==================== */

TEST(test_vec3_dot_basic)
{
	t_vec3 a = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 b = ft_vec3_new(4.0, 5.0, 6.0);
	double result = ft_vec3_dot(a, b);
	ASSERT_NEAR(result, 32.0, EPSILON);
}

TEST(test_vec3_dot_perpendicular)
{
	t_vec3 a = ft_vec3_new(1.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(0.0, 1.0, 0.0);
	double result = ft_vec3_dot(a, b);
	ASSERT_NEAR(result, 0.0, EPSILON);
}

/* ==================== ft_vec3_cross tests ==================== */

TEST(test_vec3_cross_basic)
{
	t_vec3 a = ft_vec3_new(1.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(0.0, 1.0, 0.0);
	t_vec3 result = ft_vec3_cross(a, b);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
	ASSERT_NEAR(result.z, 1.0, EPSILON);
}

TEST(test_vec3_cross_anticommutative)
{
	t_vec3 a = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 b = ft_vec3_new(4.0, 5.0, 6.0);
	t_vec3 ab = ft_vec3_cross(a, b);
	t_vec3 ba = ft_vec3_cross(b, a);
	ASSERT_NEAR(ab.x, -ba.x, EPSILON);
	ASSERT_NEAR(ab.y, -ba.y, EPSILON);
	ASSERT_NEAR(ab.z, -ba.z, EPSILON);
}

TEST(test_vec3_cross_parallel_returns_zero)
{
	t_vec3 a = ft_vec3_new(1.0, 2.0, 3.0);
	t_vec3 b = ft_vec3_new(2.0, 4.0, 6.0);
	t_vec3 result = ft_vec3_cross(a, b);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
	ASSERT_NEAR(result.z, 0.0, EPSILON);
}

/* ==================== ft_vec3_len tests ==================== */

TEST(test_vec3_len_basic)
{
	t_vec3 v = ft_vec3_new(2.0, 3.0, 6.0);
	double len = ft_vec3_len(v);
	ASSERT_NEAR(len, 7.0, EPSILON);
}

TEST(test_vec3_len_zero)
{
	t_vec3 v = ft_vec3_new(0.0, 0.0, 0.0);
	double len = ft_vec3_len(v);
	ASSERT_NEAR(len, 0.0, EPSILON);
}

/* ==================== ft_vec3_len_sq tests ==================== */

TEST(test_vec3_len_sq_basic)
{
	t_vec3 v = ft_vec3_new(2.0, 3.0, 6.0);
	double len_sq = ft_vec3_len_sq(v);
	ASSERT_NEAR(len_sq, 49.0, EPSILON);
}

/* ==================== ft_vec3_norm tests ==================== */

TEST(test_vec3_norm_basic)
{
	t_vec3 v = ft_vec3_new(3.0, 0.0, 4.0);
	t_vec3 result = ft_vec3_norm(v);
	ASSERT_NEAR(result.x, 0.6, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
	ASSERT_NEAR(result.z, 0.8, EPSILON);
	ASSERT_NEAR(ft_vec3_len(result), 1.0, EPSILON);
}

TEST(test_vec3_norm_zero)
{
	t_vec3 v = ft_vec3_new(0.0, 0.0, 0.0);
	t_vec3 result = ft_vec3_norm(v);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
	ASSERT_NEAR(result.z, 0.0, EPSILON);
}

/* ==================== ft_vec3_dist tests ==================== */

TEST(test_vec3_dist_basic)
{
	t_vec3 a = ft_vec3_new(0.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(2.0, 3.0, 6.0);
	double dist = ft_vec3_dist(a, b);
	ASSERT_NEAR(dist, 7.0, EPSILON);
}

/* ==================== ft_vec3_lerp tests ==================== */

TEST(test_vec3_lerp_zero)
{
	t_vec3 a = ft_vec3_new(0.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(10.0, 20.0, 30.0);
	t_vec3 result = ft_vec3_lerp(a, b, 0.0);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 0.0, EPSILON);
	ASSERT_NEAR(result.z, 0.0, EPSILON);
}

TEST(test_vec3_lerp_one)
{
	t_vec3 a = ft_vec3_new(0.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(10.0, 20.0, 30.0);
	t_vec3 result = ft_vec3_lerp(a, b, 1.0);
	ASSERT_NEAR(result.x, 10.0, EPSILON);
	ASSERT_NEAR(result.y, 20.0, EPSILON);
	ASSERT_NEAR(result.z, 30.0, EPSILON);
}

TEST(test_vec3_lerp_half)
{
	t_vec3 a = ft_vec3_new(0.0, 0.0, 0.0);
	t_vec3 b = ft_vec3_new(10.0, 20.0, 30.0);
	t_vec3 result = ft_vec3_lerp(a, b, 0.5);
	ASSERT_NEAR(result.x, 5.0, EPSILON);
	ASSERT_NEAR(result.y, 10.0, EPSILON);
	ASSERT_NEAR(result.z, 15.0, EPSILON);
}

/* ==================== ft_vec3_reflect tests ==================== */

TEST(test_vec3_reflect_basic)
{
	t_vec3 v = ft_vec3_new(1.0, -1.0, 0.0);
	t_vec3 normal = ft_vec3_new(0.0, 1.0, 0.0);
	t_vec3 result = ft_vec3_reflect(v, normal);
	ASSERT_NEAR(result.x, 1.0, EPSILON);
	ASSERT_NEAR(result.y, 1.0, EPSILON);
	ASSERT_NEAR(result.z, 0.0, EPSILON);
}

TEST(test_vec3_reflect_perpendicular)
{
	t_vec3 v = ft_vec3_new(0.0, -1.0, 0.0);
	t_vec3 normal = ft_vec3_new(0.0, 1.0, 0.0);
	t_vec3 result = ft_vec3_reflect(v, normal);
	ASSERT_NEAR(result.x, 0.0, EPSILON);
	ASSERT_NEAR(result.y, 1.0, EPSILON);
	ASSERT_NEAR(result.z, 0.0, EPSILON);
}

/* ==================== ft_vec3_negate tests ==================== */

TEST(test_vec3_negate_basic)
{
	t_vec3 v = ft_vec3_new(1.0, -2.0, 3.0);
	t_vec3 result = ft_vec3_negate(v);
	ASSERT_NEAR(result.x, -1.0, EPSILON);
	ASSERT_NEAR(result.y, 2.0, EPSILON);
	ASSERT_NEAR(result.z, -3.0, EPSILON);
}

/* ==================== Main ==================== */

void run_all_tests(void)
{
	printf("\n\033[1m=== ft_vec2_new tests ===\033[0m\n");
	RUN_TEST(test_vec2_new_basic);
	RUN_TEST(test_vec2_new_zero);
	RUN_TEST(test_vec2_new_negative);

	printf("\n\033[1m=== ft_vec2_add tests ===\033[0m\n");
	RUN_TEST(test_vec2_add_basic);
	RUN_TEST(test_vec2_add_zero);
	RUN_TEST(test_vec2_add_negative);

	printf("\n\033[1m=== ft_vec2_sub tests ===\033[0m\n");
	RUN_TEST(test_vec2_sub_basic);
	RUN_TEST(test_vec2_sub_same_vector);

	printf("\n\033[1m=== ft_vec2_scale tests ===\033[0m\n");
	RUN_TEST(test_vec2_scale_basic);
	RUN_TEST(test_vec2_scale_zero);
	RUN_TEST(test_vec2_scale_negative);

	printf("\n\033[1m=== ft_vec2_dot tests ===\033[0m\n");
	RUN_TEST(test_vec2_dot_basic);
	RUN_TEST(test_vec2_dot_perpendicular);
	RUN_TEST(test_vec2_dot_self);

	printf("\n\033[1m=== ft_vec2_len tests ===\033[0m\n");
	RUN_TEST(test_vec2_len_basic);
	RUN_TEST(test_vec2_len_zero);
	RUN_TEST(test_vec2_len_unit);

	printf("\n\033[1m=== ft_vec2_len_sq tests ===\033[0m\n");
	RUN_TEST(test_vec2_len_sq_basic);
	RUN_TEST(test_vec2_len_sq_zero);

	printf("\n\033[1m=== ft_vec2_norm tests ===\033[0m\n");
	RUN_TEST(test_vec2_norm_basic);
	RUN_TEST(test_vec2_norm_zero);
	RUN_TEST(test_vec2_norm_already_unit);

	printf("\n\033[1m=== ft_vec2_dist tests ===\033[0m\n");
	RUN_TEST(test_vec2_dist_basic);
	RUN_TEST(test_vec2_dist_same_point);

	printf("\n\033[1m=== ft_vec2_lerp tests ===\033[0m\n");
	RUN_TEST(test_vec2_lerp_zero);
	RUN_TEST(test_vec2_lerp_one);
	RUN_TEST(test_vec2_lerp_half);

	printf("\n\033[1m=== ft_vec2_rotate tests ===\033[0m\n");
	RUN_TEST(test_vec2_rotate_90_degrees);
	RUN_TEST(test_vec2_rotate_180_degrees);
	RUN_TEST(test_vec2_rotate_zero);

	printf("\n\033[1m=== ft_vec3_new tests ===\033[0m\n");
	RUN_TEST(test_vec3_new_basic);
	RUN_TEST(test_vec3_new_zero);

	printf("\n\033[1m=== ft_vec3_add tests ===\033[0m\n");
	RUN_TEST(test_vec3_add_basic);

	printf("\n\033[1m=== ft_vec3_sub tests ===\033[0m\n");
	RUN_TEST(test_vec3_sub_basic);

	printf("\n\033[1m=== ft_vec3_scale tests ===\033[0m\n");
	RUN_TEST(test_vec3_scale_basic);

	printf("\n\033[1m=== ft_vec3_dot tests ===\033[0m\n");
	RUN_TEST(test_vec3_dot_basic);
	RUN_TEST(test_vec3_dot_perpendicular);

	printf("\n\033[1m=== ft_vec3_cross tests ===\033[0m\n");
	RUN_TEST(test_vec3_cross_basic);
	RUN_TEST(test_vec3_cross_anticommutative);
	RUN_TEST(test_vec3_cross_parallel_returns_zero);

	printf("\n\033[1m=== ft_vec3_len tests ===\033[0m\n");
	RUN_TEST(test_vec3_len_basic);
	RUN_TEST(test_vec3_len_zero);

	printf("\n\033[1m=== ft_vec3_len_sq tests ===\033[0m\n");
	RUN_TEST(test_vec3_len_sq_basic);

	printf("\n\033[1m=== ft_vec3_norm tests ===\033[0m\n");
	RUN_TEST(test_vec3_norm_basic);
	RUN_TEST(test_vec3_norm_zero);

	printf("\n\033[1m=== ft_vec3_dist tests ===\033[0m\n");
	RUN_TEST(test_vec3_dist_basic);

	printf("\n\033[1m=== ft_vec3_lerp tests ===\033[0m\n");
	RUN_TEST(test_vec3_lerp_zero);
	RUN_TEST(test_vec3_lerp_one);
	RUN_TEST(test_vec3_lerp_half);

	printf("\n\033[1m=== ft_vec3_reflect tests ===\033[0m\n");
	RUN_TEST(test_vec3_reflect_basic);
	RUN_TEST(test_vec3_reflect_perpendicular);

	printf("\n\033[1m=== ft_vec3_negate tests ===\033[0m\n");
	RUN_TEST(test_vec3_negate_basic);
}

int main(void)
{
	printf("\n\033[1;36m╔══════════════════════════════════════╗\033[0m\n");
	printf("\033[1;36m║    ft_vec_math Unit Test Suite       ║\033[0m\n");
	printf("\033[1;36m╚══════════════════════════════════════╝\033[0m\n");

	run_all_tests();

	printf("\n\033[1m════════════════════════════════════════\033[0m\n");
	printf("\033[1mResults: \033[32m%d passed\033[0m, \033[31m%d failed\033[0m\n",
		   g_tests_passed, g_tests_failed);
	printf("\033[1m════════════════════════════════════════\033[0m\n\n");

	return (g_tests_failed > 0 ? 1 : 0);
}
