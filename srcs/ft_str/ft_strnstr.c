/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:47:42 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/15 16:37:32 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strnstr.c
 * @brief Locates the first occurrence of the substring in the string.
 *
 * @param str The string to be scanned.
 * @param substr The substring to be searched within str.
 * @param len The maximum number of characters to be compared.
 * @return char* A pointer to the first occurrence of the substring in str.
 */
char	*ft_strnstr(const char *str, const char *substr, size_t len)
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
