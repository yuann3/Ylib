/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:48:49 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/26 14:04:43 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_ifnegative(int *n, char *str)
{
	if (*n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		*n = 147483648;
	}
	else if (*n < 0)
	{
		str[0] = '-';
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_ifnegative(&n, str);
	while (n != 0)
	{
		str[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (str);
}
