/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_pop.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/15 17:40:05 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 17:42:56 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_deque_pop_front(t_deque *d, void *out)
{
	void	*src;

	if (!d || d->len == 0)
		return (0);
	if (out)
	{
		src = (char *)d->data + (d->head * d->elem_size);
		ft_memcpy(out, src, d->elem_size);
	}
	d->head = (d->head + 1) % d->cap;
	d->len--;
	return (1);
}

int	ft_deque_pop_back(t_deque *d, void *out)
{
	void	*src;

	if (!d || d->len == 0)
		return (0);
	d->tail = (d->tail - 1 + d->cap) % d->cap;
	if (out)
	{
		src = (char *)d->data + (d->tail * d->elem_size);
		ft_memcpy(out, src, d->elem_size);
	}
	d->len--;
	return (1);
}
