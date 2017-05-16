/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 04:14:52 by emandret          #+#    #+#             */
/*   Updated: 2017/05/16 04:43:59 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_swap_detached(t_node *n1, t_node *n2)
{
	t_node	*tmp_prev;
	t_node	*tmp_next;

	if (n1->prev)
		n1->prev->next = n2;
	if (n2->prev)
		n2->prev->next = n1;
	if (n1->next)
		n1->next->prev = n2;
	if (n2->next)
		n2->next->prev = n1;
	tmp_prev = n1->prev;
	n1->prev = n2->prev;
	n2->prev = tmp_prev;
	tmp_next = n1->next;
	n1->next = n2->next;
	n2->next = tmp_next;
}

void	ls_swap_attached(t_node *n1, t_node *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

void	ls_swap_nodes(t_node *n1, t_node *n2)
{
	if ((n1->next == n2 && n2->prev == n1) ||
		(n2->next == n1 && n1->prev == n2))
		ls_swap_attached(n1, n2);
	else
		ls_swap_detached(n1, n2);
}

t_bool	ls_swap_first(t_node **first, t_node *n1, t_node *n2)
{
	t_bool	ret;

	ret = FALSE;
	if (n1 == *first || n2 == *first)
	{
		if (n1 == *first)
			*first = n2;
		else if (n2 == *first)
			*first = n1;
		ret = TRUE;
	}
	ls_swap_nodes(n1, n2);
	return (ret);
}
