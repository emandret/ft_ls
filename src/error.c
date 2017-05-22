/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:39:10 by emandret          #+#    #+#             */
/*   Updated: 2017/05/22 20:08:27 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
** Print an error on the standard error output
*/

void	ls_error(char *filename)
{
	ft_putstr_fd("ls: ", 2);
	perror(filename);
}
