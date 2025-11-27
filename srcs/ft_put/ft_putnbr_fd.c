/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:56:36 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/27 22:39:11 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_recursive(long nb, int fd)
{
	char	c;

	if (nb >= 10)
		print_recursive(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	print_recursive(nb, fd);
}
