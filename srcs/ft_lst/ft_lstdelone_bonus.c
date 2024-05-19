/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:52:20 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/19 16:35:42 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstdelone_bonus.c
 * @brief Deletes and frees the given element and its content using the function
 * 'del' and free. Finally, the pointer to the element is set to NULL.
 *
 * @param lst Pointer to the element to be deleted.
 * @param del Address of the function to delete the content of the element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
