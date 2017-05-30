/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:02:30 by emandret          #+#    #+#             */
/*   Updated: 2017/05/30 18:15:39 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Update the reference string length `ref' if the `str' length is bigger
*/

static void	set_bigger(char *str, size_t *ref)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > *ref)
		*ref = len;
}

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
** Get the string lengths for `st_nlink', `pw_name', `gr_name' and `st_size'
*/

size_t		*ls_get_strlens(t_opts *opts, t_node *first)
{
	size_t	*lens;

	if (!(lens = (size_t*)ft_memalloc(sizeof(size_t) * LENS_SIZE)))
		return (NULL);
	while (first)
	{
		if (!IS_HIDDEN(first->filename) || opts->a)
		{
			set_bigger(ft_itoa(first->stats->st_nlink), &lens[0]);
			set_bigger(first->user->pw_name, &lens[1]);
			set_bigger(first->group->gr_name, &lens[2]);
			set_bigger(ft_itoa(first->stats->st_size), &lens[3]);
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
			total += first->stats->st_blocks;
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
