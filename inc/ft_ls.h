/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 05:51:00 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/printf/inc/ft_printf.h"

# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>

# define IS_DIRLNK(list, opts) (list->is_dir || (list->is_lnk && !opts->l))
# define IS_DOTDIR(file) (!ft_strcmp(file, ".") || !ft_strcmp(file, ".."))
# define IS_HIDDEN(file) ('.' == *file || IS_DOTDIR(file))

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_user;
typedef struct group	t_group;

typedef struct			s_opts
{
	t_bool				l;
	t_bool				R;
	t_bool				a;
	t_bool				r;
	t_bool				t;
	t_bool				path;
	t_bool				endl;
}						t_opts;

typedef struct			s_node
{
	char				*filename;
	char				target[1024];
	t_stat				*stats;
	t_user				*user;
	t_group				*group;
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
void					ls_link_target(char *path, t_node *node);
t_bool					ls_user_infos(t_node *node);

/*
** dirs
*/
int						ls_probe_dir(t_opts *opts, char *path, char *dirname);
t_node					*ls_open_dir(DIR *stream, t_opts *opts, char *path);

/*
** print
*/
void					ls_print(t_opts *opts, t_node *list);
void					ls_print_file(t_opts *opts, t_node *list);

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
void					ls_reverse_list(t_node **first);
void					ls_reorder_list(t_opts *opts, t_node **first);

/*
** utils
*/
char					*ls_path(char *path, char *dirname);
int						ls_list_size(t_node *first);
int						ls_count_dir(t_opts *opts, t_node *first);

#endif
