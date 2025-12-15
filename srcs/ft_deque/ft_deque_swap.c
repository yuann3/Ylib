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

void	ft_deque_swap(t_deque *d)
{
	void	*first;
	void	*second;
	char	temp[64];

	if (!d || d->len < 2)
		return ;
	if (d->elem_size > 64)
		return ;
	first = ft_deque_get(d, 0);
	second = ft_deque_get(d, 1);
	ft_memcpy(temp, first, d->elem_size);
	ft_memcpy(first, second, d->elem_size);
	ft_memcpy(second, temp, d->elem_size);
}
