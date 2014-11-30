#include "ft_ls.h"

<<<<<<< HEAD
static char				*ft_format_right(void)
{
	return (0);
}
=======
static char				*ft_format_right()
>>>>>>> dcc25f0d75de6b85a9e0b3bb7e5a180ef7e510b2

void					render_details(t_node *file, int flags)
{
	struct stat			st;
	
	stat(file->path, &st);
	ft_putstr(ft_filepermission(&st));
	ft_putchar(' ');
	ft_putendl(file->name);
}

