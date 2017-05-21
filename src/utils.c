/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:07:04 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 04:38:34 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_bool	ls_is_dotdir(char *dirname)
{
	return ((t_bool)(!ft_strcmp(dirname, ".") || !ft_strcmp(dirname, "..")));
}

t_bool	ls_has_trailing(char *filename, char c)
{
	return ((t_bool)(c == filename[ft_strlen(filename) - 1]));
}

char	*ls_path(char *path, char *dirname)
{
	if (ls_is_dotdir(dirname))
		return (ft_strjoin(dirname, "/"));
	return (ft_strjoin(ft_strjoin(path, dirname), "/"));
}
