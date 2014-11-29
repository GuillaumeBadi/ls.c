/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:58:27 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:25:10 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*cpy;

	cpy = malloc(len);
	ft_memcpy(cpy, src, len);
	ft_memcpy(dst, cpy, len);
	free(cpy);
	return (dst);
}
