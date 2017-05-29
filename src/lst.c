/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 08:55:11 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 11:24:09 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Order the linked list using the sorting functions
*/

void	ls_lst_order(t_opts *opts, t_node **first)
{
	ls_lst_sort(first, &ls_sort_lexi);
	if (opts->t)
		ls_lst_sort(first, &ls_sort_time);
	if (opts->r)
		ls_lst_revr(first);
}

/*
** Free the entire list
*/

void	ls_lst_free(t_node *first)
{
	t_node	*head;

	head = first;
	while (head)
	{
		head = head->next;
		ls_free_node(head);
	}
}

/*
** Count the number of nodes in the linked list
*/

int		ls_lst_size(t_node *first)
{
	int	size;

	if (!first)
		return (0);
	size = 1;
	while ((first = first->next))
		size++;
	return (size);
}

/*
** Count the numbers of directories. Symlinks are considered as directories
*/

int		ls_lst_dirs(t_opts *opts, t_node *first)
{
	int	count;

	count = 0;
	while (first)
	{
		if (IS_DIRLNK(first, opts))
			count++;
		first = first->next;
	}
	return (count);
}
