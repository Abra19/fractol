/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_color1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:19:56 by dlaure            #+#    #+#             */
/*   Updated: 2020/02/29 19:19:59 by dlaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color_6(t_fract_m *fract)
{
	fract->f_palitra[5][0] = D1;
	fract->f_palitra[5][1] = D2;
	fract->f_palitra[5][2] = D3;
	fract->f_palitra[5][3] = D4;
	fract->f_palitra[5][4] = D5;
	fract->f_palitra[5][5] = D6;
	fract->f_palitra[5][6] = D7;
	fract->f_palitra[5][7] = D8;
	fract->f_palitra[5][8] = D9;
	fract->f_palitra[5][9] = D10;
	fract->f_palitra[5][10] = D11;
	fract->f_palitra[5][11] = D12;
	fract->f_palitra[5][12] = D13;
	fract->f_palitra[5][13] = D14;
	fract->f_palitra[5][14] = D15;
	fract->f_palitra[5][15] = D16;
	fract->f_palitra[5][16] = D17;
	fract->f_palitra[5][17] = D18;
	fract->f_palitra[5][18] = D19;
	fract->f_palitra[5][19] = D20;
	fract->f_palitra[5][20] = D21;
}

void	init_color_7(t_fract_m *fract)
{
	fract->f_palitra[6][0] = BLACK;
	fract->f_palitra[6][1] = WHITE;
	fract->f_palitra[6][2] = NAVY;
	fract->f_palitra[6][3] = OTBLUE;
	fract->f_palitra[6][4] = DARKBLUE;
	fract->f_palitra[6][5] = NAVY;
	fract->f_palitra[6][6] = BLACK;
	fract->f_palitra[6][7] = WHITE;
	fract->f_palitra[6][8] = NAVY;
	fract->f_palitra[6][9] = BLACK;
	fract->f_palitra[6][10] = WHITE;
	fract->f_palitra[6][11] = NAVY;
	fract->f_palitra[6][12] = BLACK;
	fract->f_palitra[6][13] = WHITE;
	fract->f_palitra[6][14] = NAVY;
	fract->f_palitra[6][15] = BLACK;
	fract->f_palitra[6][16] = WHITE;
	fract->f_palitra[6][17] = NAVY;
	fract->f_palitra[6][18] = BLACK;
	fract->f_palitra[6][19] = WHITE;
	fract->f_palitra[6][20] = NAVY;
}

void	init_color(t_fract_m *fract)
{
	init_color_1(fract);
	init_color_2(fract);
	init_color_3(fract);
	init_color_4(fract);
	init_color_5(fract);
	init_color_6(fract);
	init_color_7(fract);
}
