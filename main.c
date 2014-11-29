/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:45:36 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/29 17:36:05 by vbatiot          ###   ########.fr       */
=======
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 08:15:26 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/28 11:08:20 by gbadi            ###   ########.fr       */
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
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
<<<<<<< HEAD
	struct stat			st;
	
	ft_putstr("DETAILS + ");
	ft_putendl(file->name);
}
	
=======
	ft_putstr("DETAILS + ");
	ft_putendl(file->name);
}

>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
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

<<<<<<< HEAD
	dirs = new_elem("", "");
	files = new_elem("", "");
	if ((directory = opendir(path)) == NULL)
=======
	// Norme interruption
	dirs = new_elem("", "");
	files = new_elem("", "");
	if ((directory = opendir(path)) == NULL)
		// Norme interruption
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
		return ;
	while ((file = readdir(directory)) > 0)
	{
		if (file->d_type == DT_DIR)
			dirs = push_elem(dirs, file->d_name, path_join(path, file->d_name));
		files = push_elem(files, file->d_name, path_join(path, file->d_name));
	}
<<<<<<< HEAD
=======
	// Norme interruption
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
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

<<<<<<< HEAD
void					raise_flags(int ac, char **av, int *flags)
{
	char				*opt;
	size_t				i;
=======
void						raise_flags(int ac, char **av, int *flags)
{
	char					*opt;
	size_t					i;
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1

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
<<<<<<< HEAD
				// Norme interrupt
				printf("%s:%s\n", "NOT AN FCKING OPTION", opt);
=======
				// Norme interruption
				printf("%s:%s\n", "NOT AN OPTION", opt);
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
			i++;
		}
		i = 1;
	}
}

<<<<<<< HEAD
int						main(int ac, char **av)
{
	int					flags;

	flags = 0; //egal a 0b00000;
=======
int					main(int ac, char **av)
{
	int				flags;

	flags = 0; //0b00000
>>>>>>> 240e7e134046bdeca6c87c2dd9070715c93a14b1
	raise_flags(ac, av, &flags);
	ft_ls(".", flags);
	return (0);
}
