/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 02:35:13 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/09 02:43:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					unknown(char *path)
{
	struct stat		st;

	return (lstat(path, &st) != 0);
}

int					is_ok(char *path)
{
	DIR				*dir;

	if ((dir = opendir(path)) == NULL)
		return (0);
	else
		closedir(dir);
	return (1);
}

t_node				*get_args(int ac, char **av, int flags)
{
	t_node			*list;
	t_node			*files;
	t_node			*current;
	int				dir;
	int				ret;

	dir = 0;
	ret = 0;
	// Norme interruption
	list = new_elem(".", ".", 0);
	files = new_elem(".",".", 0);
	while (--ac)
	{
		if (!ISOPT(av[ac]))
		{
			// Norme interruption
			if (is_dir(av[ac], flags))
			{
				if (is_ok(av[ac]))
					list = sort_insert(list, new_elem(av[ac], av[ac], 0), flags);
				else
					perror(ft_strjoin("ls: ", av[ac] + 1));
			}
			else
				files = sort_insert(files, new_elem(av[ac], av[ac], 0), flags);
			dir = 1;
		}
	}
	if (dir)
	{
		// Norme interruption
		list = list->next;
	}
	files = files->next;
	current = files;
	if (files)
	{
		while (current != NULL)
		{
			if (!unknown(current->path))
				ft_ls(current, flags);
			else
				perror(ft_strjoin("ls: ", current->name));
			current = current->next;
		}
		if (!list)
			exit(1);
		if (!list->next)
		{
			ft_putstr("\n");
			ft_putstr(list->name);
			ft_putstr(":\n");
		}
		else
			ft_putstr("\n");
	}
	return (list);
}

int					dir_count(t_node *list)
{
	t_node			*current;
	int				i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		i++;
		current->first = 1;
		current = current->next;
	}
	return (i);
}

int					main(int ac, char **av)
{
	int				flags;
	int				count;
	t_node			*dirs;
	t_node			*current;
	int				first;

	flags = 0;
	first = 1;
	raise_flags(ac, av, &flags);
	dirs = get_args(ac, av, flags);
	count = dir_count(dirs);
	if (count == 1)
	{
		ft_ls(dirs, flags);
	}
	else if (count > 1)
	{
		current = dirs;
		while (current != NULL)
		{
			// norme interupt
			if (first)
			{
				ft_putstr(current->path);
				ft_putstr(":\n");
				first = !first;
			}
			else
			{
				ft_putstr("\n");
				ft_putstr(current->path);
				ft_putstr(":\n");
			}
			ft_ls(current, flags);
			current = current->next;
		}
	}
	return (0);
}
