/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 14:07:05 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 14:07:25 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free all memory associated with the vector.
 *
 * Frees both the internal data buffer and the vector struct itself.
 * Safe to call with NULL. Does not free heap-allocated elements
 * stored within the vector (user responsibility).
 *
 * @param vec Pointer to the vector to free (can be NULL).
 */
void	ft_vec_free(t_vec *vec)
{
	if (!vec)
		return ;
	if (vec->data)
		free(vec->data);
	free(vec);
}
