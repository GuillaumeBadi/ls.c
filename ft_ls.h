/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:39:22 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/29 17:40:01 by gbadi            ###   ########.fr       */
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

typedef struct dirent		dirent;

typedef struct			s_node
{
	char				*name;
	char				*path;
	struct s_node		*next;
}						t_node;

typedef struct 			s_file
{
	char				*mode;
	size_t				n_link;
}						t_file;

t_node					*new_elem(char *name, char *path);
t_node					*push_elem(t_node *list, char *name, char *path);
char					*path_join(char *path, char *name);
void					render_file(t_node *file, int flags);
void					render_details(t_node *file, int flags);
void					ft_ls(char *path, int flags);
void					render_list_r(t_node *list, int flags);
void					render_list(t_node *list, int flags);
void					render_file(t_node *file, int flags);
char					*get_next_opt(int ac, char **av);
void					raise_flags(int ac, char **av, int *flags);

#endif
