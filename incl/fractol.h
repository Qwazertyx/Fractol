/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cathy <Cathy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:06:39 by vsedat            #+#    #+#             */
/*   Updated: 2022/01/26 03:45:16 by Cathy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include <stdio.h>

//my_mlx_pixel_put(data, i, y, 0x00FFFFFF);
//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 2 * 2 && i < 100)
	{
		temp = (x * x - y * y + (px * (0.005 * data->zoom1) - (2 * data->updown * data->zoom2)));
		y = (2 * x * y + (py * (0.005 * data->zoom3) - (1.5 * data->leftright * data->zoom4)));
		x = temp;
		i++;
	}
	my_mlx_pixel_put(data, px, py, 9000 - i * 5);
}

int	algo(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->winwidth)
	{
		y = 0;
		while (y < data->winlength)
		{
			mandelbrot(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	vardef(t_data *data)
{
	data->winwidth = 600;
	data->winlength = 600;
	data->updown = 1;
	data->leftright = 1;
	data->zoom1 = 1;
	data->zoom2 = 1;
	data->zoom3 = 1;
	data->zoom4 = 1;
	data->mousex = 1;
	data->mousey = 1;
}

int	close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)	//quit echap
		close(data);
	if (keycode == 124)
		data->updown -= 0.05;
	if (keycode == 123)
		data->updown += 0.05;
	if (keycode == 126)
		data->leftright += 0.05;
	if (keycode == 125)
		data->leftright -= 0.05;
	if (keycode == 0)
	{
		data->zoom1 -= 0.1 * data->zoom1;
		data->zoom2 -= 0.1 * data->mousex / (data->winwidth / 2)* data->zoom1;
		data->zoom3 -= 0.1 * data->zoom3;
		data->zoom4 -= 0.1 * data->mousey / (data->winwidth / 2)* data->zoom3;
	}
	if (keycode == 1)
	{
		data->zoom1 += 0.1 * data->zoom1;
		data->zoom2 += 0.1 * data->mousex / (data->winwidth / 2)* data->zoom1;
		data->zoom3 += 0.1 * data->zoom3;
		data->zoom4 += 0.1 * data->mousey / (data->winwidth / 2)* data->zoom3;
	}
	if (keycode == 49)
		vardef(data);
//	printf("%d\n", keycode);
	algo(data);
	return (0);
}

int	locmouse(int x, int y, t_data *data)
{
	if (x > 0 && x < data->winwidth && y > 0 && y < data->winlength)
	{
		data->mousex = x;
		data->mousey = y;
		printf("x: %d\n", x);
		printf("y: %d\n", y);
	}
	
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	vardef(&data);
	data.win = mlx_new_window(data.mlx, data.winwidth, data.winlength, "fractol");
	data.img = mlx_new_image(data.mlx, data.winwidth, data.winlength);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	algo(&data);
	mlx_hook(data.win, 06, 1L << 6, locmouse, &data);
	mlx_key_hook(data.win, key_hook, &data);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(data.mlx);
}
