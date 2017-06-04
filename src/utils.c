/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:02:30 by emandret          #+#    #+#             */
/*   Updated: 2017/06/04 19:23:17 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Update the reference string length `ref' if the `str' length is bigger
*/

static void	set_bigger(char *str, int *ref)
{
	int	len;

	len = ft_strlen(str);
	if (len > *ref)
		*ref = len;
}

/*
** Get the string lengths for `st_nlink', `pw_name', `gr_name' and `st_size'
*/

int			*ls_get_strlens(t_opts *opts, t_node *first)
{
	int	*lens;

	if (!(lens = (int*)ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	while (first)
	{
		if (!IS_HIDDEN(first->filename) || opts->a)
		{
			set_bigger(ft_itoa(first->stat->st_nlink), &lens[0]);
			set_bigger(first->user->pw_name, &lens[1]);
			set_bigger(first->group->gr_name, &lens[2]);
			set_bigger(ft_itoa(first->stat->st_size), &lens[3]);
		}
		first = first->next;
	}
	return (lens);
}

/*
** Compute the total number of block for the linked list
*/

int			ls_total_blocks(t_opts *opts, t_node *first)
{
	int	total;

	total = 0;
	while (first)
	{
		if (!IS_HIDDEN(first->filename) || opts->a)
			total += first->stat->st_blocks;
		first = first->next;
	}
	return (total);
}

/*
** Get the date & time of creation for a file (node)
*/

char		*ls_get_filetime(time_t last_access)
{
	time_t	timestamp;
	char	*datetime;
	char	*filetime;

	if (!(filetime = ft_strnew(12)))
		return (NULL);
	time(&timestamp);
	datetime = ctime(&last_access);
	if (ABS(timestamp - last_access) > 3600 * 24 * 30 * 6)
	{
		ft_strncpy(filetime, &datetime[4], 7);
		ft_strncpy(&filetime[7], &datetime[19], 5);
	}
	else
		ft_strncpy(filetime, &datetime[4], 12);
	return (filetime);
}
