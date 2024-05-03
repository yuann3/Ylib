/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:42:58 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/26 16:55:10 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memchr.c
 * @brief Locates the first occurrence of a character in a block of memory.
 *
 * @param str Pointer to the block of memory.
 * @param c The character to locate. The value is passed as an int,
	but the function locates the unsigned char conversion of
  this value in the block of memory.
 * @param n Number of bytes to analyze.
 * @return void* Returns a pointer to the located character,
	or NULL if the character does not occur in the block of memory.
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;

	p = str;
	while (n-- != 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
