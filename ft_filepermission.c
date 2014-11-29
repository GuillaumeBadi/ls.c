#include "ft_ls.h"

t_node		ft_filepermission(char *str, struct stat st)
{
	str = (char *)malloc(sizeof(char) * 10);
	str[1] = ((st.st_mode & S_IRUSR) ? 'r' : '-');
	str[2] = ((st.st_mode & S_IWUSR) ? 'w' : '-');
	str[3] = ((st.st_mode & S_IXUSR) ? 'x' : '-');
	str[4] = ((st.st_mode & S_IRGRP) ? 'r' : '-');
	str[5] = ((st.st_mode & S_IWGRP) ? 'w' : '-');
	str[6] = ((st.st_mode & S_IXGRP) ? 'x' : '-');
	str[7] = ((st.st_mode & S_IROTH) ? 'r' : '-');
	str[8] = ((st.st_mode & S_IWOTH) ? 'w' : '-');
	str[9] = ((st.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr(str);
}
