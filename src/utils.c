/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:02:30 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 20:30:20 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Return the corresponding character of a supported file type in UNIX. Return a
** NULL character if the file type is not supported
*/

char		ls_get_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISSOCK(mode))
		return ('s');
	return ('\0');
}

/*
** Compute the total number of block for the linked list
*/

int			ls_total_blocks(t_node *first)
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
