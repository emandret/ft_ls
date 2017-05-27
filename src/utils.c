/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:07:04 by emandret          #+#    #+#             */
/*   Updated: 2017/05/27 07:45:10 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ls_list_size(t_node *first)
{
	int	size;

	size = 0;
	while (first)
	{
		size++;
		first = first->next;
	}
	return (size);
}

int		ls_count_dir(t_opts *opts, t_node *first)
{
	int	count;

	count = 0;
	while (first)
	{
		if (IS_DIRLNK(first, opts))
			count++;
		first = first->next;
	}
	return (count);
}

char	*ls_path(char *path, char *dirname)
{
	if (IS_DOTDIR(dirname))
		return (ft_strjoin(dirname, "/"));
	return (ft_strjoin(ft_strjoin(path, dirname), "/"));
}
