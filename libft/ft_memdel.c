/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:44:09 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 20:39:17 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fried memmory with adress given by parameter
** IN: pointer's adress that needs its memory freed and set to NULL
** OUT: void
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != 0 && *ap != 0)
	{
		free(*ap);
		*ap = NULL;
	}
}
