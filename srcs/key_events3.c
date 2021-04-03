/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:20:51 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 17:04:14 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_1(int key, t_fract_m *fract)
{
	if (key == UP_KEY)
		fract->fract1.y_move += ft_abs_float(fract->fract1.qmin\
		- fract->fract1.qmax) * MULT;
	else if (key == DOWN_KEY)
		fract->fract1.y_move -= ft_abs_float(fract->fract1.qmin\
		- fract->fract1.qmax) * MULT;
	else if (key == LEFT_KEY)
		fract->fract1.x_move += ft_abs_float(fract->fract1.pmin\
		- fract->fract1.pmax) * MULT;
	else if (key == RIGHT_KEY)
		fract->fract1.x_move -= ft_abs_float(fract->fract1.pmin\
		- fract->fract1.pmax) * MULT;
	mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
	fract->fract1.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
	fract->fract1.img_ptr, LEGENDA, 0);
	legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
}

void	move_2(int key, t_fract_m *fract)
{
	if (key == UP_KEY)
		fract->fract2.y_move += ft_abs_float(fract->fract2.qmin\
		- fract->fract2.qmax) * MULT;
	else if (key == DOWN_KEY)
		fract->fract2.y_move -= ft_abs_float(fract->fract2.qmin\
		- fract->fract2.qmax) * MULT;
	else if (key == LEFT_KEY)
		fract->fract2.x_move += ft_abs_float(fract->fract2.pmin\
		- fract->fract2.pmax) * MULT;
	else if (key == RIGHT_KEY)
		fract->fract2.x_move -= ft_abs_float(fract->fract2.pmin\
		- fract->fract2.pmax) * MULT;
	mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
	fract->fract2.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
	fract->fract2.img_ptr, LEGENDA, 0);
	legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
}
