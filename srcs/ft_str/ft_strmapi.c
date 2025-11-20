/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 15:06:56 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:06:58 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_new;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	str_new = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str_new == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
