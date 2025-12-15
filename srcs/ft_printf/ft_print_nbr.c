/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/29 23:44:17 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/30 00:30:18 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_recursive(unsigned int number)
{
	int	length;
	int	check_error;

	length = 0;
	if (number >= 10)
	{
		check_error = print_recursive(number / 10);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (length + 1);
}

int	ft_print_unsigned(unsigned int number)
{
	return (print_recursive(number));
}

int	ft_print_nbr(int number)
{
	int				length;
	int				check_error;
	unsigned int	unsigned_num;

	length = 0;
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		length++;
		unsigned_num = -(unsigned int)number;
	}
	else
		unsigned_num = (unsigned int)number;
	check_error = print_recursive(unsigned_num);
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}
