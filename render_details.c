/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_details.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:11:17 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:13:35 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				render_details(t_node *file, int flags, t_length *length)
{
	struct stat			st;

	lstat(file->path, &st);
	ft_putstr(ft_filepermission(&st));
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(format_int_column(st.st_nlink, RIGHT, (length) ?
				length->links : 0));
	ft_putchar(' ');
	ft_putstr(format_str_column(getpwuid(st.st_uid)->pw_name, LEFT, (length) ?
				length->pw : 0));
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(format_str_column(getgrgid(st.st_gid)->gr_name, LEFT, (length) ?
				length->gr : 0));
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(format_int_column(st.st_size, RIGHT, (length) ?
				length->size : 0));
	ft_putchar(' ');
	print_date(ctime(&st.st_mtime));
	ft_putchar(' ');
	ft_putendl(file->name);
}
