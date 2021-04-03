/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 20:50:45 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		heart_calc(t_fract *fract, t_fract_m *fract_m)
{
	int		k;
	float	tmpx;
	float	tmpy;

	k = 0;
	while (k < fract->iter)
	{
		if (fract_m->xk2 + fract_m->yk2 <= fract_m->r)
		{
			tmpx = fract_m->xk2 - fract_m->yk2 + fract->p;
			tmpy = -2 * ft_abs_float(fract_m->xk) * fract_m->yk + fract->q;
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

void	draw_heart(t_fract *fract, t_fract_m *fract_m)
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
			fract->p = fract->pmin + i * fract->dp + fract->x_move;
			fract->q = fract->qmin + j * fract->dq + fract->y_move;
			k = 0;
			fract->color = fract_m->f_palitra[fract->palitra_num][k];
			init_fract_pow2(fract_m);
			k = heart_calc(fract, fract_m);
			put_fract(fract, fract_m, k);
			image_pixel_put(fract_m, i, j, fract->color);
			i++;
		}
		j++;
	}
}

void	heart(t_fract_m *fract, int n)
{
	if (n == 1)
	{
		fract->n_win = 1;
		draw_heart(&fract->fract1, fract);
	}
	if (n == 2)
	{
		fract->n_win = 2;
		draw_heart(&fract->fract2, fract);
	}
}
