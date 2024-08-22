/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <lyiyuane@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:30:19 by yiyli             #+#    #+#             */
/*   Updated: 2024/06/28 10:30:22 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(void *ptr)
{
	unsigned long	num;
	int				len;

	if (ptr == NULL)
		return (5);
	num = (unsigned long)ptr;
	len = 2;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
