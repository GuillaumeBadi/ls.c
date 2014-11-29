#include "ft_ls.h"

void					raise_flags(int ac, char **av, int *flags)
{
	char				*opt;
	size_t				i;

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


