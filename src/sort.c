/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 02:45:17 by emandret          #+#    #+#             */
/*   Updated: 2017/05/13 20:49:42 by emandret         ###   ########.fr       */
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
	t_node	*head;
	int		i = 0; // debug
	int		j = 0; // debug

	while (i < 10)
	{
		head = first;
		j = 0;
		while (j < 10 && head->next)
		{
			printf("\e[93m%p => %s    \e[95mNEXT : %p => %s\n", head, head->filename, head->next, head->next->filename);
			if (ft_strcmp(head->filename, head->next->filename) > 0)
			{
				if (head == first)
				{
					printf("\e[91mSWAP FIRST : %s WITH %s\n", first->filename, first->next->filename);
					ls_swap_first(&first, first->next);
					printf("\e[91mFIRST = %s\n", first->filename);
				}
				else
				{
					printf("\e[92mSWAP NODES : %s WITH %s\n", head->filename, head->next->filename);
					ls_swap_nodes(head, head->next);
				}
			}
			printf("\e[96m%p => %s    \e[93mNEXT : %p => %s\n", head, head->filename, head->next, head->next->filename);
			head = head->next;
			j++; // debug
		}
		printf("\e[91m OUT OF FIRST LOOP\n");
		i++; // debug
	}
	exit(0);
	return (first);
}

/*
** TODO :
** mise a jour du 1er maillon avec swap node lorsqu'on change
** le maillon qui suit celui-ci.
*/
