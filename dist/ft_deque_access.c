/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_access.c                                  :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/15 17:57:36 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 17:58:18 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_deque_front(t_deque *d)
{
	if (!d || d->len == 0)
		return (NULL);
	return ((char *)d->data + (d->head * d->elem_size));
}

void	*ft_deque_back(t_deque *d)
{
	size_t	back_idx;

	if (!d || d->len == 0)
		return (NULL);
	back_idx = (d->tail - 1 + d->cap) % d->cap;
	return ((char *)d->data + (back_idx * d->elem_size));
}

void	*ft_deque_get(t_deque *d, size_t index)
{
	size_t	phys_idx;

	if (!d || index >= d->len)
		return (NULL);
	phys_idx = (d->head + index) % d->cap;
	return ((char *)d->data + (phys_idx * d->elem_size));
}
