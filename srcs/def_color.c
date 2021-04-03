/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:19:40 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/01 22:13:06 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color_1(t_fract_m *fract)
{
	fract->f_palitra[0][0] = BLACK;
	fract->f_palitra[0][1] = WHITE;
	fract->f_palitra[0][2] = NAVY;
	fract->f_palitra[0][3] = BLUE;
	fract->f_palitra[0][4] = DARKBLUE;
	fract->f_palitra[0][5] = DARKTURQUOISE;
	fract->f_palitra[0][6] = CADETBLUE;
	fract->f_palitra[0][7] = ORANGE;
	fract->f_palitra[0][8] = SKYBLUE;
	fract->f_palitra[0][9] = DEEPSKYBLUE;
	fract->f_palitra[0][10] = CORNFLOWERBLUE;
	fract->f_palitra[0][11] = DODGERBLUE;
	fract->f_palitra[0][12] = STEELBLUE;
	fract->f_palitra[0][13] = ROYALBLUE;
	fract->f_palitra[0][14] = BLUE;
	fract->f_palitra[0][15] = MEDIUMBLUE;
	fract->f_palitra[0][16] = MSTATEBLUE;
	fract->f_palitra[0][17] = STATEBLUE;
	fract->f_palitra[0][18] = DARKBLUE;
	fract->f_palitra[0][19] = NAVY;
	fract->f_palitra[0][20] = MIDNIGHTBLUE;
}

void	init_color_2(t_fract_m *fract)
{
	fract->f_palitra[1][0] = BLACK;
	fract->f_palitra[1][1] = WHITE;
	fract->f_palitra[1][2] = GREENYELLOW;
	fract->f_palitra[1][3] = LAWNGREEN;
	fract->f_palitra[1][4] = CHARTREUSE;
	fract->f_palitra[1][5] = LIME;
	fract->f_palitra[1][6] = YELLOWGREEN;
	fract->f_palitra[1][7] = PALEGREEN;
	fract->f_palitra[1][8] = LIMEGREEN;
	fract->f_palitra[1][9] = SPRINGGREEN;
	fract->f_palitra[1][10] = MSPRINGGREEN;
	fract->f_palitra[1][11] = AQUAMARINE;
	fract->f_palitra[1][12] = MAQUAMARINE;
	fract->f_palitra[1][13] = MSEAGREEN;
	fract->f_palitra[1][14] = SEAGREEN;
	fract->f_palitra[1][15] = FORESTGREEN;
	fract->f_palitra[1][16] = GREEN;
	fract->f_palitra[1][17] = DARKGREEN;
	fract->f_palitra[1][18] = LIGHTSEAGREEN;
	fract->f_palitra[1][19] = TEAL;
	fract->f_palitra[1][20] = DARKCYAN;
}

void	init_color_3(t_fract_m *fract)
{
	fract->f_palitra[2][0] = BLACK;
	fract->f_palitra[2][1] = WHITE;
	fract->f_palitra[2][2] = KHAKI;
	fract->f_palitra[2][3] = YELLOW;
	fract->f_palitra[2][4] = YELLOW;
	fract->f_palitra[2][5] = ORANGE;
	fract->f_palitra[2][6] = DARKORANGE;
	fract->f_palitra[2][7] = LSALMON;
	fract->f_palitra[2][8] = SALMON;
	fract->f_palitra[2][9] = DSALMON;
	fract->f_palitra[2][10] = LCORAL;
	fract->f_palitra[2][11] = CORAL;
	fract->f_palitra[2][12] = TOMATO;
	fract->f_palitra[2][13] = ORANGERED;
	fract->f_palitra[2][14] = RED;
	fract->f_palitra[2][15] = CRIMSON;
	fract->f_palitra[2][16] = INDIANRED;
	fract->f_palitra[2][17] = FIREBRICK;
	fract->f_palitra[2][18] = BROWN;
	fract->f_palitra[2][19] = DARKRED;
	fract->f_palitra[2][20] = MAROON;
}

void	init_color_4(t_fract_m *fract)
{
	fract->f_palitra[3][0] = BLACK;
	fract->f_palitra[3][1] = WHITE;
	fract->f_palitra[3][2] = PINK;
	fract->f_palitra[3][3] = INDIGO;
	fract->f_palitra[3][4] = INDIGO;
	fract->f_palitra[3][5] = PALEVIOLETRED;
	fract->f_palitra[3][6] = DEEPPINK;
	fract->f_palitra[3][7] = MAGENTA;
	fract->f_palitra[3][8] = ORCHID;
	fract->f_palitra[3][9] = PLUM;
	fract->f_palitra[3][10] = VIOLET;
	fract->f_palitra[3][11] = MEDIUMVIOLETRED;
	fract->f_palitra[3][12] = MEDIUMORCHID;
	fract->f_palitra[3][13] = DARKORCHID;
	fract->f_palitra[3][14] = DARKVIOLET;
	fract->f_palitra[3][15] = PURPLE;
	fract->f_palitra[3][16] = DARKMAGENTA;
	fract->f_palitra[3][17] = MEDIUMPURPLE;
	fract->f_palitra[3][18] = BLUEVIOLET;
	fract->f_palitra[3][19] = INDIGO;
	fract->f_palitra[3][20] = DARKSTATEBLUE;
}

void	init_color_5(t_fract_m *fract)
{
	fract->f_palitra[4][0] = C1;
	fract->f_palitra[4][1] = C2;
	fract->f_palitra[4][2] = C3;
	fract->f_palitra[4][3] = C4;
	fract->f_palitra[4][4] = C5;
	fract->f_palitra[4][5] = C6;
	fract->f_palitra[4][6] = C7;
	fract->f_palitra[4][7] = C8;
	fract->f_palitra[4][8] = C9;
	fract->f_palitra[4][9] = C10;
	fract->f_palitra[4][10] = C11;
	fract->f_palitra[4][11] = C12;
	fract->f_palitra[4][12] = C13;
	fract->f_palitra[4][13] = C14;
	fract->f_palitra[4][14] = C15;
	fract->f_palitra[4][15] = C16;
	fract->f_palitra[4][16] = C17;
	fract->f_palitra[4][17] = C18;
	fract->f_palitra[4][18] = C19;
	fract->f_palitra[4][19] = C20;
	fract->f_palitra[4][20] = C21;
}
