/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:16:45 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/10 15:17:15 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** outputs the character c to the standard output
** IN: character to output
** OUT: void
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
