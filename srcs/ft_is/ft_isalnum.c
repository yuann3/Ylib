/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:05:19 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:05:22 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isalnum.c
 * @brief Checks if the character is alphanumeric.
 * @param c Character to check.
 * @return 1 if c is alphanumeric, 0 otherwise.
 *
 * The function checks if the passed character is either an
 * uppercase or lowercase alphabet, or a digit. If it is,
 * the function returns 1. If not, it returns 0.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
