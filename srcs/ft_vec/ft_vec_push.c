/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 13:46:08 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 13:54:22 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the next capacity for vector growth.
 *
 * Uses 1.5x growth factor for memory efficiency.
 * Returns 0 if overflow would occur.
 *
 * @param cap Current capacity.
 * @return New capacity, or 0 on overflow.
 */
static size_t	ft_vec_next_cap(size_t cap)
{
	size_t	new_cap;

	if (cap == 0)
		return (8);
	if (cap > SIZE_MAX / 2)
		return (0);
	new_cap = cap + cap / 2;
	if (new_cap < cap)
		return (0);
	return (new_cap);
}

/**
 * @brief Grow the vector's capacity by 1.5x.
 *
 * Called internally when push would exceed current capacity.
 * Delegates to ft_vec_reserve for the actual reallocation.
 *
 * @param vec Pointer to the vector.
 * @return 1 on success, 0 on allocation failure or overflow.
 */
static int	ft_vec_grow(t_vec *vec)
{
	size_t	new_cap;

	new_cap = ft_vec_next_cap(vec->cap);
	if (new_cap == 0)
		return (0);
	return (ft_vec_reserve(vec, new_cap));
}

/**
 * @brief Append an element to the end of the vector.
 *
 * Copies elem_size bytes from elem to the end of the vector.
 * Automatically grows capacity if needed (1.5x growth factor).
 *
 * @param vec Pointer to the vector.
 * @param elem Pointer to the element to copy.
 * @return 1 on success, 0 on failure or NULL params.
 */
int	ft_vec_push(t_vec *vec, const void *elem)
{
	void	*dst;

	if (!vec || !elem)
		return (0);
	if (vec->len == vec->cap)
	{
		if (!ft_vec_grow(vec))
			return (0);
	}
	dst = (char *)vec->data + (vec->len * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	vec->len++;
	return (1);
}
