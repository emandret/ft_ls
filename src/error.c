/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:39:10 by emandret          #+#    #+#             */
/*   Updated: 2017/05/18 04:39:08 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Get the error corresponding to the errno
*/

static void	ft_puterror(void)
{
	if (errno == ENOENT)
		ft_putstr_fd("No such file or directory", 2);
	if (errno == EACCES)
		ft_putstr_fd("Permission denied", 2);
}

/*
** Print an error on the standard error output
*/

void		ls_error(char *filename)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_puterror();
	ft_putchar_fd('\n', 2);
}
