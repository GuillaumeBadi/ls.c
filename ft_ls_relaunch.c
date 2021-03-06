/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_relaunch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 12:31:17 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:22:14 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_ls_relaunch(t_node *dirs, int flags)
{
	t_node				*current;

	current = dirs;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		if ((A_ON && ISHIDDEN(current)) || !ISHIDDEN(current))
		{
			ft_putchar('\n');
			ft_putstr(current->path);
			ft_putstr(":\n");
		}
		ft_ls(current, flags);
		current = current->next;
	}
}
