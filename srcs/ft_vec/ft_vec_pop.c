/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 13:56:16 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 13:58:01 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Remove and optionally retrieve the last element.
 *
 * Decrements the vector length. If out is not NULL, copies the
 * removed element to the provided buffer before removal.
 *
 * @param vec Pointer to the vector.
 * @param out Buffer to receive the popped element (can be NULL).
 * @return 1 on success, 0 if vec is NULL or empty.
 */
int	ft_vec_pop(t_vec *vec, void *out)
{
	void	*src;

	if (!vec || vec->len == 0)
		return (0);
	vec->len--;
	if (out)
	{
		src = (char *)vec->data + (vec->len * vec->elem_size);
		ft_memcpy(out, src, vec->elem_size);
	}
	return (1);
}
