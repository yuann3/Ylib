/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:03:35 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/16 16:12:27 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @file ft_toupper.c
 * @brief Converts a lowercase letter to uppercase.
 */

/**
 * @brief Converts a lowercase letter to uppercase.
 * 
 * @param c The character to convert.
 * @return The converted character. If the input character is a lowercase letter (ASCII 97-122), it is converted to uppercase by subtracting 32 from its ASCII value. If the input character is not a lowercase letter, it is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}
