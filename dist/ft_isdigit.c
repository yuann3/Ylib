/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:19:41 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 19:36:00 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isdigit.c
 * @brief Checks if the character is alphanumeric.
 * @param c Character to check.
 * @return 1 if c is alphanumeric, 0 otherwise.
 * 
 * The function checks if the passed character is either an
 * uppercase or lowercase alphabet, or a digit. If it is,
 * the function returns 1. If not, it returns 0.
 */
int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}
