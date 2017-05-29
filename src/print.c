/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:35:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 22:13:15 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Print using colors for the file types
*/

static void	color_print(t_node *node)
{
	if (node->type == '-')
		ft_printf("%s\n", node->filename);
	else if (node->type == 'd')
		ft_printf("\e[1m\e[96m%s\e[39m\e[0m\n", node->filename);
	else if (node->type == 'l')
		ft_printf("\e[35m%s\e[39m\n", node->filename);
	else if (node->type == 'c')
		ft_printf("\e[43m\e[34m%s\e[39m\e[49m\n", node->filename);
	else if (node->type == 'b')
		ft_printf("\e[46m\e[34m%s\e[39m\e[49m\n", node->filename);
	else if (node->type == 'p')
		ft_printf("\e[33m%s\e[39m\n", node->filename);
	else if (node->type == 's')
		ft_printf("\e[32m%s\e[39m\n", node->filename);
}

/*
** Print the filename of each node in the linked list. The `print_dirs' parameter
** must be set to TRUE in order to print directories and symlinks
*/

void	ls_print(t_opts *opts, t_node *first, t_bool print_dirs)
{
	while (first)
	{
		if ((!IS_HIDDEN(first->filename) || opts->a) &&
			(!IS_DIRLNK(first) || print_dirs))
			color_print(first);
		first = first->next;
	}
}
