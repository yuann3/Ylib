/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 15:07:33 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:08:13 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned char	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return ((c1 > c2) - (c1 < c2));
}
