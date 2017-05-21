/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:24:45 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 04:33:30 by emandret         ###   ########.fr       */
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
