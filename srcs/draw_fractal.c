/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:38:43 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fract_m *fract)
{
	if (fract->flag_twoarg == 0)
	{
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
			fract->fract1.img_ptr, VBORD + LEGENDA, HBORD);
		legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
	}
	else
	{
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
			fract->fract1.img_ptr, VBORD + LEGENDA, HBORD);
		legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
			fract->fract2.img_ptr, VBORD + LEGENDA, HBORD);
		legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
	}
}
