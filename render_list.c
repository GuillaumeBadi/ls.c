/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:11:51 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:11:52 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					render_list(t_node *list, int flags)
{
	t_node				*current;
	t_length			*length;

	if (L_ON)
		length = get_length(list, flags);
	if (R_ON)
	{
		render_list_r(list, flags);
		return ;
	}
	current = list;
	while (current != NULL)
	{
		render_file(current, flags, (L_ON) ? length : NULL);
		current = current->next;
	}
}
