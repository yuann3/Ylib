/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:34:35 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/27 21:38:35 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strmapi.c
 * @brief Applies a function to each character of a string,
	creating a new string.
 *
 * @param s The original string.
 * @param f The function to apply to each character.
 * @return char* The new string resulting from successive applications of 'f',
	or NULL if an error occurs.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_new;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	str_new = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str_new == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
