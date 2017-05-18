/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:55:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/18 05:11:19 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Create a new node based on the filename
*/

t_node	*ls_new_node(char *path, char *filename, t_node *prev)
{
	t_node	*new_node;

	if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_node->filename = filename;
	if (!(new_node->stats = ls_file_lstat(path, filename)))
		return (NULL);
	if (S_ISDIR(new_node->stats->st_mode))
		new_node->is_dir = TRUE;
	if (S_ISLNK(new_node->stats->st_mode))
		new_node->is_lnk = TRUE;
	new_node->prev = prev;
	new_node->next = NULL;
	return (new_node);
}

/*
** Add a node to the directory content list
*/

t_node	*ls_add_node(char *path, char *filename, t_node *first)
{
	t_node	*last;

	if (!first)
		return (ls_new_node(path, filename, NULL));
	last = ls_get_last(first);
	last->next = ls_new_node(path, filename, last);
	return (first);
}

/*
** Get the last node
*/

t_node	*ls_get_last(t_node *first)
{
	t_node	*head;

	head = first;
	while (head->next)
		head = head->next;
	return (head);
}
