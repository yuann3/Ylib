/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 14:30:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 14:30:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ensure vector has at least the specified capacity.
 *
 * If new_cap is greater than current capacity, reallocates the
 * internal buffer. Existing elements are preserved. Does nothing
 * if new_cap <= current capacity.
 *
 * @param vec Pointer to the vector.
 * @param new_cap Minimum required capacity.
 * @return 1 on success, 0 on allocation failure or overflow.
 */
int	ft_vec_reserve(t_vec *vec, size_t new_cap)
{
	void	*new_data;

	if (!vec)
		return (0);
	if (new_cap <= vec->cap)
		return (1);
	if (new_cap > SIZE_MAX / vec->elem_size)
		return (0);
	new_data = ft_calloc(new_cap, vec->elem_size);
	if (!new_data)
		return (0);
	ft_memcpy(new_data, vec->data, vec->len * vec->elem_size);
	free(vec->data);
	vec->data = new_data;
	vec->cap = new_cap;
	return (1);
}
