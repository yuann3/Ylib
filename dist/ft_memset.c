/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:30:53 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/17 17:52:24 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memset.c
 * @brief Fills a block of memory with a specified value.
 *
 * @param b Pointer to the block of memory to fill.
 * @param c The value to be set. The value is passed as an int,
	but the function fills the block of memory using the
  unsigned char conversion of this value.
 * @param len Number of bytes to be set to the value.
 * @return void* Returns a pointer to the block of memory.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (!b)
		return (0);
	ptr = b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}
