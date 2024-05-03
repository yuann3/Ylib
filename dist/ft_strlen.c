/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:40:03 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/16 17:33:18 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @brief String length calculator.
 */
#include "libft.h"

/**
 * @brief Calculates string length.
 *
 * @param s Input string.
 * @return Length of string. Iterates over string until null character.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
