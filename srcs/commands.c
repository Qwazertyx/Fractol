/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:03:12 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/01 15:02:55 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	closewin(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
	{
		data->zoom -= 0.15 * data->zoom;
		data->zoomx -= 0.15 * x / 300 * data->zoom;
		data->zoomy -= 0.15 * y / 300 * data->zoom;
		data->depthmax += 2;
	}
	if (keycode == 5 && data->zoom < 5)
	{
		data->zoom += 0.15 * data->zoom;
		data->zoomx += 0.15 * x / 300 * data->zoom;
		data->zoomy += 0.15 * y / 300 * data->zoom;
		data->depthmax -= 2;
	}
	algo(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		closewin(data);
	if (keycode == 124)
		data->updown -= data->zoom;
	if (keycode == 123)
		data->updown += data->zoom;
	if (keycode == 126)
		data->leftright += data->zoom;
	if (keycode == 125)
		data->leftright -= data->zoom;
	if (keycode == 49)
		vardef(data);
	if (keycode >= 18 && keycode <= 23)
		data->pal = &get_pal()[keycode - 18];
	if (keycode == 26 || keycode == 29)
		data->pal = &get_pal()[keycode - 20];
	if (keycode == 28)
		data->pal = &get_pal()[7];
	if (keycode == 25)
		data->pal = &get_pal()[8];
	if (keycode == 35 && data->moovepls == 1)
		data->moovepls = 0;
	else if (keycode == 35 && data->moovepls == 0)
		data->moovepls = 1;
	algo(data);
	return (0);
}

int	locmouse(int x, int y, t_data *data)
{
	if (x > 0 && x < data->winwidth && y > 0 && y < data->winlength
		&& data->moovepls == 1)
	{
		data->mousex = x;
		data->mousey = y;
		algo(data);
	}
	return (0);
}
