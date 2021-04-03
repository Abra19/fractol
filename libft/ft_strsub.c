/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:58:35 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/12 15:13:36 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a “fresh” substring from the string given as argument
** the substring begins at index = start and is of size len
** if start and len don’t refering to a valid substring - behavior is undef
** if the allocation fails, the function returns NULL
** IN: string s from which create the substring
** IN: start index of the first element of substring
** IN: size of the substring len
** OUT: substring
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned long	i;

	i = 0;
	if (len == 9223372036854775807 || s == 0)
		return (NULL);
	res = (char *)malloc((len + 1) * sizeof(*res));
	if (res == 0)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
