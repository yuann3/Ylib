/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:55:08 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:55:09 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_char_or_percent(va_list args, char format)
{
	char	c;

	if (format == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		c = (char)va_arg(args, int);
		ft_putchar(c);
		return (1);
	}
}

static int	print_string_or_pointer(va_list args, char format)
{
	char	*str;
	void	*ptr;
	int		len;

	len = 0;
	if (format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		ft_putstr(str);
		len = ft_strlen(str);
	}
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		ft_putptr(ptr);
		len = ft_ptrlen(ptr);
	}
	return (len);
}

static int	print_numeric(va_list args, char format)
{
	char	*str;
	int		len;

	if (format == 'd' || format == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (format == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else
		str = ft_xtoa(va_arg(args, unsigned int), format == 'X');
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int	print_arg(const char *format, va_list args)
{
	if (*format == 'c' || *format == '%')
		return (print_char_or_percent(args, *format));
	else if (*format == 's' || *format == 'p')
		return (print_string_or_pointer(args, *format));
	else
		return (print_numeric(args, *format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		char_len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char_len = print_arg(format, args);
			len += char_len;
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
