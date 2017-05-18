/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:09 by emandret          #+#    #+#             */
/*   Updated: 2017/05/18 18:57:53 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Entry point, parse args, populate structs
*/

int		main(int argc, char *argv[])
{
	int		i;
	t_opts	*opts;
	t_bool	no_arg;
	t_node	*first;

	i = 1;
	opts = ls_parse_opts(argc, argv, &i);
	no_arg = TRUE;
	first = NULL;
	if (argc > 1)
	{
		if (i < argc)
			no_arg = FALSE;
		while (i < argc)
			first = ls_add_node("./", argv[i++], first);
	}
	if (no_arg && !first)
		first = ls_add_node("./", ".", first);
	ft_ls(opts, first);
	return (0);
}

/*
** The ft_ls function, dispatch the nodes to the corrects functions
*/

void	ft_ls(t_opts *opts, t_node *first)
{
	t_node	*content;

	content = NULL;
	ls_sort_list(&first, &ls_sort_lexi);
	if (opts->opt_t)
		ls_sort_list(&first, &ls_sort_time);
	ls_debug_list_short(first);
	while (first)
	{
		if (first->is_dir)
			ls_debug_list_short(ls_open_dir(opts, "./", first->filename));
		first = first->next;
	}
}
