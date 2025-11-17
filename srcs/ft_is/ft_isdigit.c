/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:08:08 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:08:09 by yiyuli         ###      ########.fr      */
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
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}
