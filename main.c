#include "ft_ls.h"

int					unknown(char *path)
{
	struct stat		st;

	return (lstat(path, &st) != 0);
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
				list = sort_insert(list, new_elem(av[ac], av[ac], 0), flags);
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
			printf("\n%s:\n", list->name);
		}
		else if (list)
			printf("\n");
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
				dprintf(1, "%s:\n", current->path);
				first = !first;
			}
			else
				dprintf(1, "\n%s:\n", current->path);
			ft_ls(current, flags);
			current = current->next;
		}
	}
	return (0);
}
