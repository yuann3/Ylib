/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:51 by yiyli             #+#    #+#             */
/*   Updated: 2024/04/24 17:22:20 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret = &((char *)str)[i];
		i++;
	}
	if (c == '\0')
		ret = &((char *)str)[i];
	return (ret);
}
