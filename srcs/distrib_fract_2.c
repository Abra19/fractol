/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib_fract_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:19:56 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 18:56:55 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	distrib_fract5(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 15 || fract->fract2.n_fract == 15)
	{
		if (fract->fract1.n_fract == 15)
			mandelbrot_4(fract, 1);
		if (fract->fract2.n_fract == 15)
			mandelbrot_4(fract, 2);
	}
	if (fract->fract1.n_fract == 16 || fract->fract2.n_fract == 16)
	{
		if (fract->fract1.n_fract == 16)
			mandelbrot_5(fract, 1);
		if (fract->fract2.n_fract == 16)
			mandelbrot_5(fract, 2);
	}
}

void	distrib_fract4(t_fract_m *fract)
{
	if (fract->fract1.n_fract == 12 || fract->fract2.n_fract == 12)
	{
		if (fract->fract1.n_fract == 12)
			julia_4(fract, 1);
		if (fract->fract2.n_fract == 12)
			julia_4(fract, 2);
	}
	if (fract->fract1.n_fract == 13 || fract->fract2.n_fract == 13)
	{
		if (fract->fract1.n_fract == 13)
			julia_5(fract, 1);
		if (fract->fract2.n_fract == 13)
			julia_5(fract, 2);
	}
	if (fract->fract1.n_fract == 14 || fract->fract2.n_fract == 14)
	{
		if (fract->fract1.n_fract == 14)
			mandelbrot_3(fract, 1);
		if (fract->fract2.n_fract == 14)
			mandelbrot_3(fract, 2);
	}
}
