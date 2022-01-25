/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cathy <Cathy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:06:39 by vsedat            #+#    #+#             */
/*   Updated: 2022/01/25 17:58:23 by Cathy            ###   ########lyon.fr   */
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
	float	x;
	float	y;
	float	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 2 * 2 && i < 1000)
	{
		temp = (x * x - y * y + (px * (0.005 * data->zoom) - (2 * data->updown)));
		y = (2 * x * y + (py * (0.005 * data->zoom) - (1.5 * data->leftright)));
		x = temp;
		i++;
	}
	my_mlx_pixel_put(data, px, py, 5000 - i * 5);
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
	if (keycode == 13)
		data->zoom -= 0.05;
	if (keycode == 1)
		data->zoom += 0.05;
	printf("%d\n", keycode);
	algo(data);
	return (0);
}

void	vardef(t_data *data)
{
	data->winwidth = 600;
	data->winlength = 600;
	data->updown = 1;
	data->leftright = 1;
	data->zoom = 1;
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	vardef(&data);
	data.win = mlx_new_window(data.mlx, data.winwidth, data.winlength, "sussy baka");
	data.img = mlx_new_image(data.mlx, data.winwidth, data.winlength);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	algo(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
