/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/01 13:17:39 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/01 13:27:51 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_hex_rec(unsigned int n, char *base)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 16)
	{
		check = print_hex_rec(n / 16, base);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase == 1)
		return (print_hex_rec(n, "0123456789ABCDEF"));
	else
		return (print_hex_rec(n, "0123456789abcdef"));
}
