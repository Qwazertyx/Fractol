/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:36:57 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/01 13:53:08 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include	<stdlib.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //to delete asap
# include <unistd.h>

typedef unsigned char	t_char;

typedef struct s_pal
{
	t_char		count;
	int			colors[16];
}						t_pal;

typedef struct s_rgba
{
	t_char	r;
	t_char	g;
	t_char	b;
	t_char	a;
}	t_rgba;

typedef union s_color {
	t_rgba	rgba;
	int		value;
}	t_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				winwidth;
	int				winlength;
	int				mousex;
	int				mousey;
	int				depthmax;
	double			leftright;
	double			updown;
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			i;
	double			j;
	double			const1;
	double			const2;
	int				frachoice;
	int				moovepls;
	t_pal			*pal;
}				t_data;

t_pal	*get_pal(void);
int		locmouse(int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		closewin(t_data *data);
void	vardef(t_data *data);
int		algo(t_data *data);
int		mandelbrot(t_data *data, int px, int py);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mouse_hook(int keycode, int x, int y, t_data *data);
t_color	smooth(t_data *d, int iter);
int		lerp(int v0, int v1, double p);
t_color	linear_color(double i, int max, t_pal *pal);
t_color	color_lerp(t_color col1, t_color col2, double p);
void	ft_color(t_data *v, int x, int y, int iter);
int		parsing(t_data *data, int argc, char *argv[]);
int		ft_strcmp(char *a, char *b);
int		julia(t_data *data, int px, int py);

#endif
