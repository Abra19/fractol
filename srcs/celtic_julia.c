/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 20:43:39 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		celtic_julia_calc(t_fract *fract, t_fract_m *fract_m)
{
	float	tmpx;
	float	tmpy;
	int		k;

	k = 0;
	while (k < fract->iter)
	{
		if (fract_m->p2 + fract_m->q2 <= fract_m->r)
		{
			tmpx = ft_abs_float(fract_m->p2 - fract_m->q2 + fract->cx);
			tmpy = 2 * fract->p * fract->q + fract->cy;
			fract->p = tmpx;
			fract->q = tmpy;
			fract_m->p2 = fract->p * fract->p;
			fract_m->q2 = fract->q * fract->q;
			k++;
		}
		else
			break ;
	}
	return (k);
}

void	draw_celtic_julia(t_fract *fract, t_fract_m *fract_m)
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
			fract->color = fract_m->f_palitra[fract->palitra_num][k];
			init_julia(fract, fract_m, i, j);
			k = celtic_julia_calc(fract, fract_m);
			put_fract_j(fract, fract_m, k);
			image_pixel_put(fract_m, i, j, fract->color);
			i++;
		}
		j++;
	}
}

void	celtic_julia(t_fract_m *fract, int n)
{
	if (n == 1)
	{
		fract->n_win = 1;
		draw_celtic_julia(&fract->fract1, fract);
	}
	if (n == 2)
	{
		fract->n_win = 2;
		draw_celtic_julia(&fract->fract2, fract);
	}
}
