/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:09 by emandret          #+#    #+#             */
/*   Updated: 2017/05/17 04:07:35 by emandret         ###   ########.fr       */
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
			first = ls_add_node(argv[i++], first);
	}
	if (no_arg && !first)
		first = ls_add_node(".", first);
	ft_ls(opts, first);
	return (0);
}

/*
** The ft_ls function, dispatch the nodes to the corrects functions
*/

void	ft_ls(t_opts *opts, t_node *first)
{
	t_node	*head;

	first = ls_sort_alpha(first);
	if (opts->opt_t)
		first = ls_sort_time(first);
	head = first;
	while (head)
	{
		ft_putstr(head->filename);
		ft_putchar(32);
		head = head->next;
	}
	ft_putchar(10);
}
