/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 02:45:17 by emandret          #+#    #+#             */
/*   Updated: 2017/05/11 18:12:54 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"


t_node	*ls_swap_first(t_node *first)
{
	t_node	*head;
	t_node	*next;

	if (first && first->next)
	{
		next = first->next->next;
		first->next->next = first;
		head = first->next;
		first->next = next;
		return (head);
	}
	return (first);
}

void	ls_swap_nodes(t_node *first, t_node *n1, t_node *n2)
{
	t_node	*next;

	if (first && first->next == n1)
	{
		next = n2->next;
		first->next = n2;
		n2->next = n1;
		n1->next = next;
	}
	else
		ls_swap_nodes(first->next, n1, n2);
}

t_node	*ls_sort_alpha(t_node *first)
{
	if (ft_strcmp(first->filename, first->next->filename) < 0)
		return (ls_swap_first(first));
	return (first);
}
