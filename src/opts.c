/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:39:05 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 11:22:22 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Set the options in the `opts' structure
*/

static t_bool	set_opts(char c, t_opts *opts)
{
	if (ft_strchr("lRart", c))
	{
		if ('l' == c)
			opts->l = TRUE;
		if ('R' == c)
			opts->R = TRUE;
		if ('a' == c)
			opts->a = TRUE;
		if ('r' == c)
			opts->r = TRUE;
		if ('t' == c)
			opts->t = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

/*
** Output the error for an invalid option. Print the usage.
*/

static void		set_error(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-lRart] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

/*
** Parse the options into the `opts' structure, increment the index `i'
*/

t_opts			*ls_parse_opts(int ac, char **av, int *i)
{
	t_opts	*opts;
	int		j;

	if (!(opts = (t_opts*)ft_memalloc(sizeof(t_opts))))
		return (NULL);
	while (*i < ac && '-' == av[*i][0] && !ft_strnequ("-", av[*i], 2) &&
		!ft_strnequ("--", av[*i], 3))
	{
		j = 0;
		while (av[*i][j++])
			if (!set_opts(av[*i][j], opts))
				set_error(av[*i][j]);
		(*i)++;
	}
	if (*i < ac && ft_strnequ("--", av[*i], 3))
		(*i)++;
	return (opts);
}
