/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_fractals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 20:52:54 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia_param(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if (ft_strncmp(ptr1, "1: julia", 8) == 0 ||\
		ft_strncmp(ptr1, "1: celtic_julia", 15) == 0 ||\
		ft_strncmp(ptr1, "1: flower", 9) == 0 ||\
		ft_strncmp(ptr1, "1: mandelbrot3", 14) == 0 ||\
		ft_strncmp(ptr1, "1: mandelbrot4", 14) == 0 ||\
		ft_strncmp(ptr1, "1: mandelbrot5", 14) == 0)
	{
		fract->fract1.pmin = JPMIN;
		fract->fract1.pmax = JPMAX;
		fract->fract1.qmin = JQMIN;
		fract->fract1.qmax = JQMAX;
	}
	if (ft_strncmp(ptr2, "2: julia", 8) == 0 ||\
		ft_strncmp(ptr2, "2: celtic_julia", 15) == 0 ||\
		ft_strncmp(ptr2, "2: flower", 9) == 0 ||\
		ft_strncmp(ptr2, "2: mandelbrot3", 14) == 0 ||\
		ft_strncmp(ptr2, "2: mandelbrot4", 14) == 0 ||\
		ft_strncmp(ptr2, "2: mandelbrot5", 14) == 0)
	{
		fract->fract2.pmin = JPMIN;
		fract->fract2.pmax = JPMAX;
		fract->fract2.qmin = JQMIN;
		fract->fract2.qmax = JQMAX;
	}
}

void	init_burningship_param(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if (ft_strncmp(ptr1, "1: burningship", 8) == 0)
	{
		fract->fract1.pmin = BPMIN;
		fract->fract1.pmax = BPMAX;
		fract->fract1.qmin = BQMIN;
		fract->fract1.qmax = BQMAX;
	}
	if (ft_strncmp(ptr2, "2: burningship", 8) == 0)
	{
		fract->fract2.pmin = BPMIN;
		fract->fract2.pmax = BPMAX;
		fract->fract2.qmin = BQMIN;
		fract->fract2.qmax = BQMAX;
	}
}

void	init_mandelbar_4_param(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if (ft_strncmp(ptr1, "1: mandelbar_4", 14) == 0)
	{
		fract->fract1.pmin = MPMIN;
		fract->fract1.pmax = MPMAX;
		fract->fract1.qmin = MQMIN;
		fract->fract1.qmax = MQMAX;
	}
	if (ft_strncmp(ptr2, "2: mandelbar_4", 14) == 0)
	{
		fract->fract2.pmin = MPMIN;
		fract->fract2.pmax = MPMAX;
		fract->fract2.qmin = MQMIN;
		fract->fract2.qmax = MQMAX;
	}
}

void	init_mandelbar_3_param(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if (ft_strncmp(ptr1, "1: mandelbar_3", 14) == 0)
	{
		fract->fract1.pmin = MSPMIN;
		fract->fract1.pmax = MSPMAX;
		fract->fract1.qmin = MSQMIN;
		fract->fract1.qmax = MSQMAX;
	}
	if (ft_strncmp(ptr2, "2: mandelbar_3", 14) == 0)
	{
		fract->fract2.pmin = MPMIN;
		fract->fract2.pmax = MPMAX;
		fract->fract2.qmin = MQMIN;
		fract->fract2.qmax = MQMAX;
	}
}

void	init_bird_param(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if (ft_strncmp(ptr1, "1: bird", 7) == 0)
	{
		fract->fract1.pmin = BDPMIN;
		fract->fract1.pmax = BDPMAX;
		fract->fract1.qmin = BDQMIN;
		fract->fract1.qmax = BDQMAX;
	}
	if (ft_strncmp(ptr2, "2: bird", 7) == 0)
	{
		fract->fract2.pmin = BDPMIN;
		fract->fract2.pmax = BDPMAX;
		fract->fract2.qmin = BDQMIN;
		fract->fract2.qmax = BDQMAX;
	}
}
