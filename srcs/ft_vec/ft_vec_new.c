/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 13:40:27 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 13:44:06 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new dynamic array (vector).
 *
 * Allocates and initializes a new vector with the specified element size
 * and initial capacity. If init_cap is 0, defaults to 8 elements.
 *
 * @param elem_size Size of each element in bytes (must be > 0).
 * @param init_cap Initial capacity (0 for default of 8).
 * @return Pointer to newly allocated t_vec, or NULL on failure.
 */
t_vec	*ft_vec_new(size_t elem_size, size_t init_cap)
{
	t_vec	*vec;

	if (elem_size == 0)
		return (NULL);
	vec = ft_calloc(1, sizeof(t_vec));
	if (!vec)
		return (NULL);
	if (init_cap == 0)
		init_cap = 8;
	vec->data = ft_calloc(init_cap, elem_size);
	if (!vec->data)
		return (free(vec), NULL);
	vec->elem_size = elem_size;
	vec->cap = init_cap;
	vec->len = 0;
	return (vec);
}
