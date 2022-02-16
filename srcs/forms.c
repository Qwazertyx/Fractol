/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:34:26 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/16 10:24:48 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
			if (data->frachoice == 1)
				ft_color(data, x, y, mandelbrot(data, x, y));
			if (data->frachoice == 2)
				ft_color(data, x, y, julia(data, x, y));
			if (data->frachoice == 3)
				ft_color(data, x, y, tricorn(data, x, y));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_string_put(data->mlx, data->win, 0, 10, 0xFFFFFF, "Color: 0 .. 9");
	mlx_string_put(data->mlx, data->win, 0, 20, 0xFFFFFF, "Reset: Space");
	if (data->frachoice == 2)
		mlx_string_put(data->mlx, data->win, 0, 30, 0xFFFFFF, "Pause: P");
	return (0);
}

int	julia(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = px * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = py * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y - (0.8 * data->mousex / 300);
		y = 2 * x * y + (0.2 * data->mousey / 300);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}

int	tricorn(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = px * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = py * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y + px * 0.0065 * data->zoom
			- 2 * data->zoomx * data->updown;
		y = -2 * x * y + py * 0.0065 * data->zoom
			- 2 * data->zoomy * data->leftright;
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
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
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y + (px * 0.005 * data->zoom
				- 2 * data->updown * data->zoomx);
		y = 2 * x * y + (py * 0.005 * data->zoom
				- 1.5 * data->leftright * data->zoomy);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}
