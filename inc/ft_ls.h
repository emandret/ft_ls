/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/05/21 04:14:02 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/printf/inc/ft_printf.h"

# include <sys/stat.h>
# include <sys/errno.h>
# include <dirent.h>

# define OPEN_FAILURE -1
# define OPEN_SUCCESS 0

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
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

/*
** debug
*/
void					ls_debug_opts(t_opts *opts);
void					ls_debug_node(t_node *node);
void					ls_debug_list(t_node *first);
void					ls_debug_list_short(t_node *first);

/*
** ft_ls
*/
void					ft_ls(t_opts *opts, t_node *first);

/*
** opts
*/
t_opts					*ls_parse_opts(int ac, char **av, int *i);

/*
** list nodes
*/
t_node					*ls_new_node(char *path, char *filename, t_node *prev);
t_node					*ls_add_node(char *path, char *filename, t_node *first);
t_node					*ls_get_last(t_node *first);

/*
** stats
*/
t_stat					*ls_file_lstat(char *path, char *filename);

/*
** dirs
*/
int						ls_probe_dir(t_opts *opts, char *path, char *dirname);
t_node					*ls_open_dir(DIR *stream, t_opts *opts, char *path);

/*
** print
*/
void					ls_print_files(t_node *first);

/*
** error
*/
void					ls_error(char *filename);

/*
** node_swap
*/
void					ls_swap_detached(t_node *n1, t_node *n2);
void					ls_swap_attached(t_node *n1, t_node *n2);
void					ls_swap_nodes(t_node *n1, t_node *n2);
t_bool					ls_swap_first(t_node **first, t_node *n1, t_node *n2);

/*
** sort
*/
t_bool					ls_sort_time(t_node *n1, t_node *n2);
t_bool					ls_sort_lexi(t_node *n1, t_node *n2);
void					ls_sort_list(t_node **first,
	t_bool (*sort)(t_node *n1, t_node *n2));

/*
** utils
*/
t_bool					ls_is_dotdir(char *dirname);
t_bool					ls_has_trailing(char *filename, char c);
char					*ls_path(char *path, char *dirname);

#endif
