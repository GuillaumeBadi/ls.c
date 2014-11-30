
#include "ft_ls.h"

void					ft_ls_relaunch(t_node *dirs, int flags)
{
	t_node				*current;

	current = dirs;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		// Norme interruption
		if ((A_ON && ISHIDDEN(current)) || !ISHIDDEN(current))
		{
			// Norme interruption
			dprintf(1, "\n%s:\n", current->path);
		}
		//dprintf(1, "launching ==== > %s\n", current->name);
		ft_ls(current, flags);
		current = current->next;
	}
}
