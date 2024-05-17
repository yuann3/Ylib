/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:44:37 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/17 18:54:45 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstclear_bonus.c

	* @brief Deletes and frees the given element and every successor of that
	element, using the function 'del' and free(3). Finally,
	the pointer to the list is set to NULL.
 *
 * @param lst Double pointer to the list.
 * @param del Address of the function used to delete the content of the element.
 */
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
