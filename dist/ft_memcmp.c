/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:34:53 by yiyli             #+#    #+#             */
/*   Updated: 2024/06/01 00:54:04 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memcmp.c
 * @brief Compares two blocks of memory.
 *
 * @param s1 Pointer to the first block of memory.
 * @param s2 Pointer to the second block of memory.
 * @param n Number of bytes to compare.
 * @return int Returns an integer less than, equal to,
	or greater than zero if the first n bytes of s1 is found, respectively,
	to be less than, to match, or be greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
