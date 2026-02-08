/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_hashmap_internal.h                             :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2026/02/08 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2026/02/08 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_INTERNAL_H
# define FT_HASHMAP_INTERNAL_H

# include "libft.h"

typedef struct s_hashmap_entry
{
	char	*key;
	void	*value;
}	t_hashmap_entry;

int	ft_hashmap_grow(t_hashmap *map);

#endif
