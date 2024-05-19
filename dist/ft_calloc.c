/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:19:08 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/19 15:37:11 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_calloc.c
 * @brief Allocates memory for an array of 'count' elements,
	each of 'size' bytes,
	and initializes all bytes in the allocated storage to zero.
 *
 * @param count Number of elements to be allocated.
 * @param size Size of each element.
 * @return void* Returns a pointer to the allocated memory,
	or NULL if the allocation fails.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
