/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:15:09 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 19:18:06 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isalpha.c
 * @brief Checks if the character is an alphabet.
 * @param c Character to check.
 * @return 1 if c is an alphabet, 0 otherwise.
 *
 * The function checks if the passed character is either an
 * uppercase or lowercase alphabet. If it is, the function
 * returns 1. If not, it returns 0.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
