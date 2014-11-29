/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:38:40 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:28:22 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
