/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:35:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/27 07:34:33 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_print_files(t_opts *opts, t_node *list, t_print print_opts)
{
	while (list)
	{
		if ((print_opts == S_ALL) ||
			(print_opts == S_NOT_DIRLNK && !IS_DIRLNK(list, opts)) ||
			(print_opts == S_NOT_HIDDEN && !IS_HIDDEN(list->filename)))
			ft_putendl(list->filename);
		list = list->next;
	}
}
