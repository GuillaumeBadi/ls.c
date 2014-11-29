#include "ft_ls.h"

void					render_details(t_node *file, int flags)
{
	struct stat			st;
	
	ft_putstr("DETAILS + ");
	ft_putendl(file->name);
}

