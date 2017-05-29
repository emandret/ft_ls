/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:09 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 08:07:30 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** The entry point. Parse the parameters and create a linked list
*/

int		main(int argc, char *argv[])
{
	int		i;
	t_node	*first;
	t_opts	*opts;
	t_bool	no_arg;

	i = 1;
	first = NULL;
	opts = ls_parse_opts(argc, argv, &i);
	no_arg = TRUE;
	if (argc > 1)
	{
		if (i < argc)
			no_arg = FALSE;
		while (i < argc)
			first = ls_add_node("", argv[i++], first);
	}
	if (no_arg && !first)
		first = ls_add_node("", ".", first);
	ft_ls(opts, first);
	return (0);
}

/*
** The ft_ls function. Dispatch nodes to the appropriate functions
*/

void	ft_ls(t_opts *opts, t_node *first)
{
	t_node	*content;

	content = NULL;
	ls_lst_order(opts, &first);
	ls_print(opts, first, FALSE);
	if (ls_lst_size(first) > 1 && ls_lst_dirs(opts, first) > 0)
	{
		opts->path = TRUE;
		if (ls_lst_size(first) != ls_lst_dirs(opts, first))
			opts->endl = TRUE;
	}
	while (first)
	{
		if (IS_DIRLNK(first, opts))
			ls_probe_dir(opts, "", first->filename);
		first = first->next;
	}
}

/*
** Print an error on the stderr (fildes 2)
*/

void	ls_error(char *filename)
{
	ft_putstr_fd("ls: ", 2);
	perror(filename);
}
