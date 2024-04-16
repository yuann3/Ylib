/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:40:46 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/16 19:42:50 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

int	count_words(char const *str, char charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
			count++;
		while (*str && !is_charset(*str, charset))
			str++;
	}
	return (count);
}

char	*malloc_word(char const *str, char charset)
{
	char	*word;
	int		len;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len] && !is_charset(str[len], charset))
	{
		word[len] = str[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

/**
 * @brief Splits a string into words by a charset.
 *
 * @param str The string to split.
 * @param charset Delimiter for splitting.
 * @return Array of words.
 *
 * Allocates memory for an array of words. Iterates over the string,
   skipping charset characters and allocating memory for new words.
   The last array element is NULL. Returns the array.
 */
char	**ft_split(char const *str, char charset)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			arr[i] = malloc_word(str, charset);
			i++;
		}
		while (*str && !is_charset(*str, charset))
			str++;
	}
	arr[i] = 0;
	return (arr);
}
