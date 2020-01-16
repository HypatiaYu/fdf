/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:51:18 by hyu               #+#    #+#             */
/*   Updated: 2020/01/16 15:08:09 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void    rotate_z(t_fpoint *begin, t_scaler *scaler)
{
	int	x;
	int y;

	x = begin->x;
	y = begin->y;
	begin->x = (x)*cos((scaler->angle)*PI/180) - (y)*sin((scaler->angle) * PI/180);
	begin->y = (x)*sin((scaler->angle)*PI/180) + (y)*cos((scaler->angle) * PI/180);
}

void	rotate_x(t_fpoint *begin, t_scaler *scaler)
{
	int	y;
	int z;

	y = begin->y;
	z = begin->z;
	begin->y = (y) * cos((scaler->angle) * PI/180) - (z) * sin((scaler->angle) * PI/180);
	begin->z = (y) * sin((scaler->angle) * PI/180) + (z) * cos((scaler->angle) * PI/180);
}

void	rotate_y(t_fpoint *begin, t_scaler *scaler)
{
	int	x;
	int z;

	x = begin->x;
	z = begin->z;
	begin->x = (x)*cos((scaler->angle) * PI/180) + (z) * sin((scaler->angle) * PI/180);
	begin->z = (x) * (-1) * sin((scaler->angle) * PI/180) + (z) * cos((scaler->angle) * PI/180);
}

void	isometric_rotate(t_fpoint *begin, t_scaler *scaler)
{
	int	bx;
	int by;
	int bz;
	int	x;
	int	y;
	int z;

	x = begin->x;
	y = begin->y;
	z = begin->z;

	bx = (x) * (cos((scaler->angle) * PI/180)) - (z)*sin((scaler->angle) * PI/180);
	by = y;
	bz = (x) * (sin((scaler->angle)*PI/180)) + (z) * cos((scaler->angle) * PI/180);
	begin->x = bx;
	begin->y = by * cos((scaler->angle2) * PI/180) + bz * sin((scaler->angle2) * PI/180);
	begin->z = -by * sin((scaler->angle2) * PI/180) + bz * cos((scaler->angle2) * PI/180);
}

void	make_bigger(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (begin->x) * (scaler->scale);
	begin->y = (begin->y) * (scaler->scale);
	begin->z = (begin->z) * (scaler->scale);

}

void    make_smaller(t_fpoint *begin, t_scaler *scaler)
{
    begin->x = (begin->x) / (scaler->scale);
    begin->y = (begin->y) / (scaler->scale);
    begin->z = (begin->z) / (scaler->scale);

}

void	make_wider(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = begin->x * 1.5;
}

void    make_skinnier(t_fpoint *begin, t_scaler *scaler)
{
    begin->x = begin->x / 1.5;
}

void    make_taller(t_fpoint *begin, t_scaler *scaler)
{
    begin->y = begin->y * 1.5;
}

void    make_shorter(t_fpoint *begin, t_scaler *scaler)
{
    begin->y = begin->y / 1.5;
}

void    perspective_projection(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (-1) * (scaler->d) * (begin->x)/(begin->z);
	begin->y = (-1) * (scaler->d) * (begin->y)/(begin->z);
}

void	un_center(t_fpoint *begin, t_scaler *scaler)
{
	int center_x;
    int center_y;

    center_x = scaler->win_x / 2;
    center_y = scaler->win_y / 2;
    begin->x = begin->x - center_x + (scaler->x_dim) * (scaler->scale) * (scaler->aspect_ratio)/2 - scaler->x_trans;
    begin->y = begin->y - center_y + (scaler->y_dim) * (scaler->scale)/(scaler->aspect_ratio * 2) - scaler->y_trans;
}
