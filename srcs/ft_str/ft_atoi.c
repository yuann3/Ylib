/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:53:51 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/16 20:18:41 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief String to integer converter.
 */
#include "libft.h"

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
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (sign * result);
}
