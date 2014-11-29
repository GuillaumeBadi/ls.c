#include "ft_ls.h"

t_node					*new_elem(char *name, char *path)
{
	t_node				*elem;
	elem = (t_node *)malloc(sizeof(t_node));
	elem->name = name;
	elem->path = path;
	elem->next = NULL;
	return (elem);
}

