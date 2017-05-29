/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:55:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 09:03:12 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Create a new node and populates it with the required informations
*/

static t_node	*ls_new_node(char *path, char *filename, t_node *prev)
{
	t_node	*new_node;
	char	*fpath;

	if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_node->filename = ft_strdup(filename);
	fpath = ft_strjoin(path, filename);
	if (!ls_file_lstats(fpath, new_node) || !ls_file_types(new_node) ||
		!ls_link_target(fpath, new_node) || !ls_user_infos(new_node))
	{
		ls_error(filename);
		return (NULL);
	}
	new_node->prev = prev;
	return (new_node);
}

/*
** Add a new node to the linked list, if `first' equal to NULL, return a new node
*/

t_node			*ls_add_node(char *path, char *filename, t_node *first)
{
	t_node	*last;

	if (!first)
		return (ls_new_node(path, filename, NULL));
	last = first;
	while (last->next)
		last = last->next;
	last->next = ls_new_node(path, filename, last);
	return (first);
}

/*
** Free a node
*/

void			ls_free_node(t_node *node)
{
	if (node)
	{
		ft_memdel((void**)&node->filename);
		ft_memdel((void**)&node->stats);
		ft_memdel((void**)&node->types);
		ft_memdel((void**)&node);
	}
}
