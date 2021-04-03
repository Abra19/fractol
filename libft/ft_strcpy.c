/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:13:37 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:05:35 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy the string src to dst including '\0'
** src and dst should not overlap as the behavior is undefined
** IN: string src
** OUT: *dst
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	if (src == 0 || dst == 0)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
