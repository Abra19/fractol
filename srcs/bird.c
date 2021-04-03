/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/09 19:27:50 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		bird_calc(t_fract *fract, t_fract_m *fract_m)
{
	int		k;
	float	tmpx;
	float	tmpy;

	k = 0;
	while (k < fract->iter)
	{
		if (fract_m->xk2 + fract_m->yk2 <= fract_m->r)
		{
			tmpx = ft_abs_float(fract_m->xk) *\
			(fract_m->xk2 - 3 * fract_m->yk2) + fract->p;
			tmpy = ft_abs_float(fract_m->yk) *\
			(3 * fract_m->xk2 - fract_m->yk2) + fract->q;
			fract_m->xk = tmpx;
			fract_m->yk = tmpy;
			fract_m->xk2 = fract_m->xk * fract_m->xk;
			fract_m->yk2 = fract_m->yk * fract_m->yk;
			k++;
		}
		else
			break ;
	}
	return (k);
}

void	draw_bird(t_fract *fract, t_fract_m *fract_m)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	fract->dp = (fract->pmax - fract->pmin) / (fract_m->f_width - 1);
	fract->dq = (fract->qmax - fract->qmin) / (fract_m->f_height - 1);
	while (j < fract_m->f_height)
	{
		i = fract_m->current;
		while (i < fract_m->next)
		{
			k = 0;
			fract->p = fract->pmin + i * fract->dp + fract->x_move;
			fract->q = fract->qmin + j * fract->dq + fract->y_move;
			fract->color = fract_m->f_palitra[fract->palitra_num][k];
			init_fract_pow2(fract_m);
			k = bird_calc(fract, fract_m);
			put_fract(fract, fract_m, k);
			image_pixel_put(fract_m, i, j, fract->color);
			i++;
		}
		j++;
	}
}

void	bird(t_fract_m *fract, int n)
{
	if (n == 1)
	{
		fract->n_win = 1;
		draw_bird(&fract->fract1, fract);
	}
	if (n == 2)
	{
		fract->n_win = 2;
		draw_bird(&fract->fract2, fract);
	}
}
