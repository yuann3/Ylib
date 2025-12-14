/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 14:04:14 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 14:06:43 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get a pointer to the element at the specified index.
 *
 * Performs bounds checking and returns NULL if index is out of range.
 * The returned pointer is valid until the next push or reserve operation.
 *
 * @param vec Pointer to the vector.
 * @param index Zero-based index of the element.
 * @return Pointer to the element, or NULL if out of bounds.
 */
void	*ft_vec_get(t_vec *vec, size_t index)
{
	if (!vec || index >= vec->len)
		return (NULL);
	return ((char *)vec->data + (index * vec->elem_size));
}
