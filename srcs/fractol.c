/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:06:39 by vsedat            #+#    #+#             */
/*   Updated: 2022/01/28 17:51:01 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

//my_mlx_pixel_put(data, i, y, 0x00FFFFFF);
//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 2 * 2 && i < data->depthmax)
	{
   		temp = (x * x - y * y + (px * (0.005 * data->zoom)
					- (2 * data->updown * data->zoomx)));
		y = (2 * x * y + (py * (0.005 * data->zoom)
					- (1.5 * data->leftright * data->zoomy)));
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
//	my_mlx_pixel_put(data, px, py, 9000 - i * 10);
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
		//	mandelbrot(data, x, y);
			ft_color(data, x, y, mandelbrot(data, x, y));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	vardef(&data);
	data.win = mlx_new_window(data.mlx, data.winwidth, data.winlength, "fatol");
	data.img = mlx_new_image(data.mlx, data.winwidth, data.winlength);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	algo(&data);
	mlx_hook(data.win, 06, 1L << 6, locmouse, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
