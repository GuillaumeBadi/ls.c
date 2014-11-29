/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:27:51 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:15:39 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\n'
			|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			result;
	int			i;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - 48;
	return (result * sign);
}
