/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/17 20:08:21 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/17 20:08:22 by yiyuli         ###      ########.fr      */
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
