/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:34:35 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/26 14:10:49 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strmapi.c
 * @brief Converts an integer to a string.
 *
 * @param n The integer.
 * @return char* The string representation of the integer,
	or NULL if an error occurs.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
