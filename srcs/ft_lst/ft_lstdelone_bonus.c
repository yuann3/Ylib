/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/20 14:49:34 by yiyuli           #+#      #+#            */
/*   Updated: 2025/11/20 14:49:37 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
