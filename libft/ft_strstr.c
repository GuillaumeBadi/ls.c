/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:44:40 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/07 16:49:39 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len2;
	char	*str;

	str = (char *)s1;
	len2 = ft_strlen(s2);
	while (*str)
	{
		if (*str == s2[0] && ft_strncmp(str, s2, len2) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
