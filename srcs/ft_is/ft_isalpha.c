/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:07:39 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:07:42 by yiyuli         ###      ########.fr      */
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
