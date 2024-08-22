/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:08:10 by yiyli             #+#    #+#             */
/*   Updated: 2024/06/10 17:49:29 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr_recursive(unsigned long num)
{
	if (num >= 16)
	{
		ft_putptr_recursive(num / 16);
		ft_putptr_recursive(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

void	ft_putptr(void *ptr)
{
	unsigned long	num;

	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return ;
	}
	num = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putptr_recursive(num);
}
