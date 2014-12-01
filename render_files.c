#include "ft_ls.h"

void					render_file(t_node *file, int flags)
{
	if ( (( ISHIDDEN(file) && A_ON) || !ISHIDDEN(file)) && !IS(FORBIDDEN_FILE, file->name))
	{
		if (L_ON)
			render_details(file, flags);
		else
			ft_putendl(file->name);
	}
}
