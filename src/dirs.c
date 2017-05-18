/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:13 by emandret          #+#    #+#             */
/*   Updated: 2017/05/18 18:52:07 by emandret         ###   ########.fr       */
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

t_node			*ls_open_dir(t_opts *opts, char *path, char *dirname)
{
	DIR		*stream;
	t_dir	*dirent;
	t_node	*first;

	path = ls_dirpath(path, dirname);
	if (!(stream = opendir(path)))
	{
		ls_error(dirname);
		return (NULL);
	}
	first = NULL;
	while ((dirent = readdir(stream)))
		first = ls_add_node(path, dirent->d_name, first);
	ls_sort_list(&first, &ls_sort_lexi);
	if (opts->opt_t)
		ls_sort_list(&first, &ls_sort_time);
	return (first);
}
