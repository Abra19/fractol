/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:22:14 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 02:08:46 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** goal is to create a fractal exploration program
** mandatory: 3 different types of fractals: julia, mandelbrot, burningship
** bonus fractals:
** celtic mandelbrot, celtic julia, bird, flower, heart
** julia 3, 4, 5, mandelbar 3, 4, mandelbrot 3, 4, 5
** possible to make the parameter of the all julia similar set vary
** only with the mouse (without clicking)
** mouse wheel zooms in and out, almost infinitely (within the limits of the
** computer)
** using a set of colors to show the depth of each fractal
** bonus: change color palitre
** A parameter on the command line define what type of fractal will be
** viewed.
** If no parameter is provided, or if the parameter is invalid, the program
** displays a list of available parameters and exits properly.
** bonus: possible to launch with two parameters - two fractal in two different
** windows
** ESC define exit of the program, program properly closed with red cross
** bonus: zoom follow the actual mouse position
** bonus: moving with the arrows and witn the mouse
*/

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"
# include <pthread.h>

/*
** parameters of pixel size
*/

# define MAC_BPP			4

/*
** numbers of using color
*/

# define NCOL			20

/*
** base color
*/

# define WHITE				0xFFFFFF
# define BLACK				0x000000

/*
** mandelbrot init
*/

# define PMIN				-2.25
# define PMAX				0.75
# define QMIN				-1.5
# define QMAX				1.5

/*
** burningship init
*/

# define BPMIN				-2.5
# define BPMAX				1.7
# define BQMIN				-2.3
# define BQMAX				1.9

/*
** bird init
*/

# define BDPMIN				-1.6
# define BDPMAX				1.5
# define BDQMIN				-1.5
# define BDQMAX				1.9

/*
** julia init
*/

# define JPMIN				-1.5
# define JPMAX				1.5
# define JQMIN				-1.5
# define JQMAX				1.5
# define PJ0				0.27334
# define QJ0				0.00742

/*
** mandelbar_4 init
*/

# define MPMIN				-1.9
# define MPMAX				1.9
# define MQMIN				-1.425
# define MQMAX				1.425

/*
** mandelbar_3 init
*/

# define MSPMIN				-3.5
# define MSPMAX				2.5
# define MSQMIN				-1.8
# define MSQMAX				1.8

/*
** colors parameters: blue colors
*/

# define DARKTURQUOISE		0x00CED1
# define CADETBLUE			0x5F9EA0
# define OTBLUE				0x0E0EA4
# define SKYBLUE			0x87CEEB
# define DEEPSKYBLUE		0x00BFFF
# define CORNFLOWERBLUE		0x6495ED
# define DODGERBLUE			0x1E90FF
# define STEELBLUE			0x4682B4
# define ROYALBLUE			0x4169E1
# define BLUE				0x0000FF
# define MEDIUMBLUE			0x0000CD
# define MSTATEBLUE			0x7B68EE
# define STATEBLUE			0x6A5ACD
# define DARKBLUE			0x00008B
# define NAVY				0x000080
# define MIDNIGHTBLUE		0x191970

/*
** colors parameters: green colors
*/

# define GREENYELLOW		0xADFF2F
# define LAWNGREEN			0x7CFC00
# define CHARTREUSE			0x7FFF00
# define LIME				0x00FF00
# define YELLOWGREEN		0x9ACD32
# define PALEGREEN			0x98FB98
# define LIMEGREEN			0x32CD32
# define SPRINGGREEN		0x00FF7F
# define MSPRINGGREEN		0x00FA9A
# define AQUAMARINE			0x7FFFD4
# define MAQUAMARINE		0x66CDAA
# define MSEAGREEN			0x3CB371
# define SEAGREEN			0x2E8B57
# define FORESTGREEN		0x228B22
# define GREEN				0x008000
# define DARKGREEN			0x006400
# define LIGHTSEAGREEN		0x20B2AA
# define TEAL				0x008080
# define DARKCYAN			0x008B8B

/*
** colors parameters: red colors
*/

# define KHAKI				0xF0E68C
# define YELLOW				0xFFFF00
# define ORANGE				0xFFA500
# define DARKORANGE			0xFF8C00
# define LSALMON			0xFFA07A
# define SALMON				0xFA8072
# define DSALMON			0xE9967A
# define LCORAL				0xF08080
# define CORAL				0xFF7F50
# define TOMATO				0xFF6347
# define ORANGERED			0xFF4500
# define RED				0xFF0000
# define CRIMSON			0xDC143C
# define INDIANRED			0xCD5C5C
# define FIREBRICK			0xB22222
# define BROWN				0xA52A2A
# define DARKRED			0x8B0000
# define MAROON				0x800000

/*
** colors parameters: purple colors
*/

# define PINK				0xFFC0CB
# define PALEVIOLETRED		0xDB7093
# define DEEPPINK			0xFF1493
# define MAGENTA			0xFF00FF
# define ORCHID				0xDA70D6
# define PLUM				0xDDA0DD
# define VIOLET				0xEE82EE
# define MEDIUMVIOLETRED	0xC71585
# define MEDIUMORCHID		0xBA55D3
# define DARKORCHID			0x9932CC
# define DARKVIOLET			0x9400D3
# define PURPLE				0x800080
# define DARKMAGENTA		0x8B008B
# define MEDIUMPURPLE		0x9370DB
# define BLUEVIOLET			0x8A2BE2
# define INDIGO				0x4B0082
# define DARKSTATEBLUE		0x483D8B

/*
** colors parameters: blue-purple
*/

# define C1					0x51168D
# define C2					0x411170
# define C3					0x19071A
# define C4					0x09012F
# define C5					0x040449
# define C6					0x000764
# define C7					0x0C2C8A
# define C8					0x123092
# define C9					0x1852B1
# define C10				0x397DD1
# define C11				0x86B5E5
# define C12				0xD3ECF8
# define C13				0xF1E9BF
# define C14				0xF8C95F
# define C15				0x381356
# define C16				0x461E6E
# define C17				0x5B2C8A
# define C18				0x6C3A9F
# define C19				0x7943B0
# define C20				0x874BC3
# define C21				0x965AD2

/*
** colors parameters: red-green
*/

# define D1					0xFA9C9C
# define D2					0xF24B4B
# define D3					0x063D17
# define D4					0x09491C
# define D5					0x0C5221
# define D6					0x12642A
# define D7					0x167031
# define D8					0x1A7F38
# define D9					0x219544
# define D10				0x2AC95A
# define D11				0xF9C7F7
# define D12				0xE8A4E6
# define D13				0xD578D2
# define D14				0xC64EC2
# define D15				0xDF32D9
# define D16				0xFA26F3
# define D17				0x92078E
# define D18				0x920C07
# define D19				0xA80D07
# define D20				0xC1100A
# define D21				0xEB1B14

/*
** window parameter
*/

# define WIDTH				1400 /// 1600
# define HEIGHT				800 /// 1000
# define LEGENDA			250
# define HBORD				0
# define VBORD				0
# define MOVE_MULT			0.2
# define MULT				0.03

/*
** keyboard codes
*/

# define E_KEY				14
# define P_KEY				35
# define M_KEY				31
# define BLUE_KEY			18
# define GREEN_KEY			19
# define RED_KEY			20
# define PURP_KEY			21
# define MULT_KEY			23
# define DARK_KEY			22
# define LAST_KEY			26
# define UP_KEY				126
# define DOWN_KEY			125
# define LEFT_KEY			123
# define RIGHT_KEY			124
# define QUIT_KEY			53
# define ENTER_KEY			36
# define SPACE_KEY			49

/*
** mouse codes
*/

# define M_PRESS_1			1
# define M_PRESS_2			2
# define M_ZOOM_P			4
# define M_ZOOM_M			5

/*
** threads
*/

# define THREADS			350 /// corresponding with WIDTH

/*
** struct for image parameters
** bpp - bytes for pixel
** size_line - number of bytes used to store one line of the image in memory
** endan - endian: format of order
** width of image
** height of image
*/

typedef	struct				s_image
{
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_image;

/*
** struct for one fractal in one window
** mlx_win - pointer to open window
** mlx_ptr - pointer to open connection with mlx
** img_ptr - pointer to image
** addr - address of start of the memory for image
** x_move - move image along OX
** y_move - move image along OY
** mp, mq - re and im parts of shift for zoom corresponding with mouse point
** mouse_pressed - button of mouse is pressed = 1 else 0
** mouse_x - x coord for mouse
** mouse_y - y coord for mouse
** mouse_xprev - x coord for previous point of mouse
** mouse_yprev - y coord for previous point of mouse
** mouse_key - code of mouse manipulation
** pmax, pmin, qmax, qmin - max/min values
** for mandelbrot similar fractals of p, q from c = p + iq
** for other fractals of x, y from z = x + iy
** p, q: re and im part of parameter c
** dp, dq - parameters for drawing fractal
** cx, cy: parameters of julia types
** n_fract  - number of choosen fractal
** palitra_num: number of colors set
** color: color of current pixel
** n_draw: counter of image
** iter: quantity of iterations
** julia_change: flag for open change for mouse moving
** zoom: coefficient for zooming
*/

typedef struct				s_fract
{
	void					*mlx_win;
	void					*mlx_ptr;
	void					*img_ptr;
	char					*addr;
	float					x_move;
	float					y_move;
	float					mp;
	float					mq;
	int						mouse_pressed;
	int						mouse_xprev;
	int						mouse_yprev;
	int						mouse_x;
	int						mouse_y;
	int						mouse_key;
	float					pmin;
	float					pmax;
	float					qmin;
	float					qmax;
	float					p;
	float					q;
	float					dp;
	float					dq;
	float					cx;
	float					cy;
	int						n_fract;
	int						palitra_num;
	int						color;
	int						n_draw;
	int						iter;
	int						julia_change;
	float					zoom;
}							t_fract;

/*
**  struct for all fractals in windows
** mlx_ptr - pointer to open connection with mlx
** height - height of window
** width - width of window
** f_width, f_height - size of fractal image
** xk, yk: re and im part of z = x + iy
** xk2, yk2: xk * xk and yk * yk accordingly
** xk4, yk4: xk2 * xk2 and yk2 * yk2 accordingly
** cp, cq: re and im part of c = p + iq
** p, q: re and im part of z = p + iq
** p2, q2: p * p and q * q accordingly
** p4, q4: p2 * p2 and q2 * q2 accordingly
** r - radius of sphere in pix
** n_win: number of window to open
** f_palitra[7][21]: array for used colors
** flag_twoarg: flag for two fractal in two windows
*/

typedef struct				s_fract_m
{
	void					*mlx_ptr;
	int						height;
	int						width;
	int						f_width;
	int						f_height;
	float					xk;
	float					yk;
	float					xk2;
	float					yk2;
	float					xk4;
	float					yk4;
	float					p2;
	float					q2;
	float					p4;
	float					q4;
	int						r;
	int						n_win;
	int						f_palitra[7][21];
	int						flag_twoarg;
	int						current;
	int						next;
	t_image					image;
	t_fract					fract1;
	t_fract					fract2;
}							t_fract_m;

void						bird(t_fract_m *fract, int n);
void						burningship(t_fract_m *fract, int n);
void						celtic_julia(t_fract_m *fract, int n);
void						celtic_mandelbrot(t_fract_m *fract, int n);
void						change_color_1(int key, t_fract_m *fract);
void						change_color_2(int key, t_fract_m *fract);
int							choose_fract(char *str, int *n);
int							close_x_1(void *param);
int							close_x_2(void *param);
int							distrib_fract(t_fract_m *fract);
void						distrib_fract5(t_fract_m *fract);
void						distrib_fract4(t_fract_m *fract);
void						draw_fractal(t_fract_m *fract);
void						expose_image_1(t_fract_m *fract);
void						expose_image_2(t_fract_m *fract);
void						flower(t_fract_m *fract, int n);
void						fract_pthreads(t_fract_m *fract);
float						ft_abs_float(float a);
void						heart(t_fract_m *fract, int n);
void						init_bird_param(char *ptr1, char *ptr2,\
							t_fract_m *fract);
void						init_burningship_param(char *ptr1, char *ptr2,\
							t_fract_m *fract);
void						init_color(t_fract_m *fract);
void						init_color_1(t_fract_m *fract);
void						init_color_2(t_fract_m *fract);
void						init_color_3(t_fract_m *fract);
void						init_color_4(t_fract_m *fract);
void						init_color_5(t_fract_m *fract);
void						init_mandelbar_3_param(char *ptr1, char *ptr2,\
							t_fract_m *fract);
void						init_mandelbar_4_param(char *ptr1, char *ptr2,\
							t_fract_m *fract);
int							init_mlx(t_fract_m *fract, char *str1, char *str2);
void						image_pixel_put(t_fract_m *fract, int x, int y,\
							int color);
void						init_fract(t_fract *fract, void *mlx_ptr);
void						init_fract_pow2(t_fract_m *fract_m);
void						init_fract_pow4(t_fract_m *fract_m);
void						init_julia(t_fract *fract, t_fract_m *fract_m,\
							int i, int j);
void						init_julia_m(t_fract *fract, t_fract_m *fract_m,\
							int i, int j);
void						init_julia_param(char *ptr1, char *ptr2,\
							t_fract_m *fract);
void						julia(t_fract_m *fract, int n);
void						julia_3(t_fract_m *fract, int n);
void						julia_4(t_fract_m *fract, int n);
void						julia_5(t_fract_m *fract, int n);
int							key_press_1(int key, void *param);
int							key_press_2(int key, void *param);
void						legenda(t_fract *fract, void *mlx_win,\
							void *mlx_ptr);
void						mandelbar_3(t_fract_m *fract, int n);
void						mandelbar_4(t_fract_m *fract, int n);
void						mandelbrot(t_fract_m *fract, int n);
void						mandelbrot_3(t_fract_m *fract, int n);
void						mandelbrot_4(t_fract_m *fract, int n);
void						mandelbrot_5(t_fract_m *fract, int n);
int							mouse_move_1(int x, int y, void *param);
int							mouse_move_2(int x, int y, void *param);
int							mouse_press_1(int button, int x, int y,\
							t_fract_m *fract);
int							mouse_press_2(int button, int x, int y,\
							t_fract_m *fract);
int							mouse_release(int button, int x, int y,\
							void *param);
void						move_1(int key, t_fract_m *fract);
void						move_2(int key, t_fract_m *fract);
void						print_usage(void);
void						put_fract(t_fract *fract, t_fract_m *fract_m,\
							int k);
void						put_fract_image(t_fract_m	*fract);
void						put_fract_j(t_fract *fract, t_fract_m *fract_m,\
							int k);
void						refresh_fract(t_fract_m *fract_m);

#endif
