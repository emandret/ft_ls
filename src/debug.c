/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:19:32 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 19:56:03 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_debug_opts(t_opts *opts)
{
	if (opts)
	{
		if (opts->l)
			printf("\e[92m    option -l ENABLED\n");
		if (opts->R)
			printf("\e[92m    option -R ENABLED\n");
		if (opts->a)
			printf("\e[92m    option -a ENABLED\n");
		if (opts->r)
			printf("\e[92m    option -r ENABLED\n");
		if (opts->t)
			printf("\e[92m    option -t ENABLED\n");
	}
}

void	ls_debug_node(t_node *node)
{
	if (node)
	{
		printf("\e[90m    prev        = %p\n", node->prev);
		printf("\e[90m    next        = %p\n", node->next);
		printf("\e[94m    username    = %s\n", node->user->pw_name);
		printf("\e[96m    group       = %s\n", node->group->gr_name);
		printf("\e[95m    filename    = %s\n", node->filename);
		printf("\e[95m    target      = %s\n", node->target);
		printf("\e[93m    hard links  = %d\n", node->stats->st_nlink);
		printf("\e[94m    size        = %llu\n", node->stats->st_size);
		if (node->type == 'd')
			printf("\e[92m    is_dir      = TRUE\n");
		else
			printf("\e[91m    is_dir      = FALSE\n");
		if (node->type == 'l')
			printf("\e[92m    is_lnk      = TRUE\n");
		else
			printf("\e[91m    is_lnk      = FALSE\n");
		printf("\e[39m\n");
	}
}

void	ls_debug_list_short(t_node *first)
{
	t_node	*last;

	last = first;
	while (last->next)
		last = last->next;
	while (first)
	{
		printf("\e[95m%s \e[39m-> ", first->filename);
		first = first->next;
		if (!first)
			printf("\e[91mNULL\n");
	}
	while (last)
	{
		printf("\e[96m%s \e[39m-> ", last->filename);
		last = last->prev;
		if (!last)
			printf("\e[91mNULL\n");
	}
}

void	ls_debug_list(t_node *first)
{
	int	i;

	i = 0;
	while (first)
	{
		printf("\e[96mNode %d :\n", i++);
		ls_debug_node(first);
		first = first->next;
	}
}
