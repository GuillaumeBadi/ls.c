/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:54:54 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/08 16:45:21 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f'
			|| c == '\n' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len]))
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
