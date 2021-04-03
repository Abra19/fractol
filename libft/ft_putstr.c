/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:18:03 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 20:40:24 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the string s to the standard output
** IN: string s to output
** OUT: void
*/

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s != 0)
	{
		while (*s != '\0' && s != 0)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
