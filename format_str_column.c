/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str_column.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 12:30:11 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 12:30:26 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*format_str_column(char *str, int orientation, int len)
{
	if (len)
	{
		while (ft_strlen(str) < len)
		{
			if (orientation == LEFT)
				str = ft_strjoin(str, " ");
			else
				str = ft_strjoin(" ", str);
		}
	}
	return (str);
}
