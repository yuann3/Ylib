/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec_clear.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 14:07:40 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 14:08:07 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reset vector to empty state without freeing memory.
 *
 * Sets length to 0, keeping the allocated capacity intact.
 * Useful for reusing a vector without reallocation overhead.
 *
 * @param vec Pointer to the vector (can be NULL).
 */
void	ft_vec_clear(t_vec *vec)
{
	if (!vec)
		return ;
	vec->len = 0;
}
