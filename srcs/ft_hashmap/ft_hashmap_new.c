/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_new.c                                  :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/02/08 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2026/02/08 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap_internal.h"

/**
 * @brief Free a single bucket and all its entries.
 *
 * Iterates through all entries in the bucket, freeing keys and
 * calling the del function on values if provided.
 *
 * @param bucket The bucket vector to free.
 * @param del Value destructor function (can be NULL).
 */
static void	free_bucket(t_vec *bucket, void (*del)(void *))
{
	size_t				i;
	t_hashmap_entry		*entry;

	if (!bucket)
		return ;
	i = 0;
	while (i < bucket->len)
	{
		entry = ft_vec_get(bucket, i);
		free(entry->key);
		if (del && entry->value)
			del(entry->value);
		i++;
	}
	ft_vec_free(bucket);
}

/**
 * @brief Create a new hash table.
 *
 * Allocates a hash table with the specified initial bucket count.
 * If init_cap is 0, defaults to 16 buckets. The del function is
 * called on values during removal/clear/free operations.
 *
 * @param init_cap Initial number of buckets (0 for default of 16).
 * @param del Value destructor function (NULL if values not owned).
 * @return New hashmap, or NULL on allocation failure.
 */
t_hashmap	*ft_hashmap_new(size_t init_cap, void (*del)(void *))
{
	t_hashmap	*map;

	map = ft_calloc(1, sizeof(t_hashmap));
	if (!map)
		return (NULL);
	if (init_cap == 0)
		init_cap = 16;
	map->buckets = ft_calloc(init_cap, sizeof(t_vec *));
	if (!map->buckets)
		return (free(map), NULL);
	map->cap = init_cap;
	map->size = 0;
	map->del = del;
	return (map);
}

/**
 * @brief Remove all entries without freeing the hashmap.
 *
 * Frees all buckets and their entries, then resets the bucket
 * array to all NULLs. The hashmap can be reused after clearing.
 *
 * @param map Hashmap to clear. Safe to call with NULL.
 */
void	ft_hashmap_clear(t_hashmap *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->cap)
	{
		free_bucket(map->buckets[i], map->del);
		map->buckets[i] = NULL;
		i++;
	}
	map->size = 0;
}

/**
 * @brief Free a hashmap and all its contents.
 *
 * Frees all entries, all buckets, the bucket array, and the
 * hashmap struct itself. Safe to call with NULL.
 *
 * @param map Hashmap to free.
 */
void	ft_hashmap_free(t_hashmap *map)
{
	if (!map)
		return ;
	ft_hashmap_clear(map);
	free(map->buckets);
	free(map);
}
