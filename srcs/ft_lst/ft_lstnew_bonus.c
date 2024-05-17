/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:15:17 by yiyli             #+#    #+#             */
/*   Updated: 2024/05/17 19:01:12 by yiyli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstnew_bonus.c

	* @brief Allocates and returns a new element. The variable 'content' is
	initialized with the value passed as a parameter. The variable 'next' is
	initialized to NULL.
 *
 * @param content Pointer to the content to be added to the new element.
 * @return t_list* Returns a pointer to the new element,
	or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
