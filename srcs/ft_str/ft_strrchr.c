/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 15:13:38 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:13:39 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last_occurrence = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)last_occurrence);
}
