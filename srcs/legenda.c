/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legenda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:00 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 17:06:17 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	legenda2(void *mlx_ptr, int *h, void *mlx_win)
{
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Color spectrum: ");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"black-blue = 1");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"green      = 2");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"yellow     = 3");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"purple     = 4");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"multicolor = 5");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"blue       = 6");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 15, 0xffffff,\
	"blue-white = 7");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Zoom: ");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"mouse scroll");
}

void	legenda3(void *mlx_ptr, int *h, void *mlx_win)
{
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Move image:");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"arrows");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"mouse left or right");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Change Julia:");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"Enter");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Stop Julia change:");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"Space");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 35, 0xb8860b,\
	"Quit:");
	mlx_string_put(mlx_ptr, mlx_win, 15, *h = *h + 20, 0xffffff,\
	"Esc");
}

void	legenda(t_fract *fract, void *mlx_win, void *mlx_ptr)
{
	int		h;
	char	*str;

	h = 10;
	str = ft_itoa(fract->n_draw);
	mlx_string_put(mlx_ptr, mlx_win, 15, h, 0xb8860b,\
	"Number of image:");
	mlx_string_put(mlx_ptr, mlx_win, 15, h += 20, 0xffffff, str);
	ft_strdel(&str);
	mlx_string_put(mlx_ptr, mlx_win, 15, h += 35, 0xb8860b,\
	"Expose:");
	mlx_string_put(mlx_ptr, mlx_win, 15, h += 20, 0xffffff,\
	"E");
	str = ft_itoa(fract->iter);
	mlx_string_put(mlx_ptr, mlx_win, 15, h += 35, 0xb8860b,\
	"Number of iterations:");
	mlx_string_put(mlx_ptr, mlx_win, 15, h += 20, 0xffffff, str);
	ft_strdel(&str);
	legenda2(mlx_ptr, &h, mlx_win);
	legenda3(mlx_ptr, &h, mlx_win);
}
