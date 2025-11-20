/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 15:16:24 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:16:25 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexadecimal_digit_count(unsigned long num)
{
	int	count;

	count = 0;
	if (num == 0)
		count = 1;
	else
	{
		while (num != 0)
		{
			num /= 16;
			count++;
		}
	}
	return (count);
}

char	*ft_xtoa(unsigned long num, int is_upper)
{
	static const char	digits_lower[] = "0123456789abcdef";
	static const char	digits_upper[] = "0123456789ABCDEF";
	const char			*digit_set;
	int					digit_count;
	char				*hex_str;

	digit_count = hexadecimal_digit_count(num);
	hex_str = malloc(digit_count + 1);
	if (!hex_str)
		return (NULL);
	if (is_upper)
		digit_set = digits_upper;
	else
		digit_set = digits_lower;
	hex_str[digit_count] = '\0';
	while (digit_count > 0)
	{
		digit_count--;
		hex_str[digit_count] = digit_set[num % 16];
		num /= 16;
	}
	return (hex_str);
}
