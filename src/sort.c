/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 02:45:17 by emandret          #+#    #+#             */
/*   Updated: 2017/05/16 05:13:06 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Bubble sort test implementation
*/

t_node	*ls_sort_alpha(t_node *first)
{
	t_bool	sorted;
	t_node	*head;

	sorted = FALSE;
	while (!sorted)
	{
		sorted = TRUE;
		head = first;
		while (head->next)
		{
			if (ft_strcmp(head->filename, head->next->filename) > 0)
			{
				if (ls_swap_first(&first, head, head->next))
					head = first;
				sorted = FALSE;
			}
			else
				head = head->next;
		}
	}
	return (first);
}
