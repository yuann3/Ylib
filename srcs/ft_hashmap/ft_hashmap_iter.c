/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_iter.c                                 :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/02/08 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2026/02/08 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap_internal.h"

/**
 * @brief Iterate over all key-value pairs in the hashmap.
 *
 * Calls the provided function for each entry. Iteration order is
 * undefined (depends on hash distribution). The ctx parameter is
 * passed through to the callback for user context (avoids globals).
 * Mutating the map inside fn is undefined behavior.
 *
 * @param map Hashmap to iterate.
 * @param fn Callback receiving (key, value, ctx) for each entry.
 * @param ctx User context pointer passed to each callback invocation.
 */
void	ft_hashmap_iter(t_hashmap *map,
		void (*fn)(const char *, void *, void *), void *ctx)
{
	size_t			i;
	size_t			j;
	t_vec			*bucket;
	t_hashmap_entry	*entry;

	if (!map || !fn)
		return ;
	i = 0;
	while (i < map->cap)
	{
		bucket = map->buckets[i];
		if (bucket)
		{
			j = 0;
			while (j < bucket->len)
			{
				entry = ft_vec_get(bucket, j);
				fn(entry->key, entry->value, ctx);
				j++;
			}
		}
		i++;
	}
}

/**
 * @brief Get the number of entries in the hashmap.
 *
 * This is O(1) as the size is tracked during insertions/deletions.
 *
 * @param map Hashmap to query.
 * @return Number of entries, or 0 if map is NULL.
 */
size_t	ft_hashmap_size(t_hashmap *map)
{
	if (!map)
		return (0);
	return (map->size);
}
