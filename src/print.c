/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:35:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/27 11:00:49 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	print(t_node *node)
{
	if (node->is_dir)
		ft_printf("\e[96m%s\e[39m\n", node->filename);
	else if (node->is_lnk)
		ft_printf("\e[35m%s\e[39m\n", node->filename);
	else
		ft_printf("%s\n", node->filename);
}

void	ls_print(t_opts *opts, t_node *list)
{
	while (list)
	{
		if (!IS_HIDDEN(list->filename) || opts->a)
			print(list);
		list = list->next;
	}
}

void	ls_print_file(t_opts *opts, t_node *list)
{
	while (list)
	{
		if (!IS_DIRLNK(list, opts))
			print(list);
		list = list->next;
	}
}
