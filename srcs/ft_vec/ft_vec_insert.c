/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 15:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 15:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Shift elements right starting from index.
 *
 * Moves elements from index to len-1 one position to the right.
 * Uses memmove to handle overlapping regions safely.
 *
 * @param vec Pointer to the vector.
 * @param index Starting index for the shift.
 */
static void	ft_vec_shift_right(t_vec *vec, size_t index)
{
	void	*src;
	void	*dst;
	size_t	bytes;

	src = (char *)vec->data + (index * vec->elem_size);
	dst = (char *)vec->data + ((index + 1) * vec->elem_size);
	bytes = (vec->len - index) * vec->elem_size;
	ft_memmove(dst, src, bytes);
}

/**
 * @brief Insert an element at the specified index.
 *
 * Shifts existing elements to the right and inserts the new element.
 * Index must be <= len (insert at len is equivalent to push).
 * Grows capacity automatically if needed.
 *
 * @param vec Pointer to the vector.
 * @param index Position to insert at (0 to len).
 * @param elem Pointer to the element to insert.
 * @return 1 on success, 0 on failure or invalid index.
 */
int	ft_vec_insert(t_vec *vec, size_t index, const void *elem)
{
	void	*dst;

	if (!vec || !elem || index > vec->len)
		return (0);
	if (vec->len == vec->cap)
	{
		if (!ft_vec_reserve(vec, vec->cap + vec->cap / 2 + 1))
			return (0);
	}
	if (index < vec->len)
		ft_vec_shift_right(vec, index);
	dst = (char *)vec->data + (index * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	vec->len++;
	return (1);
}
