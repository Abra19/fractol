/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:20:51 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:06:49 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_x_1(void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
	mlx_destroy_image(fract->mlx_ptr, fract->fract1.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->fract1.mlx_win);
	exit(0);
}

int		close_x_2(void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
	mlx_destroy_image(fract->mlx_ptr, fract->fract2.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->fract2.mlx_win);
	return (1);
}

void	expose_image_1(t_fract_m *fract)
{
	mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
	fract->fract1.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract1.mlx_win,\
			fract->fract1.img_ptr, LEGENDA, 0);
	legenda(&fract->fract1, fract->fract1.mlx_win, fract->mlx_ptr);
}

void	expose_image_2(t_fract_m *fract)
{
	mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
	fract->fract2.n_draw++;
	fract_pthreads(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->fract2.mlx_win,\
			fract->fract2.img_ptr, LEGENDA, 0);
	legenda(&fract->fract2, fract->fract2.mlx_win, fract->mlx_ptr);
}
