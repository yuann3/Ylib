/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_deque_new.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/14 15:44:23 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/14 16:11:53 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_deque	*ft_deque_new(size_t elem_size, size_t init_cap)
{
	t_deque	*d;

	if (elem_size == 0)
		return (NULL);
	d = ft_calloc(1, sizeof(t_deque));
	if (!d)
		return (NULL);
	if (init_cap == 0)
		init_cap = 8;
	d->data = ft_calloc(init_cap, elem_size);
	if (!d->data)
		return (free(d), NULL);
	d->elem_size = elem_size;
	d->cap = init_cap;
	d->head = 0;
	d->tail = 0;
	d->len = 0;
	return (d);
}
