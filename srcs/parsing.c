/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:34:23 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/01 15:06:49 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (b[i] - a[i]);
}

int	parsing(t_data *data, int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		data->frachoice = 1;
		return (1);
	}
	if (!ft_strcmp(argv[1], "julia"))
	{
		data->frachoice = 2;
		return (1);
	}
	if (!ft_strcmp(argv[1], "tricorn"))
	{
		data->frachoice = 3;
		return (1);
	}
	return (0);
}
