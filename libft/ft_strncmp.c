/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:52:59 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 22:01:02 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare n symbols of strings s1 and s2
** IN: string s1, s2, numbers of symbols n
** OUT: int equal first difference *s1 - *s2 or 0
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	if (n == 0 || (s1 == 0 && s2 == 0))
		return (0);
	if (*s1 == '\0')
		return (-*s2);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
