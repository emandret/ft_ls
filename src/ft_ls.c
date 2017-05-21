/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:09 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 07:57:24 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Entry point, parse args, populate structs
*/

int		main(int argc, char *argv[])
{
	int		i;
	t_node	*list;
	t_opts	*opts;
	t_bool	no_arg;

	i = 1;
	list = NULL;
	opts = ls_parse_opts(argc, argv, &i);
	no_arg = TRUE;
	if (argc > 1)
	{
		if (i < argc)
			no_arg = FALSE;
		while (i < argc)
			list = ls_add_node("", argv[i++], list);
	}
	if (no_arg && !list)
		list = ls_add_node("", ".", list);
	ft_ls(opts, list);
	return (0);
}

/*
** The ft_ls function, dispatch the nodes to the corrects functions
*/

void	ft_ls(t_opts *opts, t_node *list)
{
	t_node	*content;

	content = NULL;
	ls_sort_list(&list, &ls_sort_lexi);
	if (opts->opt_t)
		ls_sort_list(&list, &ls_sort_time);
	if (opts->opt_r)
		ls_reverse_list(&list);
	while (list)
	{
		if (list->is_dir)
			ls_probe_dir(opts, "", list->filename);
		list = list->next;
	}
}
