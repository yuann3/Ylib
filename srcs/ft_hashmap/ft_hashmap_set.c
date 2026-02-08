/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_set.c                                  :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/02/08 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2026/02/08 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap_internal.h"

static size_t	hashmap_hash(const char *key)
{
	size_t			hash;
	unsigned char	*str;

	hash = 5381;
	str = (unsigned char *)key;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash);
}

static t_hashmap_entry	*find_entry(t_vec *bucket, const char *key)
{
	size_t			i;
	t_hashmap_entry	*entry;

	if (!bucket)
		return (NULL);
	i = 0;
	while (i < bucket->len)
	{
		entry = ft_vec_get(bucket, i);
		if (ft_strcmp(entry->key, key) == 0)
			return (entry);
		i++;
	}
	return (NULL);
}

static void	update_entry(t_hashmap *map, t_hashmap_entry *existing,
		void *value)
{
	if (existing->value == value)
		return ;
	if (map->del && existing->value)
		map->del(existing->value);
	existing->value = value;
}

int	ft_hashmap_set(t_hashmap *map, const char *key, void *value)
{
	size_t			idx;
	t_hashmap_entry	*existing;
	t_hashmap_entry	new_entry;

	if (!map || !key)
		return (0);
	idx = hashmap_hash(key) % map->cap;
	existing = find_entry(map->buckets[idx], key);
	if (existing)
		return (update_entry(map, existing, value), 1);
	if (!map->buckets[idx])
		map->buckets[idx] = ft_vec_new(sizeof(t_hashmap_entry), 4);
	if (!map->buckets[idx])
		return (0);
	new_entry.key = ft_strdup(key);
	new_entry.value = value;
	if (!new_entry.key || !ft_vec_push(map->buckets[idx], &new_entry))
		return (free(new_entry.key), 0);
	map->size++;
	if (map->size * 4 > map->cap * 3)
		if (!ft_hashmap_grow(map))
			return (1);
	return (1);
}
