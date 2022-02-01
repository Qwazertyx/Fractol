/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:01:15 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/01 13:57:22 by vsedat           ###   ########lyon.fr   */
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
	data->zoomy = 1;
	data->mousex = 1;
	data->mousey = 1;
	data->const1 = 2;
	data->const2 = 1.5;
	data->moovepls = 1;
}

t_pal	*get_pal(void)
{
	static t_pal	tab[10];

	tab[0] = (t_pal){5, {0x070700, 0x353632, 0x646563, \
						0x929595, 0xc1c4c6}};
	tab[1] = (t_pal){5, {0x775C6D, 0x6d6f95, 0x0c1957, \
						0xAF91C3, 0x442CB0,}};
	tab[2] = (t_pal){5, {0xFFBF60, 0x171070, 0xA0A5FF, \
						0xE0358B, 0xD468ED,}};
	tab[3] = (t_pal){5, {0xBBD8EF, 0xCF6A93, 0x9CA7AE, \
						0xBBF6F7, 0xE4F5F7,}};
	tab[4] = (t_pal){5, {0x562135, 0xC3829E, 0xE9B1CD, \
						0xFFE7DE, 0xFCD1D7,}};
	tab[5] = (t_pal){5, {0xFEAD12, 0xFFBF10, 0xEE5519, \
						0xC8200E, 0x842539, 0x6A2448}};
	tab[6] = (t_pal){5, {0x5E0943, 0xB14359, 0xF4709A, \
						0xF0A5C1, 0xEBE6D9,}};
	tab[7] = (t_pal){4, {0x082032, 0x2C394B, 0x334756, \
						0xFF4C29,}};
	tab[8] = (t_pal){4, {0x000000, 0x5800FF, 0xE900FF, \
						0xFFC600,}};
	tab[9] = (t_pal){5, {0x03045E, 0x0077B6, 0x00B4D8, \
						0x90E0EF, 0xCAF0F8,}};
	return (tab);
}
