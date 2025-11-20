/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:56:26 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:56:28 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, uppercase);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n]);
}
