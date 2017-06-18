/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 11:19:20 by emandret          #+#    #+#             */
/*   Updated: 2017/06/18 06:12:53 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/src/printf/inc/ft_printf.h"

# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define IS_DIRLNK(node) ('d' == node->type || 'l' == node->type)
# define IS_TRGDIR(node) ('l' == node->type && 'd' == node->target_type)
# define IS_DOTDIR(name) (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
# define IS_HIDDEN(name) ('.' == *name || IS_DOTDIR(name))

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
	t_bool				recu;
	t_bool				a;
	t_bool				r;
	t_bool				t;
	t_bool				path;
	t_bool				endl;
}						t_opts;

/*
** The node. It contains a lot of informations about a file or a directory :
**    + -------------- + ------------------------------- +
**    | type           | The type of the file            |
**    + -------------- + ------------------------------- +
**    | target         | The file pointed by a symlink   |
**    + -------------- + ------------------------------- +
**    | target_type    | The type of the pointed target  |
**    + -------------- + ------------------------------- +
**    | filename       | The filename                    |
**    + -------------- + ------------------------------- +
**    | stat           | The stat structure              |
**    + -------------- + ------------------------------- +
**    | user           | The passwd structure            |
**    + -------------- + ------------------------------- +
**    | group          | The group structure             |
**    + -------------- + ------------------------------- +
**    | prev & next    | Linked list references          |
**    + -------------- + ------------------------------- +
*/
typedef struct			s_node
{
	char				type;
	char				acl;
	char				target[256];
	char				target_type;
	char				*filename;
	t_stat				*stat;
	t_user				*user;
	t_group				*group;
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
** node.c -- Nodes functions
*/
t_node					*ls_add_node(char *path, char *filename, t_node *first);
void					ls_free_node(t_node *node);

/*
** lst.c -- Linked list functions
*/
void					ls_lst_order(t_opts *opts, t_node **first);
void					ls_lst_free(t_node *first);
int						ls_lst_size(t_node *first);
int						ls_lst_dirs(t_node *first);

/*
** data.c -- Retrieve informations about files
*/
t_bool					ls_node_data(char *fpath, t_node *node);

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
** perms.c -- Retrieve permissions
*/
char					*ls_get_perms(char type, mode_t mode);

/*
** utils.c -- Utilities functions
*/
int						*ls_get_strlens(t_opts *opts, t_node *first);
uintmax_t				ls_total_blocks(t_opts *opts, t_node *first);
char					*ls_get_devsize(t_node *node);
char					*ls_get_filetime(time_t last_access);

/*
** print.c -- Printing
*/
void					ls_print(t_opts *opts, t_node *first, t_bool show_d);

#endif
