/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_get.c                                  :+:      :+:    :+:   */
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

void	*ft_hashmap_get(t_hashmap *map, const char *key)
{
	size_t			idx;
	t_hashmap_entry	*entry;

	if (!map || !key)
		return (NULL);
	idx = hashmap_hash(key) % map->cap;
	entry = find_entry(map->buckets[idx], key);
	if (entry)
		return (entry->value);
	return (NULL);
}

int	ft_hashmap_has(t_hashmap *map, const char *key)
{
	size_t	idx;

	if (!map || !key)
		return (0);
	idx = hashmap_hash(key) % map->cap;
	return (find_entry(map->buckets[idx], key) != NULL);
}
