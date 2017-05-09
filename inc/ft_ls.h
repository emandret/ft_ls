/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/05/09 23:43:56 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/printf/inc/ft_printf.h"

# include <sys/stat.h>
# include <sys/errno.h>
# include <dirent.h>

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
	char				*filename;
	t_stat				*stats;
	t_bool				is_dir;
	t_bool				is_lnk;
	struct s_node		*next;
}						t_node;

/*
** debug
*/
void					ls_debug_opts(t_opts *opts);
void					ls_debug_node(t_node *node);
void					ls_debug_list(t_node *first);

/*
** options
*/
t_opts					*ls_parse_opts(int ac, char **av, int *i);

/*
** list nodes
*/
t_node					*ls_new_node(char *filename);
t_node					*ls_add_node(char *filename, t_node *first);

/*
** stats
*/
t_stat					*ls_file_lstat(char *filename);

/*
** error
*/
void					ls_error(char *filename);

#endif
