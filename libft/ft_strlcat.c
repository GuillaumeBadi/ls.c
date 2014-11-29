/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:53:56 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/11 22:37:57 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_dest;
	size_t			len_src;
	size_t			i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dest)
		return (len_src + size);
	while (src[i] && len_dest + i + 1 < size)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_dest + len_src);
}
