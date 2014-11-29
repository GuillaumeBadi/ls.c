#include "ft_ls.h"

void					ft_ls(char *path, int flags)
{
	DIR					*directory;
	dirent				*file;
	t_node				*dirs;
	t_node				*files;

	// Norme interruption
	dirs = new_elem("", "");
	files = new_elem("", "");
	if ((directory = opendir(path)) == NULL)
		// Norme interruption
		return ;
	while ((file = readdir(directory)) > 0)
	{
		if (file->d_type == DT_DIR)
			dirs = push_elem(dirs, file->d_name, path_join(path, file->d_name));
		files = push_elem(files, file->d_name, path_join(path, file->d_name));
	}
	files = files->next;
	dirs = dirs->next;
	render_list(files, flags);
}

