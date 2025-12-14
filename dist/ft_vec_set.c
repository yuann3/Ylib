/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_set.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 14:02:52 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 14:03:25 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Set the value of an element at the specified index.
 *
 * Copies elem_size bytes from elem to the element at index.
 * Index must be within current length (cannot extend vector).
 *
 * @param vec Pointer to the vector.
 * @param index Zero-based index of the element to set.
 * @param elem Pointer to the source data.
 * @return 1 on success, 0 if out of bounds or NULL params.
 */
int	ft_vec_set(t_vec *vec, size_t index, const void *elem)
{
	void	*dst;

	if (!vec || !elem || index >= vec->len)
		return (0);
	dst = (char *)vec->data + (index * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	return (1);
}
