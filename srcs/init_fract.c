/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 17:25:30 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract_pow2(t_fract_m *fract_m)
{
	fract_m->xk = 0;
	fract_m->yk = 0;
	fract_m->xk2 = 0;
	fract_m->yk2 = 0;
}

void	init_fract_pow4(t_fract_m *fract_m)
{
	init_fract_pow2(fract_m);
	fract_m->xk4 = 0;
	fract_m->yk4 = 0;
}

void	init_julia(t_fract *fract, t_fract_m *fract_m, int i, int j)
{
	fract->p = fract->pmin + i * fract->dp + fract->x_move;
	fract->q = fract->qmin + j * fract->dq + fract->y_move;
	fract_m->p2 = fract->p * fract->p;
	fract_m->q2 = fract->q * fract->q;
}

void	init_julia_m(t_fract *fract, t_fract_m *fract_m, int i, int j)
{
	fract->p = fract->pmin + i * fract->dp + fract->x_move;
	fract->q = fract->qmin + j * fract->dq + fract->y_move;
	fract_m->p2 = fract->p * fract->p;
	fract_m->q2 = fract->q * fract->q;
	fract_m->p4 = fract_m->p2 * fract_m->p2;
	fract_m->q4 = fract_m->q2 * fract_m->q2;
}

void	init_fract(t_fract *fract, void *mlx_ptr)
{
	ft_bzero(fract, sizeof(t_fract));
	fract->iter = 100;
	fract->n_draw = 1;
	fract->pmin = PMIN;
	fract->pmax = PMAX;
	fract->qmin = QMIN;
	fract->qmax = QMAX;
	fract->cx = PJ0;
	fract->cy = QJ0;
	fract->mlx_ptr = mlx_ptr;
}
