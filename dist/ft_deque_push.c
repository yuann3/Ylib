/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_push.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 16:35:33 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 17:38:10 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_linearized(t_deque *d, void *new_data)
{
	size_t	i;
	void	*src;
	void	*dst;

	i = 0;
	while (i < d->len)
	{
		src = (char *)d->data + (((d->head + i) % d->cap) * d->elem_size);
		dst = (char *)new_data + (i * d->elem_size);
		ft_memcpy(dst, src, d->elem_size);
		i++;
	}
}

static int	ft_deque_grow(t_deque *d)
{
	void	*new_data;
	size_t	new_cap;

	new_cap = d->cap * 2;
	if (new_cap < d->cap)
		return (0);
	new_data = ft_calloc(new_cap, d->elem_size);
	if (!new_data)
		return (0);
	copy_linearized(d, new_data);
	free(d->data);
	d->data = new_data;
	d->cap = new_cap;
	d->head = 0;
	d->tail = d->len;
	return (1);
}

int	ft_deque_push_front(t_deque *d, const void *elem)
{
	void	*dst;

	if (!d || !elem)
		return (0);
	if (d->len == d->cap)
	{
		if (!ft_deque_grow(d))
			return (0);
	}
	d->head = (d->head - 1 + d->cap) % d->cap;
	dst = (char *)d->data + (d->head * d->elem_size);
	ft_memcpy(dst, elem, d->elem_size);
	d->len++;
	return (1);
}

int	ft_deque_push_back(t_deque *d, const void *elem)
{
	void	*dst;

	if (!d || !elem)
		return (0);
	if (d->len == d->cap)
	{
		if (!ft_deque_grow(d))
			return (0);
	}
	dst = (char *)d->data + (d->tail * d->elem_size);
	ft_memcpy(dst, elem, d->elem_size);
	d->tail = (d->tail + 1) % d->cap;
	d->len++;
	return (1);
}
