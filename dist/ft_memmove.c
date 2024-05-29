/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:13:47 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/29 08:48:42 by yiyli            ###   ########.fr       */
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
	unsigned char		*dst_ptr;
	unsigned const char	*src_ptr;

	if (!dst && !src && len != 0)
		return (NULL);
	if (dst < src)
	{
		dst_ptr = (unsigned char *)dst;
		src_ptr = (unsigned const char *)src;
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		dst_ptr = (unsigned char *)dst + len;
		src_ptr = (unsigned const char *)src + len;
		while (len--)
			*--dst_ptr = *--src_ptr;
	}
	return (dst);
}
