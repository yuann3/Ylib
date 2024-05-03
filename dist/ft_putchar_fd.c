/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:57:56 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/18 22:59:37 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putchar_fd.c
 * @brief Writes a character to a file descriptor.
 * @param c Character to write.
 * @param fd File descriptor to write to.
 * 
 * The function writes the character c to the file descriptor fd.
 * The write function is used to write the character to the file.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
