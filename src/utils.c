/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:02:30 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 12:06:23 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Compute the total number of block for the linked list
*/

int		ls_total_blocks(t_node *first)
{
	int	total;

	total = 0;
	while (first)
	{
		if (!IS_DIRLNK(first))
			total += first->stats->st_blocks;
		first = first->next;
	}
	return (total);
}
