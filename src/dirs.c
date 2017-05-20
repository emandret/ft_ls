/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 01:23:53 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_bool			ls_is_dotdir(char *dirname)
{
	return ((t_bool)(!ft_strcmp(dirname, ".") || !ft_strcmp(dirname, "..")));
}

char			*ls_dirpath(char *path, char *dirname)
{
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	return (ft_strjoin(ft_strjoin(path, dirname), "/"));
}

int				ls_probe_dir(t_opts *opts, char *path, char *dirname)
{
	DIR		*stream;
	t_node	*list;

	if (!(stream = opendir((path = ls_dirpath(path, dirname)))))
	{
		ls_error(dirname);
		return (OPEN_FAILURE);
	}
	list = ls_open_dir(stream, opts, path);
	ls_debug_list_short(list);
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
	return (list);
}
