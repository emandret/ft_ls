/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:37:55 by emandret          #+#    #+#             */
/*   Updated: 2016/11/25 20:56:12 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = NULL;
	if (lst)
	{
		result = f(lst);
		if ((first_node = ft_lstnew(result->content, result->content_size)))
		{
			current_node = first_node;
			while ((lst = lst->next))
			{
				result = f(lst);
				if (!(current_node->next =
					ft_lstnew(result->content, result->content_size)))
					return (NULL);
				current_node = current_node->next;
			}
		}
	}
	return (first_node);
}
