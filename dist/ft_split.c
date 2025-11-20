/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:46:37 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 15:42:57 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			++str;
		if (*str && !is_sep(*str, charset))
		{
			++count;
			while (*str && !is_sep(*str, charset))
				++str;
		}
	}
	return (count);
}

static char	*dup_word(char *str, int word_len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(word_len + 1);
	if (!dest)
		return (NULL);
	while (i < word_len)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;
	int		word_len;
	int		i;

	words = count_word(str, charset);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && is_sep(*str, charset))
			++str;
		word_len = 0;
		while (str[word_len] && !is_sep(str[word_len], charset))
			++word_len;
		res[i] = dup_word(str, word_len);
		if (!res[i])
			return (NULL);
		i++;
		str += word_len;
	}
	res[i] = NULL;
	return (res);
}
