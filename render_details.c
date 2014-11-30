#include "ft_ls.h"

void					print_date(char *str)
{
	int i;

	i = 4;
	while (str[i + 9] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void					render_details(t_node *file, int flags)
{
	struct stat			st;
	
	stat(file->path, &st);
	ft_putstr(ft_filepermission(&st));
	ft_putchar(' ');
	ft_putnbr(st.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(st.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putstr(getgrgid(st.st_gid)->gr_name);
	ft_putchar(' ');
	ft_putnbr(st.st_size);
	ft_putchar(' ');
	print_date(ctime(&st.st_mtime));
	ft_putchar(' ');
	ft_putendl(file->name);
}

