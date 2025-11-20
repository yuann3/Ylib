/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:09:28 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:20:27 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

/**
 * @brief Converts string to integer.
 *
 * @param str Input string.
 * @return Integer representation of string.
 *
 * Skips leading whitespace, checks for sign,
 * and converts digits to integer.
 */
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+' )
	{
	if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}
