/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:33:20 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 19:36:38 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isascii.c
 * @brief Checks if the character is an ASCII character.
 * @param c Character to check.
 * @return 1 if c is an ASCII character, 0 otherwise.
 * 
 * The function checks if the passed character is in the ASCII
 * range (between 0 and 127). If it is, the function returns 1.
 * If not, it returns 0.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
