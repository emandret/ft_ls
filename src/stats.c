/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:24:45 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 19:59:34 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Obtains information about the file pointed by the full path using lstat(2)
*/

t_bool	ls_file_lstats(char *fpath, t_node *node)
{
	if (!(node->stats = (t_stat*)ft_memalloc(sizeof(t_stat))))
		return (FALSE);
	if (lstat(fpath, node->stats) == -1)
		return (FALSE);
	return (TRUE);
}

/*
** Set all the supported file types in UNIX
*/

t_bool	ls_file_types(t_node *node)
{
	if (!(node->type = ls_get_type(node->stats->st_mode)))
		return (FALSE);
	return (TRUE);
}

/*
** Set the target (pointed file) of symbolic link (symlink)
*/

t_bool	ls_link_target(char *fpath, t_node *node)
{
	ssize_t	ret;

	if (node->type == 'l')
	{
		if ((ret = readlink(fpath, node->target, TARGET_SIZE)) == -1)
			return (FALSE);
		node->target[ret] = '\0';
	}
	return (TRUE);
}

/*
** Set the user and group informations for a given file (node)
*/

t_bool	ls_user_infos(t_node *node)
{
	if (!(node->user = getpwuid(node->stats->st_uid)))
		return (FALSE);
	if (!(node->group = getgrgid(node->stats->st_gid)))
		return (FALSE);
	return (TRUE);
}
