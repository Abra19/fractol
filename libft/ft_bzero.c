/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:35:32 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/14 17:46:25 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** writes n zeroed bytes to the string str
** if n is zero bzero() does nothin
** IN: string str, bytes number n
** OUT: void
*/

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char*)str;
	if (n != 0)
	{
		while (i < n)
		{
			ptr[i] = 0;
			i++;
		}
	}
}
