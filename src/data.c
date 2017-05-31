/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:11:19 by emandret          #+#    #+#             */
/*   Updated: 2017/05/31 23:26:54 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Return the corresponding character of a supported file type in UNIX. Return a
** NULL character if the file type is not supported
*/

static char		get_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISSOCK(mode))
		return ('s');
	return ('\0');
}

/*
** Obtains informations about the pointed file in case of a symbolic link
*/

static t_bool	link_data(char *fpath, t_node *node)
{
	ssize_t	ret;
	t_stat	*st;

	if (!(st = (t_stat*)ft_memalloc(sizeof(t_stat))))
		return (FALSE);
	if ((ret = readlink(fpath, node->target, 255)) == -1)
		return (FALSE);
	node->target[ret] = '\0';
	if (ft_strcmp(node->filename, node->target))
	{
		if (stat(fpath, st) == -1)
			return (FALSE);
		if (!(node->target_type = get_type(st->st_mode)))
			return (FALSE);
	}
	return (TRUE);
}

/*
** Obtains information about the file located at `fpath' using lstat(2) and fill
** the node
*/

t_bool			ls_node_data(char *fpath, t_node *node)
{
	if (!(node->stat = (t_stat*)ft_memalloc(sizeof(t_stat))))
		return (FALSE);
	if (lstat(fpath, node->stat) == -1)
		return (FALSE);
	if (!(node->type = get_type(node->stat->st_mode)))
		return (FALSE);
	if ('l' == node->type && !link_data(fpath, node))
		return (FALSE);
	if (!(node->user = getpwuid(node->stat->st_uid)))
		return (FALSE);
	if (!(node->group = getgrgid(node->stat->st_gid)))
		return (FALSE);
	return (TRUE);
}
