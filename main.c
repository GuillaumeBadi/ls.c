#include "ft_ls.h"

t_node				*get_args(int ac, char **av)
{
	t_node			*list;
	int				dir;

	dir = 0;
	list = new_elem(".", ".");
	while (--ac)
	{
		if (!ISOPT(av[ac]))
		{
			printf("pushing = %s\n", av[ac]);
			list = push_elem(list, av[ac], av[ac]);
			dir = 1;
		}
	}
	if (dir)
	{
		// Norme interruption
		list = list->next;
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
	printf(" i = %d\n", i);
	return (i);
}

int					main(int ac, char **av)
{
	int				flags;
	int				count;
	t_node			*dirs;
	t_node			*current;

	flags = 0;
	raise_flags(ac, av, &flags);
	dirs = get_args(ac, av);
	count = dir_count(dirs);
	if (count == 1)
	{
		printf("%s\n", dirs->path);
		ft_ls(dirs, flags);
	}
	else if (count > 1)
	{
		current = dirs;
		while (current != NULL)
		{
			// norme interupt
			dprintf(1, "\n%s:\n", current->path);
			ft_ls(current, flags);
			current = current->next;
		}
	}
	return (0);
}
