/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:24:50 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/11 19:34:03 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (i < start)
		i++;
	while (i < len + start)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
