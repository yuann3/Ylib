/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:59 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 13:39:39 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strncmp.c
 * @brief Compares two strings up to n characters.
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Number of characters to compare.
 * @return Difference between first pair of non-matching characters.
 * 
 * Compares up to the first n characters of s1 and s2. Returns the
 * difference between the first pair of non-matching characters. If
 * the first n characters are equal, returns the difference between
 * the lengths of s1 and s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
