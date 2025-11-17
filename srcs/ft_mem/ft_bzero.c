/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:06:55 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:06:56 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/**
 * @file ft_bzero.c
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 *
 * @param s Pointer to the block of memory to set to zero.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
