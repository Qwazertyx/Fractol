/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:06:39 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/01 12:21:27 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (int)(y * data->line_length + x
			* (data->bits_per_pixel * 0.125));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (parsing(&data, argc, argv) == 0)
	{
		write (1, "Wrong parameter, here is a list of the different ", 49);
		write (1, "parameters available:\n- mandelbrot\n- julia\n", 43);
		return (0);
	}
	data.mlx = mlx_init();
	vardef(&data);
	data.pal = &get_pal()[8];
	data.win = mlx_new_window(data.mlx, data.winwidth, data.winlength, "baka");
	data.img = mlx_new_image(data.mlx, data.winwidth, data.winlength);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	algo(&data);
	mlx_hook(data.win, 17, 1L << 2, closewin, &data);
	mlx_hook(data.win, 06, 1L << 6, locmouse, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
