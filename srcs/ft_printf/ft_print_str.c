/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/29 16:16:56 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/29 16:25:09 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (write(1, str, length) == -1)
		return (-1);
	return (length);
}
