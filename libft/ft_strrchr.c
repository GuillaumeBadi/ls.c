/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:19:03 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/07 18:21:02 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	while (len--)
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	return (NULL);
}
