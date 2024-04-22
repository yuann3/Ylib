/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:47:42 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/22 21:15:04 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (substr[j] == str[i + j] && (i + j) < len)
		{
			if (substr[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
