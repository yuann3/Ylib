/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/15 17:59:01 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 17:59:22 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_with_buffer(void *first, void *second, char *buf, size_t size)
{
	ft_memcpy(buf, first, size);
	ft_memcpy(first, second, size);
	ft_memcpy(second, buf, size);
}

void	ft_deque_swap(t_deque *d)
{
	void	*first;
	void	*second;
	char	stack_buf[64];
	void	*heap_buf;

	if (!d || d->len < 2)
		return ;
	first = ft_deque_get(d, 0);
	second = ft_deque_get(d, 1);
	if (d->elem_size <= 64)
		swap_with_buffer(first, second, stack_buf, d->elem_size);
	else
	{
		heap_buf = malloc(d->elem_size);
		if (!heap_buf)
			return ;
		swap_with_buffer(first, second, heap_buf, d->elem_size);
		free(heap_buf);
	}
}
