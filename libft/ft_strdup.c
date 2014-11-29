/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:25:09 by vbatiot           #+#    #+#             */
/*   Updated: 2014/11/10 18:18:09 by vbatiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *str)
{
	char		*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	dest = ft_strcpy(dest, str);
	return (dest);
}
