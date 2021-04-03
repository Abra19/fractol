/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:12:07 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 13:58:55 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the first occurrence of c in the string pointed by str
** if c is '\0' function locate the terminating '\0'e
** IN: string str, symbol c
** OUT: pointer to c or NULL if c does not appear in the string
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	sym;

	if (str == 0)
		return (NULL);
	sym = (char)c;
	while (*str != '\0')
	{
		if (*str == sym)
			return ((char *)str);
		str++;
	}
	if (*str == sym)
		return ((char *)str);
	return (NULL);
}
