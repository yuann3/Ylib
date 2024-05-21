/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:48:49 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/21 15:52:01 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of digits in an integer.
 *
 * @param n The integer.
 * @return int The number of digits in the integer.
 */
static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, int n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

/**
 * @file ft_itoa.c
 * @brief Converts an integer to a string.
 *
 * @param n The integer.
 * @return char* The string representation of the integer,
	or NULL if an error occurs.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	fill_str(str, n, len);
	return (str);
}
