/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:13:47 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/29 08:49:11 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memmove.c
 * @brief Copies a block of memory from a source to a destination,
 *        even if the source and destination overlap.
 *
 * @param dst Pointer to the destination block of memory.
 * @param src Pointer to the source block of memory.
 * @param len Number of bytes to copy.
 * @return void* Returns a pointer to the destination block of memory.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst && len != 0)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
