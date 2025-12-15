/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/29 23:14:41 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/29 23:37:52 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_recursive(unsigned long n)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 16)
	{
		check = ft_putptr_recursive(n / 16);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_putptr_recursive((unsigned long)ptr);
	if (len == -1)
		return (-1);
	return (len + 2);
}
