#include "ft_ls.h"

char					*path_join(char *path, char *name)
{
	char				*finale;

	finale = ft_strjoin(path, "/");
	finale = ft_strjoin(finale, name);
	return (finale);
}

