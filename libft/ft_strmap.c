/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:26:08 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:28:46 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*dest;
	int			i;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
