/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:03:45 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:19:33 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s3;

	s3 = (char *)malloc(sizeof(char) * n);
	s3 = ft_strncpy(s3, (char *)s2, n);
	return (ft_strstr(s1, s3));
}
