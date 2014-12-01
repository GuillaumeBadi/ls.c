#include "ft_ls.h"

void					ft_ls(t_node *dir, int flags)
{
	DIR					*directory;
	dirent				*file;
	t_node				*dirs;
	t_node				*files;

	dirs = new_elem("", "");
	files = new_elem("", "");
	if ((directory = opendir(dir->path)) == NULL)
		return ;
	while ((file = readdir(directory)) > 0)
	{
		if (file->d_type == DT_DIR && !IS(file->d_name, ".") && !IS(file->d_name, "..") && RR_ON)
			dirs = sort_insert(dirs, new_elem(file->d_name, path_join(dir->path, file->d_name)), flags);
		files = sort_insert(files, new_elem(file->d_name, path_join(dir->path, file->d_name)), flags);
	}
	files = files->next;
	dirs = dirs->next;
	if ((ISHIDDEN(dir) && A_ON) || !ISHIDDEN(dir) || dir->first == TRUE)
	{
		render_list(files, flags);
	}
	free(files);
	closedir(directory);
	if (RR_ON)
		ft_ls_relaunch(dirs, flags);
	free(dirs);
}
