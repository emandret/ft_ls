/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 07:51:14 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Set the new path and append a trailing slash
*/

static char		*set_path(char *path, char *dirname)
{
	if (IS_DOTDIR(dirname))
		return (ft_strjoin(dirname, "/"));
	return (ft_strjoin(ft_strjoin(path, dirname), "/"));
}

/*
** Explore a directory stream using readdir(3) and place the content in a linked
** list. Return the first node of the newly created list
*/

t_node			*ls_open_dir(DIR *stream, t_opts *opts, char *path)
{
	t_dir	*dirent;
	t_node	*first;

	first = NULL;
	while ((dirent = readdir(stream)))
		first = ls_add_node(path, dirent->d_name, first);
	ls_lst_order(opts, &first);
	return (first);
}

/*
** Open a directory using opendir(3). Print the content of the opened directory.
** Use recursion to explore nested directories.
*/

int				ls_probe_dir(t_opts *opts, char *path, char *dirname)
{
	DIR		*stream;
	t_node	*first;
	t_node	*head;

	if (!(stream = opendir((path = set_path(path, dirname)))))
	{
		ls_error(dirname);
		return (-1);
	}
	if ((first = ls_open_dir(stream, opts, path)))
	{
		if (opts->path || (opts->path && opts->R))
		{
			if (opts->endl)
				ft_putchar('\n');
			ft_printf("\e[92m%.*s:\e[39m\n", ft_strlen(path) - 1, path);
		}
		opts->endl = TRUE;
		opts->path = TRUE;
		ls_print(opts, first, TRUE);
		head = first;
		while (head)
		{
			if (opts->R && head->types->is_dir && !IS_DOTDIR(head->filename) &&
				(!IS_HIDDEN(head->filename) || opts->a))
				ls_probe_dir(opts, path, head->filename);
			head = head->next;
		}
	}
	// free memory here
	closedir(stream);
	return (0);
}
