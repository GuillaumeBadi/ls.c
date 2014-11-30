#include "ft_ls.h"

static char		get_type(struct stat st)
{
	if (S_ISDIR(st.st_mode))
		return ('d');
	if (S_ISREG(st.st_mode))
		return ('-');
	if (S_ISLNK(st.st_mode))
		return ('l');
	if (S_ISFIFO(st.st_mode))
		return ('p');
	if (S_ISSOCK(st.st_mode))
		return ('s');
	if (S_ISCHR(st.st_mode))
		return ('c');
	if (S_ISBLK(st.st_mode))
		return ('b');
	return (0);
}

char			*ft_filepermission(struct stat *st)
{
	char		rights[11];

	rights[0] = get_type(*st);
	rights[1] = (st->st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (st->st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (st->st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (st->st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (st->st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (st->st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (st->st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (st->st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (st->st_mode & S_IXOTH) ? 'x' : '-';
	rights[10] = '\0';
	return (ft_strdup(rights));
}
