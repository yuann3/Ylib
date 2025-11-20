/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 15:15:55 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:16:07 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else
	{
		while (n != 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	int		digit_count;
	char	*result;

	digit_count = get_digit_count(n);
	result = (char *)malloc(sizeof(char) * (digit_count + 1));
	if (!result)
		return (NULL);
	result[digit_count] = '\0';
	while (digit_count > 0)
	{
		digit_count--;
		result[digit_count] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
