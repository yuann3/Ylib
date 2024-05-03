/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:51 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/24 18:57:41 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strrchr.c
 * @brief Locates the last occurrence of c (converted to a char) in the string.
 *
 * @param str The string to be scanned.
 * @param c The character to be searched within str.
 * @return char* A pointer to the last occurrence of the character in str.
 */
char	*ft_strrchr(const char *str, int c)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret = &((char *)str)[i];
		i++;
	}
	if (c == '\0')
		ret = &((char *)str)[i];
	return (ret);
}
