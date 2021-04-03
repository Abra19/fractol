/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:40:48 by dlaure            #+#    #+#             */
/*   Updated: 2019/09/09 19:42:08 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates and returns a “fresh” memory area
** memory allocated is initialized to 0
** if the allocation fails, the function returns NULL
** IN: size of the memory that needs to be allocated
** OUT: pointer to allocated memory area
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == 0)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
