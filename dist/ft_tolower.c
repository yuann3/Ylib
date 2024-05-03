/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:29:28 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/16 17:30:21 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Converts an uppercase letter to lowercase.
 */
#include "libft.h"

/**
 * @brief Converts an uppercase letter to lowercase.
 * 
 * @param c The character to convert.
 * @return The converted character. If the input character is an 
 * uppercase letter ASCII 65-90), it is converted to lowercase by a
 * dding 32 to its ASCII value. If the input character is not an 
 uppercase letter, it is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
