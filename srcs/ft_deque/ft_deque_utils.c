/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/15 18:02:23 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 18:02:55 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deque_free(t_deque *d)
{
	if (!d)
		return ;
	if (d->data)
		free(d->data);
	free(d);
}

int	ft_deque_is_empty(t_deque *d)
{
	if (!d)
		return (1);
	return (d->len == 0);
}

int	ft_deque_is_full(t_deque *d)
{
	if (!d)
		return (0);
	return (d->len == d->cap);
}

void	ft_deque_rotate(t_deque *d)
{
	void	*first;
	void	*back;

	if (!d || d->len <= 1)
		return ;
	first = (char *)d->data + (d->head * d->elem_size);
	back = (char *)d->data + (d->tail * d->elem_size);
	ft_memcpy(back, first, d->elem_size);
	d->head = (d->head + 1) % d->cap;
	d->tail = (d->tail + 1) % d->cap;
}

void	ft_deque_rrotate(t_deque *d)
{
	void	*last;
	void	*front;
	size_t	last_idx;

	if (!d || d->len <= 1)
		return ;
	last_idx = (d->tail - 1 + d->cap) % d->cap;
	last = (char *)d->data + (last_idx * d->elem_size);
	d->head = (d->head - 1 + d->cap) % d->cap;
	d->tail = (d->tail - 1 + d->cap) % d->cap;
	front = (char *)d->data + (d->head * d->elem_size);
	ft_memcpy(front, last, d->elem_size);
}
