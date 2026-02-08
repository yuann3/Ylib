#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void	print_entry(const char *key, void *value, void *ctx)
{
	int	*count;

	count = (int *)ctx;
	(*count)++;
	(void)key;
	(void)value;
}

static void	test_basic_lifecycle(void)
{
	t_hashmap	*map;

	map = ft_hashmap_new(0, free);
	assert(map != NULL);
	assert(ft_hashmap_size(map) == 0);
	ft_hashmap_free(map);
	printf("  [OK] basic lifecycle\n");
}

static void	test_set_get_del(void)
{
	t_hashmap	*map;
	char		*val;

	map = ft_hashmap_new(0, free);
	ft_hashmap_set(map, "PATH", ft_strdup("/usr/bin"));
	ft_hashmap_set(map, "HOME", ft_strdup("/Users/yuan"));
	ft_hashmap_set(map, "SHELL", ft_strdup("/bin/zsh"));
	assert(ft_hashmap_size(map) == 3);
	val = ft_hashmap_get(map, "PATH");
	assert(val != NULL && strcmp(val, "/usr/bin") == 0);
	assert(ft_hashmap_has(map, "HOME") == 1);
	assert(ft_hashmap_has(map, "NOPE") == 0);
	ft_hashmap_del(map, "SHELL");
	assert(ft_hashmap_size(map) == 2);
	assert(ft_hashmap_has(map, "SHELL") == 0);
	ft_hashmap_free(map);
	printf("  [OK] set/get/del\n");
}

static void	test_update_existing_key(void)
{
	t_hashmap	*map;
	char		*val;

	map = ft_hashmap_new(0, free);
	ft_hashmap_set(map, "KEY", ft_strdup("old_value"));
	ft_hashmap_set(map, "KEY", ft_strdup("new_value"));
	assert(ft_hashmap_size(map) == 1);
	val = ft_hashmap_get(map, "KEY");
	assert(strcmp(val, "new_value") == 0);
	ft_hashmap_free(map);
	printf("  [OK] update existing key (old value freed)\n");
}

static void	test_self_assignment(void)
{
	t_hashmap	*map;
	char		*val;

	map = ft_hashmap_new(0, free);
	val = ft_strdup("test");
	ft_hashmap_set(map, "KEY", val);
	ft_hashmap_set(map, "KEY", val);
	assert(ft_hashmap_size(map) == 1);
	assert(ft_hashmap_get(map, "KEY") == val);
	ft_hashmap_free(map);
	printf("  [OK] self-assignment (no double-free)\n");
}

static void	test_grow(void)
{
	t_hashmap	*map;
	char		buf[32];
	int			i;

	map = ft_hashmap_new(4, free);
	i = 0;
	while (i < 50)
	{
		sprintf(buf, "key_%d", i);
		ft_hashmap_set(map, buf, ft_strdup(buf));
		i++;
	}
	assert(ft_hashmap_size(map) == 50);
	i = 0;
	while (i < 50)
	{
		sprintf(buf, "key_%d", i);
		assert(ft_hashmap_has(map, buf) == 1);
		assert(strcmp(ft_hashmap_get(map, buf), buf) == 0);
		i++;
	}
	ft_hashmap_free(map);
	printf("  [OK] grow (4 -> 50 entries)\n");
}

static void	test_clear(void)
{
	t_hashmap	*map;

	map = ft_hashmap_new(0, free);
	ft_hashmap_set(map, "A", ft_strdup("1"));
	ft_hashmap_set(map, "B", ft_strdup("2"));
	ft_hashmap_clear(map);
	assert(ft_hashmap_size(map) == 0);
	assert(ft_hashmap_has(map, "A") == 0);
	ft_hashmap_set(map, "C", ft_strdup("3"));
	assert(ft_hashmap_size(map) == 1);
	ft_hashmap_free(map);
	printf("  [OK] clear and reuse\n");
}

static void	test_iter(void)
{
	t_hashmap	*map;
	int			count;

	map = ft_hashmap_new(0, free);
	ft_hashmap_set(map, "X", ft_strdup("1"));
	ft_hashmap_set(map, "Y", ft_strdup("2"));
	ft_hashmap_set(map, "Z", ft_strdup("3"));
	count = 0;
	ft_hashmap_iter(map, print_entry, &count);
	assert(count == 3);
	ft_hashmap_free(map);
	printf("  [OK] iter with ctx\n");
}

static void	test_null_value(void)
{
	t_hashmap	*map;

	map = ft_hashmap_new(0, NULL);
	ft_hashmap_set(map, "null_val", NULL);
	assert(ft_hashmap_has(map, "null_val") == 1);
	assert(ft_hashmap_get(map, "null_val") == NULL);
	ft_hashmap_free(map);
	printf("  [OK] NULL value stored correctly\n");
}

static void	test_delete_all(void)
{
	t_hashmap	*map;
	char		buf[32];
	int			i;

	map = ft_hashmap_new(0, free);
	i = 0;
	while (i < 20)
	{
		sprintf(buf, "k%d", i);
		ft_hashmap_set(map, buf, ft_strdup(buf));
		i++;
	}
	i = 0;
	while (i < 20)
	{
		sprintf(buf, "k%d", i);
		ft_hashmap_del(map, buf);
		i++;
	}
	assert(ft_hashmap_size(map) == 0);
	ft_hashmap_free(map);
	printf("  [OK] delete all entries\n");
}

int	main(void)
{
	printf("=== hashmap leak tests ===\n");
	test_basic_lifecycle();
	test_set_get_del();
	test_update_existing_key();
	test_self_assignment();
	test_grow();
	test_clear();
	test_iter();
	test_null_value();
	test_delete_all();
	printf("=== all tests passed ===\n");
	return (0);
}
