/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/04 20:52:19 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	process_type_fract(char *ptr1, char *ptr2, t_fract_m *fract)
{
	init_julia_param(ptr1, ptr2, fract);
	init_burningship_param(ptr1, ptr2, fract);
	init_mandelbar_4_param(ptr1, ptr2, fract);
	init_mandelbar_3_param(ptr1, ptr2, fract);
	init_bird_param(ptr1, ptr2, fract);
}

int		new_window_create(char *ptr1, char *ptr2, t_fract_m *fract)
{
	if ((fract->fract1.mlx_win = mlx_new_window(fract->mlx_ptr, fract->width,\
	fract->height, ptr1)) == NULL)
	{
		ft_putendl("creating of new window fall");
		return (0);
	}
	if (fract->flag_twoarg == 1)
	{
		if ((fract->fract2.mlx_win = mlx_new_window(fract->mlx_ptr,\
		fract->width, fract->height, ptr2)) == NULL)
		{
			ft_putendl("creating of new window fall");
			return (0);
		}
	}
	return (1);
}

int		init_param_fractals(t_fract_m *fract, char *str1, char *str2)
{
	char *ptr1;
	char *ptr2;

	ptr1 = ft_strjoin("1: ", str1);
	ptr2 = ft_strjoin("2: ", str2);
	process_type_fract(ptr1, ptr2, fract);
	if ((fract->mlx_ptr = mlx_init()) == NULL)
	{
		ft_putendl("start of drawing fall");
		return (0);
	}
	if (new_window_create(ptr1, ptr2, fract) == 0)
		return (0);
	ft_strdel(&ptr1);
	ft_strdel(&ptr2);
	return (1);
}

int		fract_image1(t_fract_m *fract)
{
	if ((fract->fract1.img_ptr = mlx_new_image(fract->mlx_ptr,\
	fract->image.width, fract->image.height)) == NULL)
	{
		ft_putendl("creating of new image fall");
		return (0);
	}
	fract->fract1.addr = mlx_get_data_addr(fract->fract1.img_ptr,\
	&(fract->image.bpp), &(fract->image.size_line), &(fract->image.endian));
	ft_bzero(fract->fract1.addr, fract->image.width * fract->image.height\
	* MAC_BPP);
	return (1);
}

int		init_mlx(t_fract_m *fract, char *str1, char *str2)
{
	if (init_param_fractals(fract, str1, str2) == 0)
		return (0);
	if (fract_image1(fract) == 0)
		return (0);
	if (fract->flag_twoarg == 1)
	{
		if ((fract->fract2.img_ptr = mlx_new_image(fract->mlx_ptr,\
		fract->image.width, fract->image.height)) == NULL)
		{
			ft_putendl("creating of new image fall");
			return (0);
		}
		fract->fract2.addr = mlx_get_data_addr(fract->fract2.img_ptr, \
		&(fract->image.bpp), &(fract->image.size_line), &(fract->image.endian));
		ft_bzero(fract->fract2.addr, fract->image.width * fract->image.height\
		* MAC_BPP);
	}
	return (1);
}
