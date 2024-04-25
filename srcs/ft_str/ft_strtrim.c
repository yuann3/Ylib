/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:58:14 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/25 20:31:15 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is in a set of characters.
 *
 * @param c The character to be checked.
 * @param set The set of characters.
 * @return int Returns 1 if the character is in the set, 0 otherwise.
 */
int	ft_checkset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/**
 * @file ft_strtrim.c
 * @brief Trims the start and end of a string based on a set of characters.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim.
 * @return char* Returns the trimmed string, or NULL if an error occurs.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	trimmed[len] = '\0';
	return (trimmed);
}
