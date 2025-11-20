/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:07:19 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:07:37 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

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
