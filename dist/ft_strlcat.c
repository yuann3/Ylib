/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:47:24 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/19 15:28:45 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strlcat.c
 * @brief Appends string src to the end of dest.
 * @param dest Destination string.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return Total length of the string they tried to create.
 *
 * Appends the src string to the dest string overwriting the '\0'
 * character at the end of dest, and then adds a '\0'. If the
 * resulting string would exceed size, src is truncated to fit.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}
