/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:23 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:18:39 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom_1(int button, int x, int y, t_fract_m *fract)
{
	fract->fract1.zoom = (button == M_ZOOM_P) ? 1.1 : 1 / 1.1;
	fract->fract1.mp = (x - LEGENDA) * (fract->fract1.pmax\
		- fract->fract1.pmin) / (fract->f_width - 1) + fract->fract1.pmin;
	fract->fract1.mq = fract->fract1.qmin + y * (fract->fract1.qmax -\
		fract->fract1.qmin) / (fract->f_height - 1);
	fract->fract1.pmin = fract->fract1.pmin * fract->fract1.zoom\
		+ fract->fract1.mp * (1 - fract->fract1.zoom);
	fract->fract1.pmax = fract->fract1.pmax * fract->fract1.zoom\
		+ fract->fract1.mp * (1 - fract->fract1.zoom);
	fract->fract1.qmin = fract->fract1.qmin * fract->fract1.zoom +\
		fract->fract1.mq * (1 - fract->fract1.zoom);
	fract->fract1.qmax = fract->fract1.qmax * fract->fract1.zoom +\
		fract->fract1.mq * (1 - fract->fract1.zoom);
	mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
	fract->fract1.n_draw++;
	if (button == M_ZOOM_P)
	{
		if (fract->fract1.iter > 20)
			fract->fract1.iter -= 20;
	}
	else if (button == M_ZOOM_M)
		fract->fract1.iter += 20;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win, \
	fract->fract1.img_ptr, VBORD + LEGENDA, HBORD);
	legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
}

void	mouse_zoom_2(int button, int x, int y, t_fract_m *fract)
{
	fract->fract2.zoom = (button == M_ZOOM_P) ? 1.1 : 1 / 1.1;
	fract->fract2.mp = (x - LEGENDA) * (fract->fract2.pmax\
			- fract->fract2.pmin) / (fract->f_width - 1) + fract->fract2.pmin;
	fract->fract2.mq = fract->fract2.qmin + y * (fract->fract2.qmax -\
			fract->fract2.qmin) / (fract->f_height - 1);
	fract->fract2.pmin = fract->fract2.pmin * fract->fract2.zoom\
			+ fract->fract2.mp * (1 - fract->fract2.zoom);
	fract->fract2.pmax = fract->fract2.pmax * fract->fract2.zoom\
			+ fract->fract2.mp * (1 - fract->fract2.zoom);
	fract->fract2.qmin = fract->fract2.qmin * fract->fract2.zoom +\
			fract->fract2.mq * (1 - fract->fract2.zoom);
	fract->fract2.qmax = fract->fract2.qmax * fract->fract2.zoom +\
			fract->fract2.mq * (1 - fract->fract2.zoom);
	mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
	fract->fract2.n_draw++;
	if (button == M_ZOOM_P)
	{
		if (fract->fract2.iter > 20)
			fract->fract2.iter -= 20;
	}
	else if (button == M_ZOOM_M)
		fract->fract2.iter += 20;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win, \
	fract->fract2.img_ptr, VBORD + LEGENDA, HBORD);
	legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
}

int		mouse_press_1(int button, int x, int y, t_fract_m *fract)
{
	if (x >= LEGENDA && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (button == M_PRESS_1 || button == M_PRESS_2)
		{
			fract->fract1.mouse_pressed = 1;
			fract->fract1.mouse_x = x;
			fract->fract1.mouse_y = y;
			if (button == M_PRESS_1)
				fract->fract1.mouse_key = 1;
			else
				fract->fract1.mouse_key = 2;
		}
		if (button == M_ZOOM_P || button == M_ZOOM_M)
			mouse_zoom_1(button, x, y, fract);
	}
	return (1);
}

int		mouse_press_2(int button, int x, int y, t_fract_m *fract)
{
	if (x >= LEGENDA && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (button == M_PRESS_1 || button == M_PRESS_2)
		{
			fract->fract2.mouse_pressed = 1;
			fract->fract2.mouse_x = x;
			fract->fract2.mouse_y = y;
			if (button == M_PRESS_1)
				fract->fract2.mouse_key = 1;
			else
				fract->fract2.mouse_key = 2;
		}
		if (button == M_ZOOM_P || button == M_ZOOM_M)
			mouse_zoom_2(button, x, y, fract);
	}
	return (1);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_fract *fract;

	(void)x;
	(void)y;
	(void)button;
	fract = (t_fract *)param;
	fract->mouse_pressed = 0;
	return (1);
}
