/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:07:42 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:32:59 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define A_FLAG 0b00001
# define L_FLAG 0b00010
# define RR_FLAG 0b00100
# define T_FLAG 0b01000
# define R_FLAG 0b10000

# define FORBIDDEN_FILE "!FORBIDDEN_FILE"

# define LEFT 1
# define RIGHT 2

# define A_ON ((A_FLAG & flags) ? 1 : 0)
# define RR_ON ((RR_FLAG & flags) ? 1: 0)
# define R_ON ((R_FLAG & flags) ? 1 : 0)
# define T_ON ((T_FLAG & flags) ? 1 : 0)
# define L_ON ((L_FLAG & flags) ? 1 : 0)

# define ISHIDDEN(x) ((x->name[0] == '.') ? 1 : 0)
# define ISCURRENT(x) ((ft_strcmp(x->name, ".") == 0) ? 1:0 )
# define IS(x, y) ((ft_strcmp(x, y) == 0) ? 1 : 0)
# define ISOPT(x) (x[0] == '-')

# define TRUE 1
# define FALSE 0

typedef int			t_bool;

typedef struct		s_node
{
	char			*name;
	char			*path;
	t_bool			first;
	struct s_node	*next;
	char			*mode;
	size_t			n_link;
	size_t			size;
	char			*uid;
	char			*gid;
	char			*mtime;
	size_t			time;
}					t_node;

typedef struct		s_length
{
	size_t			pw;
	size_t			gr;
	size_t			links;
	size_t			size;
}					t_length;

t_node				*new_elem(char *name, char *path, size_t time);
t_node				*push_elem(t_node *list, char *name, char *path, size_t time);
char				*path_join(char *path, char *name);
char				*ft_filepermission(struct stat *st);
void				render_details(t_node *file, int flags, t_length *length);
void				ft_ls(t_node *dir, int flags);
void				render_list_r(t_node *list, int flags);
void				render_list(t_node *list, int flags);
int					render_file(t_node *file, int flags, t_length *length);
char				*get_next_opt(int ac, char **av);
void				raise_flags(int ac, char **av, int *flags);
void				ft_ls_relaunch(t_node *dirs, int flags);
t_node				*sort_insert(t_node *list, t_node *node, int flags);
t_length			*get_length(t_node *list, int flags);
char				*format_int_column(int number, int orientation, int len);
char				*format_str_column(char *str, int orientation, int len);
int					is_dir(char *path, int flags);

#endif
