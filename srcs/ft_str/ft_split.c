/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:45 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/31 20:21:46 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_split(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	len = 0;
	while (s[len] && len < n)
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len] && len < n)
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	free_strs(char **strs, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word_count;
	int		i;

	word_count = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		strs[i] = ft_strndup_split(s, get_word_len(s, c));
		if (!strs[i])
		{
			free_strs(strs, i);
			return (NULL);
		}
		strs[i][get_word_len(s, c)] = '\0';
		s += get_word_len(s, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
