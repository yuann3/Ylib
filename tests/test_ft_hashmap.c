/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   test_ft_hashmap.c                                  :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/02/08 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2026/02/08 00:00:00 by yiyuli         ###      ########.fr      */
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
#define ASSERT_STR_EQ(a, b) ASSERT(strcmp((a), (b)) == 0)

/* ==================== ft_hashmap_new tests ==================== */

TEST(test_new_default_cap)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_NOT_NULL(map);
    ASSERT_EQ(map->cap, 16);
    ASSERT_EQ(map->size, 0);
    ft_hashmap_free(map);
}

TEST(test_new_custom_cap)
{
    t_hashmap *map = ft_hashmap_new(64, NULL);
    ASSERT_NOT_NULL(map);
    ASSERT_EQ(map->cap, 64);
    ft_hashmap_free(map);
}

TEST(test_new_cap_one)
{
    t_hashmap *map = ft_hashmap_new(1, free);
    ASSERT_NOT_NULL(map);
    ASSERT_EQ(map->cap, 1);
    ft_hashmap_set(map, "a", ft_strdup("v"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_free(map);
}

TEST(test_new_with_del)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ASSERT_NOT_NULL(map);
    ft_hashmap_free(map);
}

TEST(test_new_without_del)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_NOT_NULL(map);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_set tests ==================== */

TEST(test_set_single)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    int ret = ft_hashmap_set(map, "key", ft_strdup("value"));
    ASSERT_EQ(ret, 1);
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_free(map);
}

TEST(test_set_multiple)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ft_hashmap_set(map, "c", ft_strdup("3"));
    ASSERT_EQ(ft_hashmap_size(map), 3);
    ft_hashmap_free(map);
}

TEST(test_set_null_map)
{
    char *leaked = ft_strdup("val");
    int ret = ft_hashmap_set(NULL, "key", leaked);
    ASSERT_EQ(ret, 0);
    free(leaked);
}

TEST(test_set_null_key)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    int ret = ft_hashmap_set(map, NULL, "val");
    ASSERT_EQ(ret, 0);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_free(map);
}

TEST(test_set_null_value)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ft_hashmap_set(map, "key", NULL);
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT_NULL(ft_hashmap_get(map, "key"));
    ASSERT_EQ(ft_hashmap_has(map, "key"), 1);
    ft_hashmap_free(map);
}

TEST(test_set_empty_string_key)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "", ft_strdup("empty_key"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT_STR_EQ(ft_hashmap_get(map, ""), "empty_key");
    ft_hashmap_free(map);
}

TEST(test_set_key_is_copied)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char key[32];
    strcpy(key, "original");
    ft_hashmap_set(map, key, ft_strdup("val"));
    strcpy(key, "modified");
    ASSERT_EQ(ft_hashmap_has(map, "original"), 1);
    ASSERT_EQ(ft_hashmap_has(map, "modified"), 0);
    ft_hashmap_free(map);
}

/* ==================== Update (overwrite) tests ==================== */

TEST(test_update_existing_key)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("old"));
    ft_hashmap_set(map, "key", ft_strdup("new"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT_STR_EQ(ft_hashmap_get(map, "key"), "new");
    ft_hashmap_free(map);
}

TEST(test_update_does_not_increase_size)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "x", ft_strdup("1"));
    ft_hashmap_set(map, "x", ft_strdup("2"));
    ft_hashmap_set(map, "x", ft_strdup("3"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_free(map);
}

TEST(test_self_assignment_no_double_free)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char *val = ft_strdup("test");
    ft_hashmap_set(map, "key", val);
    ft_hashmap_set(map, "key", val);
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT(ft_hashmap_get(map, "key") == val);
    ft_hashmap_free(map);
}

TEST(test_update_with_null_del)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    int a = 1;
    int b = 2;
    ft_hashmap_set(map, "k", &a);
    ft_hashmap_set(map, "k", &b);
    ASSERT(ft_hashmap_get(map, "k") == &b);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_get tests ==================== */

TEST(test_get_existing)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "PATH", ft_strdup("/usr/bin"));
    char *val = ft_hashmap_get(map, "PATH");
    ASSERT_NOT_NULL(val);
    ASSERT_STR_EQ(val, "/usr/bin");
    ft_hashmap_free(map);
}

TEST(test_get_nonexistent)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_NULL(ft_hashmap_get(map, "nope"));
    ft_hashmap_free(map);
}

TEST(test_get_null_map)
{
    ASSERT_NULL(ft_hashmap_get(NULL, "key"));
}

TEST(test_get_null_key)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_NULL(ft_hashmap_get(map, NULL));
    ft_hashmap_free(map);
}

TEST(test_get_after_delete)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("val"));
    ft_hashmap_del(map, "key");
    ASSERT_NULL(ft_hashmap_get(map, "key"));
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_has tests ==================== */

TEST(test_has_existing)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("val"));
    ASSERT_EQ(ft_hashmap_has(map, "key"), 1);
    ft_hashmap_free(map);
}

TEST(test_has_nonexistent)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_EQ(ft_hashmap_has(map, "nope"), 0);
    ft_hashmap_free(map);
}

TEST(test_has_null_map)
{
    ASSERT_EQ(ft_hashmap_has(NULL, "key"), 0);
}

TEST(test_has_null_key)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_EQ(ft_hashmap_has(map, NULL), 0);
    ft_hashmap_free(map);
}

TEST(test_has_with_null_value)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ft_hashmap_set(map, "null_val", NULL);
    ASSERT_EQ(ft_hashmap_has(map, "null_val"), 1);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_del tests ==================== */

TEST(test_del_existing)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("val"));
    int ret = ft_hashmap_del(map, "key");
    ASSERT_EQ(ret, 1);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ASSERT_EQ(ft_hashmap_has(map, "key"), 0);
    ft_hashmap_free(map);
}

TEST(test_del_nonexistent)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    int ret = ft_hashmap_del(map, "nope");
    ASSERT_EQ(ret, 0);
    ft_hashmap_free(map);
}

TEST(test_del_null_map)
{
    ASSERT_EQ(ft_hashmap_del(NULL, "key"), 0);
}

TEST(test_del_null_key)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_EQ(ft_hashmap_del(map, NULL), 0);
    ft_hashmap_free(map);
}

TEST(test_del_first_of_many)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ft_hashmap_set(map, "c", ft_strdup("3"));
    ft_hashmap_del(map, "a");
    ASSERT_EQ(ft_hashmap_size(map), 2);
    ASSERT_EQ(ft_hashmap_has(map, "a"), 0);
    ASSERT_EQ(ft_hashmap_has(map, "b"), 1);
    ASSERT_EQ(ft_hashmap_has(map, "c"), 1);
    ft_hashmap_free(map);
}

TEST(test_del_last_entry_in_bucket)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "only", ft_strdup("val"));
    ft_hashmap_del(map, "only");
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_set(map, "only", ft_strdup("reinserted"));
    ASSERT_STR_EQ(ft_hashmap_get(map, "only"), "reinserted");
    ft_hashmap_free(map);
}

TEST(test_del_double_delete)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("val"));
    ASSERT_EQ(ft_hashmap_del(map, "key"), 1);
    ASSERT_EQ(ft_hashmap_del(map, "key"), 0);
    ft_hashmap_free(map);
}

TEST(test_del_all_entries)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 20)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 20);
    i = 0;
    while (i < 20)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ASSERT_EQ(ft_hashmap_del(map, buf), 1);
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_clear tests ==================== */

TEST(test_clear_basic)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ft_hashmap_clear(map);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ASSERT_EQ(ft_hashmap_has(map, "a"), 0);
    ASSERT_EQ(ft_hashmap_has(map, "b"), 0);
    ft_hashmap_free(map);
}

TEST(test_clear_then_reuse)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "old", ft_strdup("data"));
    ft_hashmap_clear(map);
    ft_hashmap_set(map, "new", ft_strdup("data"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT_STR_EQ(ft_hashmap_get(map, "new"), "data");
    ASSERT_EQ(ft_hashmap_has(map, "old"), 0);
    ft_hashmap_free(map);
}

TEST(test_clear_empty_map)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ft_hashmap_clear(map);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_free(map);
}

TEST(test_clear_null_map)
{
    ft_hashmap_clear(NULL);
}

TEST(test_clear_multiple_times)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_clear(map);
    ft_hashmap_clear(map);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_free tests ==================== */

TEST(test_free_null)
{
    ft_hashmap_free(NULL);
}

TEST(test_free_empty_map)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ft_hashmap_free(map);
}

TEST(test_free_populated_map)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ft_hashmap_set(map, "c", ft_strdup("3"));
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_iter tests ==================== */

static void	count_entries(const char *key, void *value, void *ctx)
{
    int *count = (int *)ctx;
    (*count)++;
    (void)key;
    (void)value;
}

static void	collect_keys(const char *key, void *value, void *ctx)
{
    int *sum = (int *)ctx;
    *sum += (int)strlen(key);
    (void)value;
}

TEST(test_iter_basic)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    int count = 0;
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ft_hashmap_set(map, "c", ft_strdup("3"));
    ft_hashmap_iter(map, count_entries, &count);
    ASSERT_EQ(count, 3);
    ft_hashmap_free(map);
}

TEST(test_iter_empty)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    int count = 0;
    ft_hashmap_iter(map, count_entries, &count);
    ASSERT_EQ(count, 0);
    ft_hashmap_free(map);
}

TEST(test_iter_null_map)
{
    int count = 0;
    ft_hashmap_iter(NULL, count_entries, &count);
    ASSERT_EQ(count, 0);
}

TEST(test_iter_null_fn)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ft_hashmap_iter(map, NULL, NULL);
    ft_hashmap_free(map);
}

TEST(test_iter_ctx_passed_correctly)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    int key_len_sum = 0;
    ft_hashmap_set(map, "ab", ft_strdup("1"));
    ft_hashmap_set(map, "cd", ft_strdup("2"));
    ft_hashmap_set(map, "ef", ft_strdup("3"));
    ft_hashmap_iter(map, collect_keys, &key_len_sum);
    ASSERT_EQ(key_len_sum, 6);
    ft_hashmap_free(map);
}

/* ==================== ft_hashmap_size tests ==================== */

TEST(test_size_empty)
{
    t_hashmap *map = ft_hashmap_new(0, NULL);
    ASSERT_EQ(ft_hashmap_size(map), 0);
    ft_hashmap_free(map);
}

TEST(test_size_null)
{
    ASSERT_EQ(ft_hashmap_size(NULL), 0);
}

TEST(test_size_after_operations)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "a", ft_strdup("1"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_set(map, "b", ft_strdup("2"));
    ASSERT_EQ(ft_hashmap_size(map), 2);
    ft_hashmap_del(map, "a");
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_set(map, "b", ft_strdup("updated"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ft_hashmap_free(map);
}

/* ==================== Grow / resize tests ==================== */

TEST(test_grow_triggers_at_load_factor)
{
    t_hashmap *map = ft_hashmap_new(4, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 4)
    {
        snprintf(buf, sizeof(buf), "k%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    ASSERT(map->cap > 4);
    ft_hashmap_free(map);
}

TEST(test_grow_preserves_all_entries)
{
    t_hashmap *map = ft_hashmap_new(4, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 50)
    {
        snprintf(buf, sizeof(buf), "key_%03d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 50);
    i = 0;
    while (i < 50)
    {
        snprintf(buf, sizeof(buf), "key_%03d", i);
        ASSERT_EQ(ft_hashmap_has(map, buf), 1);
        ASSERT_STR_EQ(ft_hashmap_get(map, buf), buf);
        i++;
    }
    ft_hashmap_free(map);
}

TEST(test_grow_multiple_times)
{
    t_hashmap *map = ft_hashmap_new(2, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 200)
    {
        snprintf(buf, sizeof(buf), "k%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 200);
    ASSERT(map->cap >= 200);
    i = 0;
    while (i < 200)
    {
        snprintf(buf, sizeof(buf), "k%d", i);
        ASSERT_STR_EQ(ft_hashmap_get(map, buf), buf);
        i++;
    }
    ft_hashmap_free(map);
}

/* ==================== Collision tests ==================== */

TEST(test_collision_same_bucket)
{
    t_hashmap *map = ft_hashmap_new(1, free);
    ft_hashmap_set(map, "a", ft_strdup("val_a"));
    ft_hashmap_set(map, "b", ft_strdup("val_b"));
    ft_hashmap_set(map, "c", ft_strdup("val_c"));
    ASSERT_STR_EQ(ft_hashmap_get(map, "a"), "val_a");
    ASSERT_STR_EQ(ft_hashmap_get(map, "b"), "val_b");
    ASSERT_STR_EQ(ft_hashmap_get(map, "c"), "val_c");
    ft_hashmap_free(map);
}

TEST(test_collision_delete_from_chain)
{
    t_hashmap *map = ft_hashmap_new(1, free);
    ft_hashmap_set(map, "x", ft_strdup("1"));
    ft_hashmap_set(map, "y", ft_strdup("2"));
    ft_hashmap_set(map, "z", ft_strdup("3"));
    ft_hashmap_del(map, "y");
    ASSERT_EQ(ft_hashmap_size(map), 2);
    ASSERT_STR_EQ(ft_hashmap_get(map, "x"), "1");
    ASSERT_EQ(ft_hashmap_has(map, "y"), 0);
    ASSERT_STR_EQ(ft_hashmap_get(map, "z"), "3");
    ft_hashmap_free(map);
}

/* ==================== Edge case tests ==================== */

TEST(test_long_key)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char long_key[1024];
    memset(long_key, 'A', 1023);
    long_key[1023] = '\0';
    ft_hashmap_set(map, long_key, ft_strdup("long"));
    ASSERT_STR_EQ(ft_hashmap_get(map, long_key), "long");
    ft_hashmap_free(map);
}

TEST(test_similar_keys)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "abc", ft_strdup("1"));
    ft_hashmap_set(map, "abd", ft_strdup("2"));
    ft_hashmap_set(map, "ab",  ft_strdup("3"));
    ft_hashmap_set(map, "abcd", ft_strdup("4"));
    ASSERT_EQ(ft_hashmap_size(map), 4);
    ASSERT_STR_EQ(ft_hashmap_get(map, "abc"), "1");
    ASSERT_STR_EQ(ft_hashmap_get(map, "abd"), "2");
    ASSERT_STR_EQ(ft_hashmap_get(map, "ab"), "3");
    ASSERT_STR_EQ(ft_hashmap_get(map, "abcd"), "4");
    ft_hashmap_free(map);
}

TEST(test_set_after_del_same_key)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    ft_hashmap_set(map, "key", ft_strdup("first"));
    ft_hashmap_del(map, "key");
    ft_hashmap_set(map, "key", ft_strdup("second"));
    ASSERT_EQ(ft_hashmap_size(map), 1);
    ASSERT_STR_EQ(ft_hashmap_get(map, "key"), "second");
    ft_hashmap_free(map);
}

TEST(test_interleaved_set_del)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 100)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    i = 0;
    while (i < 50)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ft_hashmap_del(map, buf);
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 50);
    i = 50;
    while (i < 100)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ASSERT_EQ(ft_hashmap_has(map, buf), 1);
        i++;
    }
    i = 0;
    while (i < 50)
    {
        snprintf(buf, sizeof(buf), "key_%d", i);
        ASSERT_EQ(ft_hashmap_has(map, buf), 0);
        i++;
    }
    ft_hashmap_free(map);
}

/* ==================== Custom struct value tests ==================== */

typedef struct s_pair
{
    int     id;
    char    name[64];
}   t_pair;

static void	free_pair(void *ptr)
{
    free(ptr);
}

static t_pair	*make_pair(int id, const char *name)
{
    t_pair *p = malloc(sizeof(t_pair));
    if (!p)
        return (NULL);
    p->id = id;
    strncpy(p->name, name, 63);
    p->name[63] = '\0';
    return (p);
}

TEST(test_struct_values)
{
    t_hashmap *map = ft_hashmap_new(0, free_pair);
    t_pair *p;

    ft_hashmap_set(map, "alice", make_pair(1, "Alice"));
    ft_hashmap_set(map, "bob", make_pair(2, "Bob"));
    p = ft_hashmap_get(map, "alice");
    ASSERT_NOT_NULL(p);
    ASSERT_EQ(p->id, 1);
    ASSERT_STR_EQ(p->name, "Alice");
    p = ft_hashmap_get(map, "bob");
    ASSERT_EQ(p->id, 2);
    ft_hashmap_free(map);
}

TEST(test_struct_update_frees_old)
{
    t_hashmap *map = ft_hashmap_new(0, free_pair);
    ft_hashmap_set(map, "user", make_pair(1, "Old"));
    ft_hashmap_set(map, "user", make_pair(2, "New"));
    t_pair *p = ft_hashmap_get(map, "user");
    ASSERT_EQ(p->id, 2);
    ASSERT_STR_EQ(p->name, "New");
    ft_hashmap_free(map);
}

/* ==================== Stress tests ==================== */

TEST(test_stress_1000_entries)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 1000)
    {
        snprintf(buf, sizeof(buf), "stress_%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        i++;
    }
    ASSERT_EQ(ft_hashmap_size(map), 1000);
    i = 0;
    while (i < 1000)
    {
        snprintf(buf, sizeof(buf), "stress_%d", i);
        ASSERT_STR_EQ(ft_hashmap_get(map, buf), buf);
        i++;
    }
    ft_hashmap_free(map);
}

TEST(test_stress_insert_delete_reinsert)
{
    t_hashmap *map = ft_hashmap_new(0, free);
    char buf[32];
    int i;
    int round;

    round = 0;
    while (round < 3)
    {
        i = 0;
        while (i < 100)
        {
            snprintf(buf, sizeof(buf), "r%d_k%d", round, i);
            ft_hashmap_set(map, buf, ft_strdup(buf));
            i++;
        }
        i = 0;
        while (i < 100)
        {
            snprintf(buf, sizeof(buf), "r%d_k%d", round, i);
            ft_hashmap_del(map, buf);
            i++;
        }
        ASSERT_EQ(ft_hashmap_size(map), 0);
        round++;
    }
    ft_hashmap_free(map);
}

TEST(test_stress_alternating_ops)
{
    t_hashmap *map = ft_hashmap_new(8, free);
    char buf[32];
    int i;

    i = 0;
    while (i < 500)
    {
        snprintf(buf, sizeof(buf), "a%d", i);
        ft_hashmap_set(map, buf, ft_strdup(buf));
        if (i > 0 && i % 3 == 0)
        {
            snprintf(buf, sizeof(buf), "a%d", i - 1);
            ft_hashmap_del(map, buf);
        }
        i++;
    }
    ASSERT(ft_hashmap_size(map) > 0);
    ft_hashmap_free(map);
}

/* ==================== Env var simulation ==================== */

TEST(test_env_var_simulation)
{
    t_hashmap *env = ft_hashmap_new(0, free);

    ft_hashmap_set(env, "PATH", ft_strdup("/usr/bin:/bin"));
    ft_hashmap_set(env, "HOME", ft_strdup("/Users/yuan"));
    ft_hashmap_set(env, "SHELL", ft_strdup("/bin/zsh"));
    ft_hashmap_set(env, "USER", ft_strdup("yuan"));
    ft_hashmap_set(env, "LANG", ft_strdup("en_US.UTF-8"));

    ASSERT_STR_EQ(ft_hashmap_get(env, "PATH"), "/usr/bin:/bin");
    ASSERT_STR_EQ(ft_hashmap_get(env, "HOME"), "/Users/yuan");

    ft_hashmap_set(env, "PATH", ft_strdup("/usr/local/bin:/usr/bin:/bin"));
    ASSERT_STR_EQ(ft_hashmap_get(env, "PATH"), "/usr/local/bin:/usr/bin:/bin");

    ft_hashmap_del(env, "LANG");
    ASSERT_EQ(ft_hashmap_has(env, "LANG"), 0);
    ASSERT_EQ(ft_hashmap_size(env), 4);

    ft_hashmap_free(env);
}

/* ==================== Main ==================== */

void run_all_tests(void)
{
    printf("\n\033[1m=== ft_hashmap_new tests ===\033[0m\n");
    RUN_TEST(test_new_default_cap);
    RUN_TEST(test_new_custom_cap);
    RUN_TEST(test_new_cap_one);
    RUN_TEST(test_new_with_del);
    RUN_TEST(test_new_without_del);

    printf("\n\033[1m=== ft_hashmap_set tests ===\033[0m\n");
    RUN_TEST(test_set_single);
    RUN_TEST(test_set_multiple);
    RUN_TEST(test_set_null_map);
    RUN_TEST(test_set_null_key);
    RUN_TEST(test_set_null_value);
    RUN_TEST(test_set_empty_string_key);
    RUN_TEST(test_set_key_is_copied);

    printf("\n\033[1m=== Update (overwrite) tests ===\033[0m\n");
    RUN_TEST(test_update_existing_key);
    RUN_TEST(test_update_does_not_increase_size);
    RUN_TEST(test_self_assignment_no_double_free);
    RUN_TEST(test_update_with_null_del);

    printf("\n\033[1m=== ft_hashmap_get tests ===\033[0m\n");
    RUN_TEST(test_get_existing);
    RUN_TEST(test_get_nonexistent);
    RUN_TEST(test_get_null_map);
    RUN_TEST(test_get_null_key);
    RUN_TEST(test_get_after_delete);

    printf("\n\033[1m=== ft_hashmap_has tests ===\033[0m\n");
    RUN_TEST(test_has_existing);
    RUN_TEST(test_has_nonexistent);
    RUN_TEST(test_has_null_map);
    RUN_TEST(test_has_null_key);
    RUN_TEST(test_has_with_null_value);

    printf("\n\033[1m=== ft_hashmap_del tests ===\033[0m\n");
    RUN_TEST(test_del_existing);
    RUN_TEST(test_del_nonexistent);
    RUN_TEST(test_del_null_map);
    RUN_TEST(test_del_null_key);
    RUN_TEST(test_del_first_of_many);
    RUN_TEST(test_del_last_entry_in_bucket);
    RUN_TEST(test_del_double_delete);
    RUN_TEST(test_del_all_entries);

    printf("\n\033[1m=== ft_hashmap_clear tests ===\033[0m\n");
    RUN_TEST(test_clear_basic);
    RUN_TEST(test_clear_then_reuse);
    RUN_TEST(test_clear_empty_map);
    RUN_TEST(test_clear_null_map);
    RUN_TEST(test_clear_multiple_times);

    printf("\n\033[1m=== ft_hashmap_free tests ===\033[0m\n");
    RUN_TEST(test_free_null);
    RUN_TEST(test_free_empty_map);
    RUN_TEST(test_free_populated_map);

    printf("\n\033[1m=== ft_hashmap_iter tests ===\033[0m\n");
    RUN_TEST(test_iter_basic);
    RUN_TEST(test_iter_empty);
    RUN_TEST(test_iter_null_map);
    RUN_TEST(test_iter_null_fn);
    RUN_TEST(test_iter_ctx_passed_correctly);

    printf("\n\033[1m=== ft_hashmap_size tests ===\033[0m\n");
    RUN_TEST(test_size_empty);
    RUN_TEST(test_size_null);
    RUN_TEST(test_size_after_operations);

    printf("\n\033[1m=== Grow / resize tests ===\033[0m\n");
    RUN_TEST(test_grow_triggers_at_load_factor);
    RUN_TEST(test_grow_preserves_all_entries);
    RUN_TEST(test_grow_multiple_times);

    printf("\n\033[1m=== Collision tests ===\033[0m\n");
    RUN_TEST(test_collision_same_bucket);
    RUN_TEST(test_collision_delete_from_chain);

    printf("\n\033[1m=== Edge case tests ===\033[0m\n");
    RUN_TEST(test_long_key);
    RUN_TEST(test_similar_keys);
    RUN_TEST(test_set_after_del_same_key);
    RUN_TEST(test_interleaved_set_del);

    printf("\n\033[1m=== Custom struct value tests ===\033[0m\n");
    RUN_TEST(test_struct_values);
    RUN_TEST(test_struct_update_frees_old);

    printf("\n\033[1m=== Stress tests ===\033[0m\n");
    RUN_TEST(test_stress_1000_entries);
    RUN_TEST(test_stress_insert_delete_reinsert);
    RUN_TEST(test_stress_alternating_ops);

    printf("\n\033[1m=== Env var simulation ===\033[0m\n");
    RUN_TEST(test_env_var_simulation);
}

int main(void)
{
    printf("\n\033[1;36m╔══════════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║    ft_hashmap Unit Test Suite        ║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════════╝\033[0m\n");

    run_all_tests();

    printf("\n\033[1m════════════════════════════════════════\033[0m\n");
    printf("\033[1mResults: \033[32m%d passed\033[0m, \033[31m%d failed\033[0m\n",
           g_tests_passed, g_tests_failed);
    printf("\033[1m════════════════════════════════════════\033[0m\n\n");

    return (g_tests_failed > 0 ? 1 : 0);
}
