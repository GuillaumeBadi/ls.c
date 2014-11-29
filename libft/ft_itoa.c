/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:02:59 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:21:12 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_nbr(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbr(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = len;
	len--;
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (n > 0)
	{
		result[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	result[i] = '\0';
	return (result);
}
