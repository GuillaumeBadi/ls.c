/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:17:56 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:51:16 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node					*new_elem(char *name, char *path, size_t time)
{
	t_node				*elem;

	elem = (t_node *)malloc(sizeof(t_node));
	elem->name = ft_strdup(name);
	elem->first = FALSE;
	elem->path = ft_strdup(path);
	elem->time = time;
	elem->next = NULL;
	return (elem);
}
