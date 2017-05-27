/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/27 07:44:52 by emandret         ###   ########.fr       */
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
		if (opts->path || (opts->path && opts->R))
		{
			if (opts->endl)
				ft_putchar('\n');
			ft_printf("\e[92m%s:\e[39m\n", path);
		}
		opts->endl = TRUE;
		opts->path = TRUE;
		ls_print_files(opts, list, S_NOT_HIDDEN);
		head = list;
		while (head)
		{
			if (opts->R && head->is_dir && !IS_DOTDIR(head->filename))
				ls_probe_dir(opts, path, head->filename);
			head = head->next;
		}
	}
	// free memory here
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
	ls_reorder_list(opts, &list);
	return (list);
}
