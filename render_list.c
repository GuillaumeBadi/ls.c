#include "ft_ls.h"

void					render_list(t_node *list, int flags)
{
	t_node				*current;

	if (R_ON)
	{
		render_list_r(list, flags);
		return ;
	}
	current = list;
	while (current != NULL)
	{
		render_file(current, flags);
		current = current->next;
	}
}
