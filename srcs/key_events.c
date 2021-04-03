/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:20:29 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 01:18:39 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_key_1(t_fract_m *fract, int key)
{
	if (key == E_KEY)
		expose_image_1(fract);
	else if (key == BLUE_KEY || key == GREEN_KEY || key == RED_KEY ||\
		key == PURP_KEY || key == MULT_KEY || key == DARK_KEY ||\
		key == LAST_KEY)
		change_color_1(key, fract);
	else if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY ||\
		key == RIGHT_KEY)
		move_1(key, fract);
}

void	init_key_2(t_fract_m *fract, int key)
{
	if (key == E_KEY)
		expose_image_2(fract);
	else if (key == BLUE_KEY || key == GREEN_KEY || key == RED_KEY ||\
		key == PURP_KEY || key == MULT_KEY || key == DARK_KEY ||\
		key == LAST_KEY)
		change_color_2(key, fract);
	else if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY ||\
		key == RIGHT_KEY)
		move_2(key, fract);
}

int		key_press_1(int key, void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	if (key == E_KEY || key == BLUE_KEY || key == GREEN_KEY || key == RED_KEY\
	|| key == PURP_KEY || key == MULT_KEY || key == DARK_KEY ||\
	key == LAST_KEY || key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY\
	|| key == RIGHT_KEY || key == P_KEY || key == M_KEY)
		init_key_1(fract, key);
	else if (key == ENTER_KEY && (fract->fract1.n_fract == 2 ||\
	fract->fract1.n_fract == 5 || fract->fract1.n_fract == 11 ||\
	fract->fract1.n_fract == 12 || fract->fract1.n_fract == 13))
		fract->fract1.julia_change = 1;
	else if (key == SPACE_KEY && (fract->fract1.n_fract == 2 ||\
	fract->fract1.n_fract == 5 || fract->fract1.n_fract == 11 ||\
	fract->fract1.n_fract == 12 || fract->fract1.n_fract == 13))
		fract->fract1.julia_change = 0;
	else if (key == QUIT_KEY)
	{
		mlx_clear_window(fract->mlx_ptr, fract->fract1.mlx_win);
		mlx_destroy_image(fract->mlx_ptr, fract->fract1.img_ptr);
		mlx_destroy_window(fract->mlx_ptr, fract->fract1.mlx_win);
		exit(0);
	}
	return (1);
}

int		key_press_2(int key, void *param)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)param;
	if (key == E_KEY || key == BLUE_KEY || key == GREEN_KEY || key == RED_KEY\
	|| key == PURP_KEY || key == MULT_KEY || key == DARK_KEY ||\
	key == LAST_KEY || key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY\
	|| key == RIGHT_KEY || key == P_KEY || key == M_KEY)
		init_key_2(fract, key);
	else if (key == ENTER_KEY && (fract->fract2.n_fract == 2 ||\
	fract->fract2.n_fract == 5 || fract->fract2.n_fract == 11 ||\
	fract->fract2.n_fract == 12 || fract->fract2.n_fract == 13))
		fract->fract2.julia_change = 1;
	else if (key == SPACE_KEY && (fract->fract2.n_fract == 2 ||\
	fract->fract2.n_fract == 5 || fract->fract2.n_fract == 11 ||\
	fract->fract2.n_fract == 12 || fract->fract2.n_fract == 13))
		fract->fract2.julia_change = 0;
	else if (key == QUIT_KEY)
	{
		mlx_clear_window(fract->mlx_ptr, fract->fract2.mlx_win);
		mlx_destroy_image(fract->mlx_ptr, fract->fract2.img_ptr);
		mlx_destroy_window(fract->mlx_ptr, fract->fract2.mlx_win);
	}
	return (1);
}
