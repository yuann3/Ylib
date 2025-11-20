/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:56:43 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:56:44 by yiyuli         ###      ########.fr      */
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
