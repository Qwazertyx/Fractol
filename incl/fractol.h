/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cathy <Cathy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:36:57 by vsedat            #+#    #+#             */
/*   Updated: 2022/01/26 03:16:09 by Cathy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include	<stdlib.h>
# include "../mlx/mlx.h"
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		winwidth;
	int		winlength;
	int		mousex;
	int		mousey;
	double		leftright;
	double		updown;
	double		zoom1;
	double		zoom2;
	double		zoom3;
	double		zoom4;
	
}				t_data;

#endif
