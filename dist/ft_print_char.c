/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/29 16:09:58 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/29 16:12:59 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int character)
{
	char	to_print;

	to_print = (char)character;
	if (write(1, &to_print, 1) == -1)
		return (-1);
	return (1);
}
