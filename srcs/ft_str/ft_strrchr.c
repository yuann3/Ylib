/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:51 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/31 13:39:35 by yiyli            ###   ########.fr       */
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
