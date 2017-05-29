/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:24:45 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 05:50:46 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Get the file stats
*/

t_stat	*ls_file_lstat(char *path, char *filename)
{
	t_stat	*stats;

	if (!(stats = (t_stat*)ft_memalloc(sizeof(t_stat))))
		return (NULL);
	if (!lstat(ft_strjoin(path, filename), stats))
		return (stats);
	ls_error(filename);
	return (NULL);
}

/*
** Get the target of a link
*/

void	ls_link_target(char *path, t_node *node)
{
	ssize_t	ret;

	if ((ret = readlink(ft_strjoin(path, node->filename), node->target, 255))
		!= -1)
		node->target[ret] = '\0';
	else
		ls_error(node->filename);
}

/*
** Get the user and group structures
*/

t_bool	ls_user_infos(t_node *node)
{
	if ((node->user = getpwuid(node->stats->st_uid)) &&
		(node->group = getgrgid(node->stats->st_gid)))
		return (TRUE);
	return (FALSE);
}
