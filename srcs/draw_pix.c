/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:20:09 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/03 18:58:45 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_pixel_put(t_fract_m *fract, int x, int y, int color)
{
	int			point;

	if (x >= 0 && x < fract->image.width && y >= 0 &&\
		y < fract->image.height)
	{
		point = MAC_BPP * (x + y * fract->image.width);
		if (fract->n_win == 1)
		{
			fract->fract1.addr[point] = color;
			fract->fract1.addr[++point] = color >> 8;
			fract->fract1.addr[++point] = color >> 16;
		}
		if (fract->n_win == 2)
		{
			fract->fract2.addr[point] = color;
			fract->fract2.addr[++point] = color >> 8;
			fract->fract2.addr[++point] = color >> 16;
		}
	}
}
