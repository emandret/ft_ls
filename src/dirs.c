/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 05:35:39 by emandret         ###   ########.fr       */
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
		return (-1);
	}
	if ((list = ls_open_dir(stream, opts, path)))
	{
		if (opts->path || (opts->path && opts->R))
		{
			if (opts->endl)
				ft_putchar('\n');
			ft_printf("\e[92m%.*s:\e[39m\n", ft_strlen(path) - 1, path);
		}
		opts->endl = TRUE;
		opts->path = TRUE;
		ls_print(opts, list);
		head = list;
		while (head)
		{
			if (opts->R && head->is_dir && !IS_DOTDIR(head->filename) &&
				(!IS_HIDDEN(head->filename) || opts->a))
				ls_probe_dir(opts, path, head->filename);
			head = head->next;
		}
	}
	// free memory here
	closedir(stream);
	return (0);
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
