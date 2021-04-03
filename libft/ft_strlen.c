/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:54 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/06 20:08:48 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** computes the length of the string str
** IN: string str
** OUT: lenght of string str without '\0'
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned long len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
