/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:44:37 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/03 11:01:54 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		if (del != NULL)
			del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
