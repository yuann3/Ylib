/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/28 18:01:26 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/01 13:55:28 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_print_format(va_list args, const char **format)
{
	int	result;

	(*format)++;
	result = ft_handle_format(args, **format);
	return (result);
}

static int	ft_parse_format(va_list args, const char *format)
{
	int	total_len;
	int	result;

	total_len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			result = ft_print_format(args, &format);
			if (result == -1)
				return (-1);
			total_len += result;
		}
		else if (*format != '%')
		{
			if (write(1, format, 1) == -1)
				return (-1);
			total_len++;
		}
		format++;
	}
	return (total_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	total_len = ft_parse_format(args, format);
	va_end(args);
	return (total_len);
}
