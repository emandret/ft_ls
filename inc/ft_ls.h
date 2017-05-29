/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/05/29 08:05:11 by emandret         ###   ########.fr       */
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

# define IS_DIRLNK(node, opts) (node->types->is_dir || (node->types->is_lnk && !opts->l))
# define IS_DOTDIR(filename) (!ft_strcmp(filename, ".") || !ft_strcmp(filename, ".."))
# define IS_HIDDEN(filename) ('.' == *filename || IS_DOTDIR(filename))

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_user;
typedef struct group	t_group;

/*
** The options passed as parameters to the program
*/
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

/*
** The different file types supported in UNIX
*/
typedef struct			s_types
{
	t_bool				is_reg;
	t_bool				is_dir;
	t_bool				is_lnk;
	t_bool				is_chr;
	t_bool				is_blk;
	t_bool				is_fifo;
	t_bool				is_sock;
}						t_types;

/*
** The node. It contains a lot of informations about a file or a directory
*/
typedef struct			s_node
{
	char				*filename;
	char				target[1024];
	t_stat				*stats;
	t_user				*user;
	t_group				*group;
	t_types				*types;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

/*
** ft_ls.c -- Main file for the program
*/
void					ft_ls(t_opts *opts, t_node *first);
void					ls_error(char *filename);

/*
** opts.c -- The options parser
*/
t_opts					*ls_parse_opts(int ac, char **av, int *i);

/*
** node.c -- Linked list functions
*/
t_node					*ls_add_node(char *path, char *filename, t_node *first);
void					ls_lst_order(t_opts *opts, t_node **first);
int						ls_lst_size(t_node *first);
int						ls_lst_dirs(t_opts *opts, t_node *first);

/*
** stats.c -- Retrieve informations about files
*/
t_bool					ls_file_lstats(char *fpath, t_node *node);
t_bool					ls_file_types(t_node *node);
t_bool					ls_link_target(char *fpath, t_node *node);
t_bool					ls_user_infos(t_node *node);

/*
** node_swap.c -- Swapping functions for doubly linked list
*/
t_bool					ls_swap_first(t_node **first, t_node *n1, t_node *n2);

/*
** sort.c -- Sorting functions
*/
t_bool					ls_sort_lexi(t_node *n1, t_node *n2);
t_bool					ls_sort_time(t_node *n1, t_node *n2);
void					ls_lst_sort(t_node **first,
	t_bool (*sort)(t_node *n1, t_node *n2));
void					ls_lst_revr(t_node **first);

/*
** dirs.c -- Open directories
*/
t_node					*ls_open_dir(DIR *stream, t_opts *opts, char *path);
int						ls_probe_dir(t_opts *opts, char *path, char *dirname);

/*
** print.c -- Printing
*/
void					ls_print(t_opts *opts, t_node *first,
	t_bool print_dirs);


/* **** DEBUG **** */
void					ls_debug_opts(t_opts *opts);
void					ls_debug_node(t_node *node);
void					ls_debug_list_short(t_node *first);
void					ls_debug_list(t_node *first);
/* **** END DEBUG **** */

#endif
