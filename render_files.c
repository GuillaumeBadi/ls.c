/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:12:02 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:30:33 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					render_file(t_node *file, int flags, t_length *length)
{
	if (((ISHIDDEN(file) && A_ON) || !ISHIDDEN(file)) &&
			!IS(FORBIDDEN_FILE, file->name))
	{
		if (L_ON)
			render_details(file, flags, length);
		else
			ft_putendl(file->name);
	}
	return (1);
}
