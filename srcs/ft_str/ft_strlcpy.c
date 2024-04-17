/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:02:43 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 13:21:50 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strlcpy.c
 * @brief Copies a string.
 * @param dst Destination string.
 * @param src Source string.
 * @param destsize Size of destination buffer.
 * @return Length of source string.
 * 
 * Copies up to destsize - 1 characters from the source string
 * to the destination string, null-terminating the result. If
 * destsize is 0, no characters are copied, but the length of
 * the source string is still returned.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (destsize < 1)
		return (res);
	while (src[i] && i < destsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}
