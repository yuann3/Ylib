/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:06:25 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/27 22:19:01 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strchr.c
 * @brief Locates the first occurrence of c in string s.
 * @param s String to be scanned.
 * @param c Character to be located.
 * @return Pointer to the first occurrence of c in s, or NULL.
 *
 * The search includes the terminating null character. If c is
 * found, a pointer to c in s is returned. If c is not found,
 * the function returns NULL.
 */
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
