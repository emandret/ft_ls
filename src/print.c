/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:35:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/30 18:16:05 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Printing with some colors
*/

static void	print_filename(char type, char *filename)
{
	if (type == '-')
		ft_printf("%s", filename);
	else if (type == 'd')
		ft_printf("\e[1m\e[96m%s\e[39m\e[0m", filename);
	else if (type == 'l')
		ft_printf("\e[35m%s\e[39m", filename);
	else if (type == 'c')
		ft_printf("\e[43m\e[34m%s\e[39m\e[49m", filename);
	else if (type == 'b')
		ft_printf("\e[46m\e[34m%s\e[39m\e[49m", filename);
	else if (type == 'p')
		ft_printf("\e[33m%s\e[39m", filename);
	else if (type == 's')
		ft_printf("\e[32m%s\e[39m", filename);
}

/*
** The final output
*/

static void	print_output(t_node *node, t_bool print_list, size_t *lens)
{
	if (print_list)
	{
		ft_printf("%s  %*hu %*s  %*s  %*lld %s ",
			ls_get_perms(node->type, node->stats->st_mode),
			lens[0], node->stats->st_nlink,
			lens[1], node->user->pw_name,
			lens[2], node->group->gr_name,
			lens[3], node->stats->st_size,
			ls_get_filetime(node->stats->st_mtime)
		);
	}
	print_filename(node->type, node->filename);
	if (print_list && node->type == 'l')
		ft_printf(" -> %s", node->target);
	ft_putchar('\n');
}

/*
** Print the filename of each node in the linked list. The `print_dirs' parameter
** must be set to TRUE in order to print directories and symlinks
*/

void	ls_print(t_opts *opts, t_node *first, t_bool print_dirs)
{
	size_t	*lens;

	lens = ls_get_strlens(opts, first);
	if (print_dirs && opts->l)
		ft_printf("total %d\n", ls_total_blocks(opts, first));
	while (first)
	{
		if ((!IS_HIDDEN(first->filename) || opts->a) &&
			(!IS_DIRLNK(first) || print_dirs))
			print_output(first, opts->l, lens);
		first = first->next;
	}
}
