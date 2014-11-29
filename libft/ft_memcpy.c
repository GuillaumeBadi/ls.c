/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:24:50 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/07 17:42:44 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	unsigned char		*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		*dest++ = (unsigned char)*s++;
		n--;
	}
	return (dst);
}
