/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:19:08 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/26 17:36:55 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_calloc.c
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 *
 * @param s Pointer to the block of memory to set to zero.
 * @param n Number of bytes to set to zero.
 */
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	if (count != 0 && total / count != size)
		return (NULL);
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
