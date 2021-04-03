/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:23 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:41:48 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fract_1(int x, int y, t_fract_m *fract)
{
	if (fract->fract1.mouse_pressed == 1 && (fract->fract1.mouse_key == 1\
			|| fract->fract1.mouse_key == 2))
	{
		fract->fract1.x_move -= (x - fract->fract1.mouse_xprev) * MOVE_MULT\
		/ fract->fract1.iter;
		fract->fract1.y_move -= (y - fract->fract1.mouse_yprev) * MOVE_MULT\
		/ fract->fract1.iter;
		mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
		fract->fract1.n_draw++;
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
			fract->fract1.img_ptr, LEGENDA, 0);
		legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
	}
}

void	move_julia_1(int x, int y, t_fract_m *fract)
{
	if ((fract->fract1.n_fract == 2 || fract->fract1.n_fract == 5 ||\
		fract->fract1.n_fract == 11 || fract->fract1.n_fract == 12 ||\
		fract->fract1.n_fract == 13) && fract->fract1.julia_change == 1)
	{
		fract->fract1.cx = 2.5 * (((float)x - LEGENDA) / fract->f_width - 0.5);
		fract->fract1.cy = 2.5 * (0.5 - (float)y / fract->f_height);
		mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
		fract->fract1.n_draw++;
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
			fract->fract1.img_ptr, LEGENDA, 0);
		legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
	}
}

int		mouse_move_1(int x, int y, void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	if (x >= LEGENDA && x <= fract->width && y >= 0 && y <= fract->height)
	{
		fract->fract1.mouse_xprev = fract->fract1.mouse_x;
		fract->fract1.mouse_x = x;
		fract->fract1.mouse_yprev = fract->fract1.mouse_y;
		fract->fract1.mouse_y = y;
		if (fract->fract1.mouse_pressed == 1 && (fract->fract1.mouse_key == 1\
			|| fract->fract1.mouse_key == 2))
			move_fract_1(x, y, fract);
		move_julia_1(x, y, fract);
	}
	return (1);
}
