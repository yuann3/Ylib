/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:42:58 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/17 19:45:49 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isprint.c
 * @brief Checks if the character is printable.
 * @param c Character to check.
 * @return 1 if c is a printable character, 0 otherwise.
 *
 * The function checks if the passed character is a printable
 * ASCII character (between 32 and 126). If it is, the function
 * returns 1. If not, it returns 0.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
