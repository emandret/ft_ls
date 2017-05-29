/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:55:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 07:47:18 by emandret         ###   ########.fr       */
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
** Order the linked list using the sorting functions
*/

void			ls_lst_order(t_opts *opts, t_node **first)
{
	ls_lst_sort(first, &ls_sort_lexi);
	if (opts->t)
		ls_lst_sort(first, &ls_sort_time);
	if (opts->r)
		ls_lst_revr(first);
}

/*
** Count the number of nodes in the linked list
*/

int				ls_lst_size(t_node *first)
{
	int	size;

	size = 0;
	while ((first = first->next))
		size++;
	return (size);
}

/*
** Count the numbers of directories. Symlinks are considered as directories
*/

int				ls_lst_dirs(t_opts *opts, t_node *first)
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
