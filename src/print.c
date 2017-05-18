/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:35:29 by emandret          #+#    #+#             */
/*   Updated: 2017/05/18 18:17:35 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_print_files(t_node *first)
{
	t_bool	endl;

	endl = FALSE;
	while (first)
	{
		if (!first->is_dir && !first->is_lnk)
		{
			ft_putstr(first->filename);
			endl = TRUE;
		}
		if ((first = first->next) && endl)
			ft_putchar(' ');
	}
	if (endl)
		ft_putchar('\n');
}
