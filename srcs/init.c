/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:01:15 by vsedat            #+#    #+#             */
/*   Updated: 2022/01/28 16:11:26 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	vardef(t_data *data)
{
	data->winwidth = 600;
	data->winlength = 600;
	data->updown = 1;
	data->leftright = 1;
	data->depthmax = 50;
	data->zoom = 1;
	data->zoomx = 1;
	data->zoom = 1;
	data->zoomy = 1;
	data->mousex = 1;
	data->mousey = 1;
	data->color = 0x0FF088;
}

t_pal	*get_pal(void)
{
	static t_pal	tab[4];

	tab[0] = \
		(t_pal){15, {0xd5b7a7, 0xdaaa99, 0xe39c8c, \
						0xf48e81, 0xff8079, 0xff7273, \
						0xff6370, 0xdc5570, 0xc04872, \
						0xa43b76, 0x882e7c, 0x6a2282, \
						0x4a1788, 0x280e8e, 0x050591}};
	tab[1] = \
		(t_pal){5, {0xfff89b, 0xdf9434, 0x000000, \
						0x0055ff, 0xfffdff}};
	tab[2] = \
		(t_pal){5, {0x070700, 0x353632, 0x646563, \
						0x929595, 0xc1c4c6}};
	tab[3] = \
		(t_pal){7, {0x00FFFF, 0x0000FF, 0xFF00FF, \
						0xFF0000, 0xFFFF00, 0x00FF00, \
						0x00FFFF}};
	return (tab);
}
