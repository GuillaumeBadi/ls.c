/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int_colum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 12:29:53 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 12:30:27 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*format_int_column(int number, int orientation, int len)
{
	char			*str;

	str = ft_itoa(number);
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
