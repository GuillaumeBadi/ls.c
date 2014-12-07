/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:41:07 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:17:19 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*push_elem(t_node *list, char *name, char *path, size_t time)
{
	t_node				*new;
	t_node				*current;

	current = list;
	new = new_elem(name, path, time);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}
