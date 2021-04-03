/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:46:50 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/13 14:04:56 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare the null-terminated strings s1 and s2
** IN: string s1, s2
** OUT: int equal first difference *s1 - *s2 or 0
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
