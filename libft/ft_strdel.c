/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:55:07 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:49:23 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fried memmory with adress given by parameter
** IN: string’s address that needs to be freed and its pointer set to NULL
** OUT: void
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as != 0 && *as != 0)
	{
		free(*as);
		*as = NULL;
	}
}
