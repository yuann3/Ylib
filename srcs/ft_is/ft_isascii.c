/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:07:51 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:07:52 by yiyuli         ###      ########.fr      */
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
	return (c >= 0 && c <= 127);
}
