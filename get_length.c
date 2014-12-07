/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:18:11 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:18:17 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_length			*bzl(t_length *len)
{
	t_length			*length;

	length = (t_length *)malloc(sizeof(t_length));
	length->size = 0;
	length->links = 0;
	length->pw = 0;
	length->gr = 0;
	return (length);
}

static t_length			*update(t_length *length, struct stat *st)
{
	if (ft_intlen((int)st->st_size) > length->size)
		length->size = (size_t)ft_intlen(st->st_size);
	if (ft_intlen((int)st->st_nlink) > length->links)
		length->links = (size_t)ft_intlen(st->st_nlink);
	if (ft_strlen(getgrgid(st->st_gid)->gr_name) > length->gr)
		length->gr = ft_strlen(getgrgid(st->st_gid)->gr_name);
	if (ft_strlen(getpwuid(st->st_uid)->pw_name) > length->pw)
		length->pw = ft_strlen(getpwuid(st->st_uid)->pw_name);
	return (length);
}

t_length				*get_length(t_node *list, int flags)
{
	struct stat			st;
	t_length			*length;
	t_node				*current;

	length = bzl(length);
	current = list;
	while (current != NULL)
	{
		lstat(current->path, &st);
		length = update(length, &st);
		current = current->next;
	}
	return (length);
}
