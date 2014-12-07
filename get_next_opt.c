/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:18:25 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:18:29 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*get_next_opt(int ac, char **av)
{
	static int			index = 1;

	if (index == ac)
		return (0);
	while (av[index][0] != '-')
	{
		if (index + 1 >= ac)
			return (0);
		index++;
	}
	return (ft_strdup(av[index++]));
}
