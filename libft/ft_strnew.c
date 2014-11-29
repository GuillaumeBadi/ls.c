/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:20:05 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:26:08 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *dst;

	dst = (char *)malloc(sizeof(char) * size + 1);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size + 1);
	return (dst);
}
