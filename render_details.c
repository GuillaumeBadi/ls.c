#include "ft_ls.h"

static char				*ft_format_right(void)
{
	return (0);
}

void					render_details(t_node *file, int flags)
{
	struct stat			st;
	
	stat(file->path, &st);
	ft_putstr(ft_filepermission(&st));
	ft_putchar(' ');
	ft_putendl(file->name);
}

