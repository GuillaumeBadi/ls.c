#include "ft_ls.h"

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

