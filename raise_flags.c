/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:13:55 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:34:18 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				fuck_la_norme(void)
{
	ft_putstr("ls: illegal option -- y\nusage: ls");
	ft_putstr("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	exit(1);
}

void					raise_flags(int ac, char **av, int *flags)
{
	char				*opt;
	size_t				i;

	i = 1;
	while ((opt = get_next_opt(ac, av)) != 0)
	{
		while (i < ft_strlen(opt))
		{
			if (opt[i] == 'R')
				*flags |= RR_FLAG;
			else if (opt[i] == 'r')
				*flags |= R_FLAG;
			else if (opt[i] == 'a')
				*flags |= A_FLAG;
			else if (opt[i] == 'l')
				*flags |= L_FLAG;
			else if (opt[i] == 't')
				*flags |= T_FLAG;
			else
				fuck_la_norme();
			i++;
		}
		i = 1;
	}
}
