/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 21:49:12 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_fract(t_fract_m *fract_m)
{
	fract_m->xk2 = fract_m->xk * fract_m->xk;
	fract_m->yk2 = fract_m->yk * fract_m->yk;
	fract_m->xk4 = fract_m->xk2 * fract_m->xk2;
	fract_m->yk4 = fract_m->yk2 * fract_m->yk2;
}

void	put_fract(t_fract *fract, t_fract_m *fract_m, int k)
{
	if (fract_m->xk2 + fract_m->yk2 > fract_m->r)
		fract->color = fract_m->f_palitra[fract->palitra_num][k % NCOL];
	else if (k % NCOL == 0)
		fract->color = fract_m->f_palitra[fract->palitra_num][0];
}

void	put_fract_j(t_fract *fract, t_fract_m *fract_m, int k)
{
	if (fract_m->p2 + fract_m->q2 > fract_m->r)
		fract->color = fract_m->f_palitra[fract->palitra_num][k % NCOL];
	else if (k % NCOL == 0)
		fract->color = fract_m->f_palitra[fract->palitra_num][0];
}

void	put_fract_image(t_fract_m *fract)
{
	if (fract->flag_twoarg == 1)
	{
		mlx_hook(fract->fract2.mlx_win, 2, 0, key_press_2, fract);
		mlx_hook(fract->fract2.mlx_win, 4, 0, mouse_press_2, fract);
		mlx_hook(fract->fract2.mlx_win, 5, 0, mouse_release, &fract->fract2);
		mlx_hook(fract->fract2.mlx_win, 6, 0, mouse_move_2, fract);
		mlx_hook(fract->fract2.mlx_win, 17, 0, close_x_2, fract);
	}
	mlx_hook(fract->fract1.mlx_win, 2, 0, key_press_1, fract);
	mlx_hook(fract->fract1.mlx_win, 4, 0, mouse_press_1, fract);
	mlx_hook(fract->fract1.mlx_win, 5, 0, mouse_release, &fract->fract1);
	mlx_hook(fract->fract1.mlx_win, 6, 0, mouse_move_1, fract);
	mlx_hook(fract->fract1.mlx_win, 17, 0, close_x_1, fract);
}
