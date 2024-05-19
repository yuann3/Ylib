/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:04:44 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/19 16:30:54 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstmap_bonus.c

	* @brief Iterates the list 'lst' and applies the function 'f' to the content
	of each element,creating a new list resulting from successive applications
	of 'f'. If 'new' fails,it is taken care of to delete the content of 'new'
	with the function 'del'.
 *
 * @param lst Pointer to the list.
 * @param f Address of the function to apply to the content of the elements.
 * @param del Address of the function used to delete the content of the element.
 * @return t_list* Returns the new list, or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	current = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (new_list);
}
