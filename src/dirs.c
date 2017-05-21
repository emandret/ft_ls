/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 04:55:55 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int				ls_probe_dir(t_opts *opts, char *path, char *dirname)
{
	DIR		*stream;
	t_node	*list;
	t_node	*head;

	if (!(stream = opendir((path = ls_path(path, dirname)))))
	{
		ls_error(dirname);
		return (OPEN_FAILURE);
	}
	if ((list = ls_open_dir(stream, opts, path)))
	{
		head = list;
		while (head)
		{
			if (opts->opt_R && head->is_dir && !ls_is_dotdir(head->filename))
				ls_probe_dir(opts, path, head->filename);
			head = head->next;
		}
		/* debug */
		printf("%s:\n", path); // if a directory node and another node (2 nodes including 1 dir)
		ls_debug_list_short(list);
		printf("\n\n");
		/* end debug */
	}
	closedir(stream);
	return (OPEN_SUCCESS);
}

t_node			*ls_open_dir(DIR *stream, t_opts *opts, char *path)
{
	t_dir	*dirent;
	t_node	*list;

	list = NULL;
	while ((dirent = readdir(stream)))
		list = ls_add_node(path, dirent->d_name, list);
	ls_sort_list(&list, &ls_sort_lexi);
	if (opts->opt_t)
		ls_sort_list(&list, &ls_sort_time);
	return (list); // si -R, reverse la liste
}
