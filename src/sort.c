/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 02:45:17 by emandret          #+#    #+#             */
/*   Updated: 2017/05/13 03:35:16 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_bool	ls_check_node(t_node *node)
{
	return ((t_bool)(node && node->prev && node->next));
}

void	ls_swap_first(t_node **first, t_node *n2)
{
	t_node	*tmp_next;

	if ((*first)->next && ls_check_node(n2))
	{
		n2->prev->next = *first;
		n2->next->prev = *first;
		(*first)->next->prev = n2;
		(*first)->prev = n2->prev;
		tmp_next = (*first)->next;
		(*first)->next = n2->next;
		n2->next = tmp_next;
		n2->prev = NULL;
		*first = n2;
	}
}

void	ls_swap_nodes(t_node *n1, t_node *n2)
{
	t_node	*tmp_prev;
	t_node	*tmp_next;

	if (ls_check_node(n1) && ls_check_node(n2))
	{
		n1->prev->next = n2;
		n2->prev->next = n1;
		n1->next->prev = n2;
		n2->next->prev = n1;
		tmp_prev = n1->prev;
		n1->prev = n2->prev;
		n2->prev = tmp_prev;
		tmp_next = n1->next;
		n1->next = n2->next;
		n2->next = tmp_next;
	}
}

t_node	*ls_sort_alpha(t_node *first)
{
	return (first);
}
