/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:33:06 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:06:25 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** append a copy of s2 to the end of s1 then add '\0'
** s1 must have sufficient space to hold the result
** s1 and s2 should not overlap as the behavior is undefined
** IN: strings s1 and s2
** OUT: *s1
*/

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
