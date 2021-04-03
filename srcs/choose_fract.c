/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  choose_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 20:45:33 by elena_abrarova   ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "fractol.h"

void	other_fract(char *str, int *n)
{
	if (ft_strcmp(str, "celtic_mandelbrot") == 0)
		*n = 4;
	else if (ft_strcmp(str, "celtic_julia") == 0)
		*n = 5;
	else if (ft_strcmp(str, "mandelbar_3") == 0)
		*n = 6;
	else if (ft_strcmp(str, "mandelbar_4") == 0)
		*n = 7;
	else if (ft_strcmp(str, "bird") == 0)
		*n = 8;
	else if (ft_strcmp(str, "heart") == 0)
		*n = 9;
	else if (ft_strcmp(str, "flower") == 0)
		*n = 10;
}

void	modern_julia(char *str, int *n)
{
	if (ft_strcmp(str, "julia3") == 0)
		*n = 11;
	else if (ft_strcmp(str, "julia4") == 0)
		*n = 12;
	else if (ft_strcmp(str, "julia5") == 0)
		*n = 13;
}

void	modern_mandelbrot(char *str, int *n)
{
	if (ft_strcmp(str, "mandelbrot3") == 0)
		*n = 14;
	else if (ft_strcmp(str, "mandelbrot4") == 0)
		*n = 15;
	else if (ft_strcmp(str, "mandelbrot5") == 0)
		*n = 16;
}

void	print_usage(void)
{
	ft_putendl("Usage: ./fractol [name_of_fractal] or ");
	ft_putendl("       ./fractol [name_of_fractal_1] [name_of_fractal_2]");
	ft_putendl("");
	ft_putendl("Enable names of_fractals:");
	ft_putendl("- mandelbrot, - julia, - burningship, - bird, - heart");
	ft_putendl("- celtic mandelbrot, - celtic_julia, - mandelbar_3, "
			"- mandelbar_4");
	ft_putendl("- julia3, - julia4, - julia5, - flower");
	ft_putendl("- mandelbrot3, - mandelbrot4, - mandelbrot5");
	exit(1);
}

int		choose_fract(char *str, int *n)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		*n = 1;
	else if (ft_strcmp(str, "julia") == 0)
		*n = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		*n = 3;
	else if (ft_strcmp(str, "mandelbar_3") == 0 ||\
	ft_strcmp(str, "mandelbar_4") == 0 || ft_strcmp(str, "bird") == 0 || \
	ft_strcmp(str, "heart") == 0 || ft_strcmp(str, "celtic_julia") == 0 ||\
	ft_strcmp(str, "celtic_mandelbrot") == 0 || ft_strcmp(str, "flower") == 0)
		other_fract(str, n);
	else if (ft_strcmp(str, "julia3") == 0 || ft_strcmp(str, "julia4") == 0\
	|| ft_strcmp(str, "julia5") == 0)
		modern_julia(str, n);
	else if (ft_strcmp(str, "mandelbrot3") == 0 ||\
	ft_strcmp(str, "mandelbrot4") == 0 || ft_strcmp(str, "mandelbrot5") == 0)
		modern_mandelbrot(str, n);
	else
	{
		print_usage();
		exit(1);
	}
	return (1);
}
