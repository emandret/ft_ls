/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:55:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/12 17:26:30 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Create a new node based on the filename
*/

t_node	*ls_new_node(char *filename, t_node *prev)
{
	t_node	*new_node;

	if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_node->filename = filename;
	if (!(new_node->stats = ls_file_lstat(filename)))
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

t_node	*ls_add_node(char *filename, t_node *first)
{
	t_node	*cur_node;

	if (!first)
		return (ls_new_node(filename, NULL));
	cur_node = first;
	while (cur_node->next)
		cur_node = cur_node->next;
	cur_node->next = ls_new_node(filename, cur_node);
	return (first);
}
