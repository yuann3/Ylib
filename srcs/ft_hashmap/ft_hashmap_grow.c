/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_grow.c                                  :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/03/22 15:31:32 by yiyuli           #+#      #+#            */
/*   Updated: 2026/03/22 15:59:11 by yiyuli         ###      ########.fr      */
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

static int rehash_insert(t_vec **buckets, size_t cap, t_hashmap_entry *entry) {
	size_t idx;

	idx = hashmap_hash(entry->key) % cap;
	if (!buckets[idx])
		buckets[idx] = ft_vec_new(sizeof(t_hashmap_entry), 4);
	if (!buckets[idx])
		return 0;
	return ft_vec_push(buckets[idx], entry);
}

static int rehash_all(t_vec **new_b, size_t new_cap, t_vec **old_b,
                      size_t old_cap) {
	size_t i;
	size_t j;
	t_hashmap_entry *entry;

	i = 0;
	while (i < old_cap) {
		if (old_b[i]) {
			j = 0;
			while (j < old_b[i]->len) {
				entry = ft_vec_get(old_b[i], j);
				if (!rehash_insert(new_b, new_cap, entry))
					return 0;
				j++;
			}
        }
		i++;
    }
	return 1;
}

static void free_bucket_shells(t_vec **buckets, size_t cap) {
	size_t i;

	i = 0;
	while (i < cap) {
		if (buckets[i])
			ft_vec_free(buckets[i]);
		i++;
    }
}
