/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_del.c                                  :+:      :+:    :+:   */
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

static void	remove_entry(t_hashmap *map, t_vec *bucket,
		t_hashmap_entry *entry)
{
	t_hashmap_entry	*last;

	free(entry->key);
	if (map->del && entry->value)
		map->del(entry->value);
	last = ft_vec_get(bucket, bucket->len - 1);
	if (entry != last)
		*entry = *last;
	bucket->len--;
	map->size--;
}

int	ft_hashmap_del(t_hashmap *map, const char *key)
{
	size_t			idx;
	size_t			i;
	t_vec			*bucket;
	t_hashmap_entry	*entry;

	if (!map || !key)
		return (0);
	idx = hashmap_hash(key) % map->cap;
	bucket = map->buckets[idx];
	if (!bucket)
		return (0);
	i = 0;
	while (i < bucket->len)
	{
		entry = ft_vec_get(bucket, i);
		if (ft_strcmp(entry->key, key) == 0)
			return (remove_entry(map, bucket, entry), 1);
		i++;
	}
	return (0);
}
