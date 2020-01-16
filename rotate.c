/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:51:18 by hyu               #+#    #+#             */
/*   Updated: 2020/01/14 13:29:16 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void    rotate_z(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (begin->x)*cos((scaler->angle)*PI/180) - (begin->y)*sin((scaler->angle) * PI/180);
	begin->y = (begin->x)*sin((scaler->angle)*PI/180) + (begin->y)*cos((scaler->angle) * PI/180);
}

void	rotate_x(t_fpoint *begin, t_scaler *scaler)
{
	begin->y = (begin->y) * cos((scaler->angle) * PI/180) - (begin->z) * sin((scaler->angle) * PI/180);
	begin->z = (begin->y) * sin((scaler->angle) * PI/180) + (begin->z) * cos((scaler->angle) * PI/180);
}

void	rotate_y(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (begin->x)*cos((scaler->angle) * PI/180) + (begin->z) * sin((scaler->angle) * PI/180);
	begin->z = (begin->x) * (-1) * sin((scaler->angle) * PI/180) + (begin->z) * cos((scaler->angle) * PI/180);
}

void	isometric_rotate(t_fpoint *begin, t_scaler *scaler)
{
	int	bx;
	int by;
	int bz;

	bx = (begin->x) * (cos((scaler->angle) * PI/180)) - (begin->z)*sin((scaler->angle) * PI/180);
	by = begin->y;
	bz = (begin->x) * (sin((scaler->angle)*PI/180)) + (begin->z) * cos((scaler->angle) * PI/180);
	begin->x = bx;
	begin->y = by * cos((scaler->angle2) * PI/180) + bz * sin((scaler->angle2) * PI/180);
	begin->z = -by * sin((scaler->angle2) * PI/180) + bz * cos((scaler->angle2) * PI/180);
}

void    perspective_projection(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (-1) * (scaler->d) * (begin->x)/(begin->z);
	begin->y = (-1) * (scaler->d) * (begin->y)/(begin->z);
}
