/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:09 by emandret          #+#    #+#             */
/*   Updated: 2017/05/09 23:35:27 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char *argv[])
{
	int		i;
	t_node	*node;
	t_opts	*opts;
	t_bool	no_args;

	i = 1;
	node = NULL;
	no_args = TRUE;
	if (argc > i)
	{
		opts = ls_parse_opts(argc, argv, &i);
		if (i < argc)
			no_args = FALSE;
		while (i < argc)
			node = ls_add_node(argv[i++], node);
		ls_debug_opts(opts);
	}
	if (no_args && !node)
		node = ls_add_node(".", node);
	ls_debug_list(node);
	return (0);
}
