/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:30:53 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/28 23:53:13 by yiyli            ###   ########.fr       */
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

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}
