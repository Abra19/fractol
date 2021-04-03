/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:19:56 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 18:56:55 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	distrib_fract3(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 9 || fract->fract2.n_fract == 9)
	{
		if (fract->fract1.n_fract == 9)
			heart(fract, 1);
		if (fract->fract2.n_fract == 9)
			heart(fract, 2);
	}
	if (fract->fract1.n_fract == 10 || fract->fract2.n_fract == 10)
	{
		if (fract->fract1.n_fract == 10)
			flower(fract, 1);
		if (fract->fract2.n_fract == 10)
			flower(fract, 2);
	}
	if (fract->fract1.n_fract == 11 || fract->fract2.n_fract == 11)
	{
		if (fract->fract1.n_fract == 11)
			julia_3(fract, 1);
		if (fract->fract2.n_fract == 11)
			julia_3(fract, 2);
	}
}

void	distrib_fract2(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 6 || fract->fract2.n_fract == 6)
	{
		if (fract->fract1.n_fract == 6)
			mandelbar_3(fract, 1);
		if (fract->fract2.n_fract == 6)
			mandelbar_3(fract, 2);
	}
	if (fract->fract1.n_fract == 7 || fract->fract2.n_fract == 7)
	{
		if (fract->fract1.n_fract == 7)
			mandelbar_4(fract, 1);
		if (fract->fract2.n_fract == 7)
			mandelbar_4(fract, 2);
	}
	if (fract->fract1.n_fract == 8 || fract->fract2.n_fract == 8)
	{
		if (fract->fract1.n_fract == 8)
			bird(fract, 1);
		if (fract->fract2.n_fract == 8)
			bird(fract, 2);
	}
}

void	distrib_fract1(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 3 || fract->fract2.n_fract == 3)
	{
		if (fract->fract1.n_fract == 3)
			burningship(fract, 1);
		if (fract->fract2.n_fract == 3)
			burningship(fract, 2);
	}
	if (fract->fract1.n_fract == 4 || fract->fract2.n_fract == 4)
	{
		if (fract->fract1.n_fract == 4)
			celtic_mandelbrot(fract, 1);
		if (fract->fract2.n_fract == 4)
			celtic_mandelbrot(fract, 2);
	}
	if (fract->fract1.n_fract == 5 || fract->fract2.n_fract == 5)
	{
		if (fract->fract1.n_fract == 5)
			celtic_julia(fract, 1);
		if (fract->fract2.n_fract == 5)
			celtic_julia(fract, 2);
	}
}

void	distrib_fract0(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 1 || fract->fract2.n_fract == 1)
	{
		if (fract->fract1.n_fract == 1)
			mandelbrot(fract, 1);
		if (fract->fract2.n_fract == 1)
			mandelbrot(fract, 2);
	}
	if (fract->fract1.n_fract == 2 || fract->fract2.n_fract == 2)
	{
		if (fract->fract1.n_fract == 2)
			julia(fract, 1);
		if (fract->fract2.n_fract == 2)
			julia(fract, 2);
	}
}

int		distrib_fract(t_fract_m *fract)
{
	distrib_fract0(fract);
	distrib_fract1(fract);
	distrib_fract2(fract);
	distrib_fract3(fract);
	distrib_fract4(fract);
	distrib_fract5(fract);
	return (1);
}
