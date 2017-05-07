/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/05/07 11:42:08 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/printf/inc/ft_printf.h"

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

typedef struct			s_opts
{
	t_bool				opt_l;
	t_bool				opt_R;
	t_bool				opt_a;
	t_bool				opt_r;
	t_bool				opt_t;
}						t_opts;

typedef struct			s_node
{
	t_dir				*dirent;
	t_stat				*stats;
	struct s_node		*next;
}						t_node;

#endif
