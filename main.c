/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 08:15:26 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/28 11:08:20 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node					*new_elem(char *name, char *path)
{
	t_node				*elem;
	elem = (t_node *)malloc(sizeof(t_node));
	elem->name = name;
	elem->path = path;
	elem->next = NULL;
	return (elem);
}

t_node					*push_elem(t_node *list, char *name, char *path)
{
	t_node				*new;
	t_node				*current;

	current = list;
	new = new_elem(name,path);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}

char					*path_join(char *path, char *name)
{
	char				*finale;

	finale = ft_strjoin(path, "/");
	finale = ft_strjoin(finale, name);
	return (finale);
}

void					render_details(t_node *file, int flags)
{
	ft_putstr("DETAILS + ");
	ft_putendl(file->name);
}

void					render_file(t_node *file, int flags)
{
	if ( ( ISHIDDEN(file) && A_ON) || !ISHIDDEN(file))
	{
		if (L_ON)
			render_details(file, flags);
		else
			ft_putendl(file->name);
	}
}

void				render_list_r(t_node *list, int flags)
{
	t_node			*current;

	current = list;
	if (current->next != NULL)
		render_list_r(current->next, flags);
	render_file(current, flags);
}

void					render_list(t_node *list, int flags)
{
	t_node				*current;

	if (R_ON)
	{
		render_list_r(list, flags);
		return ;
	}
	current = list;
	while (current != NULL)
	{
		render_file(current, flags);
		current = current->next;
	}
}

void					ft_ls(char *path, int flags)
{
	DIR					*directory;
	dirent				*file;
	t_node				*dirs;
	t_node				*files;

	// Norme interruption
	dirs = new_elem("", "");
	files = new_elem("", "");
	if ((directory = opendir(path)) == NULL)
		// Norme interruption
		return ;
	while ((file = readdir(directory)) > 0)
	{
		if (file->d_type == DT_DIR)
			dirs = push_elem(dirs, file->d_name, path_join(path, file->d_name));
		files = push_elem(files, file->d_name, path_join(path, file->d_name));
	}
	// Norme interruption
	files = files->next;
	dirs = dirs->next;
	render_list(files, flags);
}

char					*get_next_opt(int ac, char **av)
{
	static int			index = 1;

	if (index == ac)
		return (0);
	while (av[index][0] != '-')
	{
		if (index + 1 >= ac)
			return (0);
		index++;
	}
	return (ft_strdup(av[index++]));
}

void						raise_flags(int ac, char **av, int *flags)
{
	char					*opt;
	size_t					i;

	i = 1;
	while ((opt = get_next_opt(ac, av)) != 0)
	{
		while (i < ft_strlen(opt))
		{
			if (opt[i] == 'R')
				*flags |= RR_FLAG;
			else if (opt[i] == 'r')
				*flags |= R_FLAG;
			else if (opt[i] == 'a')
				*flags |= A_FLAG;
			else if (opt[i] == 'l')
				*flags |= L_FLAG;
			else if (opt[i] == 't')
				*flags |= T_FLAG;
			else
				// Norme interruption
				printf("%s:%s\n", "NOT AN OPTION", opt);
			i++;
		}
		i = 1;
	}
}

int					main(int ac, char **av)
{
	int				flags;

	flags = 0; //0b00000
	raise_flags(ac, av, &flags);
	ft_ls(".", flags);
	return (0);
}
