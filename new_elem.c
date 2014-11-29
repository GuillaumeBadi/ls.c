#include "ft_ls.h"

t_node					*new_elem(char *name, char *path)
{
	t_node				*elem;
	elem = (t_node *)malloc(sizeof(t_node));
	elem->name = ft_strdup(name);
	elem->first = FALSE;
	elem->path = ft_strdup(path);
	elem->next = NULL;
	return (elem);
}

