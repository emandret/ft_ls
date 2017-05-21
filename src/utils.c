/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:07:04 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 17:55:25 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ls_path(char *path, char *dirname)
{
	if (IS_DOTDIR(dirname))
		return (ft_strjoin(dirname, "/"));
	return (ft_strjoin(ft_strjoin(path, dirname), "/"));
}
