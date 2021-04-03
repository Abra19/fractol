/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouve_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:23 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:57:49 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fract_2(int x, int y, t_fract_m *fract)
{
	if (fract->fract2.mouse_pressed == 1 && (fract->fract2.mouse_key == 1\
			|| fract->fract2.mouse_key == 2))
	{
		fract->fract2.x_move -= (x - fract->fract2.mouse_xprev) * MOVE_MULT\
		/ fract->fract2.iter;
		fract->fract2.y_move -= (y - fract->fract2.mouse_yprev) * MOVE_MULT\
		/ fract->fract2.iter;
		mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
		fract->fract2.n_draw++;
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
			fract->fract2.img_ptr, LEGENDA, 0);
		legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
	}
}

void	move_julia_2(int x, int y, t_fract_m *fract)
{
	if ((fract->fract2.n_fract == 2 || fract->fract2.n_fract == 5 ||\
		fract->fract2.n_fract == 11 || fract->fract2.n_fract == 12 ||\
		fract->fract2.n_fract == 13) && fract->fract2.julia_change == 1)
	{
		fract->fract2.cx = 2.5 * (((float)x - LEGENDA) / fract->f_width - 0.5);
		fract->fract2.cy = 2.5 * (0.5 - (float)y / fract->f_height);
		mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
		fract->fract2.n_draw++;
		fract_pthreads(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
			fract->fract2.img_ptr, LEGENDA, 0);
		legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
	}
}

int		mouse_move_2(int x, int y, void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	if (x >= LEGENDA && x <= fract->width && y >= 0 && y <= fract->height)
	{
		fract->fract2.mouse_xprev = fract->fract2.mouse_x;
		fract->fract2.mouse_x = x;
		fract->fract2.mouse_yprev = fract->fract2.mouse_y;
		fract->fract2.mouse_y = y;
		if (fract->fract2.mouse_pressed == 1 && (fract->fract2.mouse_key == 1\
			|| fract->fract2.mouse_key == 2))
			move_fract_2(x, y, fract);
		move_julia_2(x, y, fract);
	}
	return (1);
}
