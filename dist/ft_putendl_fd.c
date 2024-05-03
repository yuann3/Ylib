/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:49:21 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/22 20:50:48 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putendl_fd.c
 * @brief Writes a string to a given file descriptor, followed by a newline.
 * 
 * @param s The string to be written.
 * @param fd The file descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return ;
	while (s[len] != '\0')
	{
		write(fd, &s[len], 1);
		len++;
	}
	write(fd, "\n", 1);
}
