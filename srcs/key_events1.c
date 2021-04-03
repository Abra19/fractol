/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:20:40 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:38:43 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_2(int key, t_fract_m *fract)
{
	if (key == BLUE_KEY)
		fract->fract2.palitra_num = 0;
	else if (key == GREEN_KEY)
		fract->fract2.palitra_num = 1;
	else if (key == RED_KEY)
		fract->fract2.palitra_num = 2;
	else if (key == PURP_KEY)
		fract->fract2.palitra_num = 3;
	else if (key == MULT_KEY)
		fract->fract2.palitra_num = 4;
	else if (key == DARK_KEY)
		fract->fract2.palitra_num = 5;
	else if (key == LAST_KEY)
		fract->fract2.palitra_num = 6;
	mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
	fract->fract2.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
	fract->fract2.img_ptr, LEGENDA, 0);
	legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
}

void	change_color_1(int key, t_fract_m *fract)
{
	if (key == BLUE_KEY)
		fract->fract1.palitra_num = 0;
	else if (key == GREEN_KEY)
		fract->fract1.palitra_num = 1;
	else if (key == RED_KEY)
		fract->fract1.palitra_num = 2;
	else if (key == PURP_KEY)
		fract->fract1.palitra_num = 3;
	else if (key == MULT_KEY)
		fract->fract1.palitra_num = 4;
	else if (key == DARK_KEY)
		fract->fract1.palitra_num = 5;
	else if (key == LAST_KEY)
		fract->fract1.palitra_num = 6;
	mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
	fract->fract1.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
	fract->fract1.img_ptr, LEGENDA, 0);
	legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
}
