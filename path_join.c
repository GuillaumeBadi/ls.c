/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 14:17:38 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/07 14:50:07 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*path_join(char *path, char *name)
{
	char				*finale;

	finale = ft_strjoin(path, "/");
	finale = ft_strjoin(finale, name);
	return (finale);
}
