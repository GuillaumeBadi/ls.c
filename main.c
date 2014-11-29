#include "ft_ls.h"

int					main(int ac, char **av)
{
	int				flags;

	flags = 0; //0b00000
	raise_flags(ac, av, &flags);
	ft_ls(".", flags);
	return (0);
}
