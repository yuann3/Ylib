/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:29:45 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/22 20:52:00 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putstr_fd.c
 * @brief Writes a string to a given file descriptor.
 * 
 * @param s The string to be written.
 * @param fd The file descriptor to write to.
 */
void	ft_putstr_fd(char *s, int fd)
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
}
