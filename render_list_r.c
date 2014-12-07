/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_list_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:11:36 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:11:37 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				render_list_r(t_node *list, int flags)
{
	t_node			*current;
	t_length		*length;

	length = get_length(list, flags);
	current = list;
	if (current->next != NULL)
		render_list_r(current->next, flags);
	render_file(current, flags, length);
}
