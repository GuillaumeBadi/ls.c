#include "ft_ls.h"

t_node				*get_dirs(int ac, char **av)
{
	t_node			*list;

	list = new_elem(".", ".");
	while (--ac)
	return (list);
}

int					main(int ac, char **av)
{
	int				flags;
	t_node			*dir;

	dir = new_elem(".", ".");
	dir->first = 1;
	flags = 0; //0b00000
	raise_flags(ac, av, &flags);
	ft_ls(dir, flags);
	return (0);
}

int					main(int ac, char **av)
{
	int				flags;
	t_node			*dirs;

	flags = 0;
	raise_flags(ac, av, &flags);
	dirs = get_dirs(ac, av);
	return (0);
}
