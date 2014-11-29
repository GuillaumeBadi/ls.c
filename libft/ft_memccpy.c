/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:29:53 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/08 14:05:50 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	while (++i < n)
	{
		*(dest + i) = *(s + i);
		if (*(s + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
