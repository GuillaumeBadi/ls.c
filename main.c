#include "ft_ls.h"

int					main(int ac, char **av)
{
	int				flags;
	t_node			*dir;

	dir = new_elem(av[1], av[1]);
	dir->first = 1;
	flags = 0; //0b00000
	raise_flags(ac, av, &flags);
	ft_ls(dir, flags);
	return (0);
}
