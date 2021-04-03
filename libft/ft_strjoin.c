/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:12:41 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/11 21:27:20 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a “fresh” string ending with ’\0’
** result of the concatenation of s1 and s2
** if the allocation fails the function returns NULLe
** IN: strings s1 and s2
** OUT: The “fresh” string result of the concatenation of the 2 strings
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	size;
	char			*res;

	if ((s1 != 0) && (s2 != 0))
		size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	else if (s1 != 0)
		size = ft_strlen((char*)s1);
	else if (s2 != 0)
		size = ft_strlen((char*)s2);
	else
		return (0);
	if ((size) == 9223372036854775807)
		return (NULL);
	res = ft_memalloc(size + 1);
	if (res == 0)
		return (NULL);
	if (s1 != 0)
		res = ft_strcpy(res, (char*)s1);
	else
		res = ft_strcpy(res, (char*)s2);
	if (s1 != 0 && s2 != 0)
		res = ft_strcat(res, (char*)s2);
	return (res);
}
