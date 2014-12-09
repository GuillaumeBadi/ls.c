/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 12:30:50 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/09 02:40:07 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define JOIN(x, y) path_join(x, y)
#define PATH(x) JOIN(dir->path, x)
#define ISADIR(x) ((x->d_type == DT_DIR) ? 1 : 0)
#define TIME(x) get_time(PATH(x))
#define SORT(x,y,z) sort_insert(x, y, z)
#define NEW(x) new_elem(x, PATH(x), TIME(x))
#define PUSH(x, y) x = SORT(x, NEW(y->d_name), flags)

size_t					get_time(char *path)
{
	struct stat			st;

	lstat(path, &st);
	return ((size_t)st.st_mtime);
}

int						is_dir(char *path, int flags)
{
	struct stat			st;
	int					ret;
	int					i;

	ret = lstat(path, &st);
	i = (((st.st_mode & S_IFDIR) != 0 || (S_ISLNK(st.st_mode))) && ret == 0);
	if (L_ON && S_ISLNK(st.st_mode))
		i = 0;
	return (i);
}

void					ft_ls(t_node *dir, int flags)
{
	DIR					*directory;
	struct dirent		*file;
	t_node				*dirs;
	t_node				*files;

	dirs = new_elem(FORBIDDEN_FILE, FORBIDDEN_FILE, 0);
	files = new_elem(FORBIDDEN_FILE, FORBIDDEN_FILE, 0);
	if ((!is_dir(dir->path, flags)))
	{
		render_file(dir, flags, NULL);
		return ;
	}
	if ((directory = opendir(dir->path)) == NULL)
	{
		perror("Error");
		return ;
	}
	while ((file = readdir(directory)) > 0 && (PUSH(files, file)) != NULL)
		if (ISADIR(file) && !IS(file->d_name, ".") &&
				!IS(file->d_name, "..") && RR_ON)
			PUSH(dirs, file);
	files = files->next;
	dirs = dirs->next;
	if ((ISHIDDEN(dir) && A_ON) || !ISHIDDEN(dir) || dir->first == TRUE)
		render_list(files, flags);
	free(files);
	closedir(directory);
	if (RR_ON)
		ft_ls_relaunch(dirs, flags);
	free(dirs);
}
