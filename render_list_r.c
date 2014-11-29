#include "ft_ls.h"

void				render_list_r(t_node *list, int flags)
{
	t_node			*current;

	current = list;
	if (current->next != NULL)
		render_list_r(current->next, flags);
	render_file(current, flags);
}

