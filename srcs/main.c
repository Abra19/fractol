/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 21:00:01 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract_m(t_fract_m *fract)
{
	ft_bzero(fract, sizeof(*fract));
	fract->width = WIDTH;
	fract->height = HEIGHT;
	fract->f_width = WIDTH - LEGENDA;
	fract->f_height = HEIGHT;
	fract->image.width = fract->width;
	fract->image.height = fract->height;
	fract->image.bpp = MAC_BPP * 8;
	fract->image.size_line = fract->image.width * MAC_BPP;
	fract->image.endian = 0;
	fract->r = 100;
	init_fract(&fract->fract1, fract->mlx_ptr);
	init_fract(&fract->fract2, fract->mlx_ptr);
}

void	parse_param_fract(int argc, char *str1, char *str2, t_fract_m *fract)
{
	if (argc == 2)
		choose_fract(str1, &fract->fract1.n_fract);
	else
	{
		choose_fract(str1, &fract->fract1.n_fract);
		choose_fract(str2, &fract->fract2.n_fract);
		fract->flag_twoarg = 1;
	}
}

int		main(int argc, char **argv)
{
	t_fract_m	fract;

	init_fract_m(&fract);
	if (argc != 2 && argc != 3)
	{
		print_usage();
		exit(1);
	}
	else
	{
		parse_param_fract(argc, argv[1], argv[2], &fract);
		init_color(&fract);
		if (init_mlx(&fract, argv[1], argv[2]) == 0)
			return (1);
		draw_fractal(&fract);
	}
	put_fract_image(&fract);
	mlx_loop(fract.mlx_ptr);
	return (0);
}
