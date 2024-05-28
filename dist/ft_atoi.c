/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:53:51 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/28 23:40:14 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief String to integer converter.
 */
#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
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
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = (*str - '0') + (result * 10);
		str++;
	}
	return (sign * result);
}
