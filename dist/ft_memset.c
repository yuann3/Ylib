/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:08:52 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:08:53 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int v, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)v;
	return (b);
}
