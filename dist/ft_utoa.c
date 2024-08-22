/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:52:22 by yiyli             #+#    #+#             */
/*   Updated: 2024/06/09 11:44:37 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * get_digit_count
	- a function that counts the number of digits in an unsigned integer.
 * @param n: The unsigned integer whose digits are to be counted.
 * @return: The count of digits in the input number. If the number is 0,
	it returns 1.
 */
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

/**
 * ft_utoa - a function that converts an unsigned integer to a string.
 * @param n: The unsigned integer to be converted.

	* @return: A pointer to the resulting null-terminated string.
   Returns NULL if the allocation fails.
 */
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
