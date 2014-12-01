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

typedef struct dirent		dirent;
typedef int					t_bool;

typedef struct			s_node
{
	char				*name;
	char				*path;
	t_bool				first;
	struct s_node		*next;
	char				*mode;
	size_t				n_link;
	size_t				size;
	char				*uid;
	char				*gid;
	char				*mtime;
	size_t				time;
}						t_node;

typedef struct 			s_file
{
	char				*mode;
	size_t				n_link;
	size_t				size;
	char				*uid;
	char				*gid;
	char				*mtime;
}						t_file;

t_node					*new_elem(char *name, char *path);
t_node					*push_elem(t_node *list, char *name, char *path);
char					*path_join(char *path, char *name);
char					*ft_filepermission(struct stat *st);
void					render_file(t_node *file, int flags);
void					render_details(t_node *file, int flags);
void					ft_ls(t_node *dir, int flags);
void					render_list_r(t_node *list, int flags);
void					render_list(t_node *list, int flags);
void					render_file(t_node *file, int flags);
char					*get_next_opt(int ac, char **av);
void					raise_flags(int ac, char **av, int *flags);
void					ft_ls_relaunch(t_node *dirs, int flags);
t_node					*sort_insert(t_node *list, t_node *node, int flags);

#endif
