/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 20:27:11 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			translation_xyz(t_fpoint *list, t_point *dimensions)
{
	list->x = list->x + dimensions->x_trans;
	list->y = list->y + dimensions->y_trans;
	list->z = list->z + dimensions->z_trans;
}

void			rotate_z(t_fpoint *begin, t_point *scaler)
{
	int			x;
	int			y;

	x = begin->x;
	y = begin->y;
	begin->x = (x) * cos((scaler->angle) * PI / 180) -
	(y) * sin((scaler->angle) * PI / 180);
	begin->y = (x) * sin((scaler->angle) * PI / 180) +
	(y) * cos((scaler->angle) * PI / 180);
}

void			rotate_x(t_fpoint *begin, t_point *scaler)
{
	int			y;
	int			z;

	y = begin->y;
	z = begin->z;
	begin->y = (y) * cos((scaler->angle) * PI / 180) -
	(z) * sin((scaler->angle) * PI / 180);
	begin->z = (y) * sin((scaler->angle) * PI / 180) +
	(z) * cos((scaler->angle) * PI / 180);
}

void			rotate_y(t_fpoint *begin, t_point *scaler)
{
	int			x;
	int			z;

	x = begin->x;
	z = begin->z;
	begin->x = (x) * cos((scaler->angle) * PI / 180) +
	(z) * sin((scaler->angle) * PI / 180);
	begin->z = (x) * (-1) * sin((scaler->angle) * PI / 180) +
	(z) * cos((scaler->angle) * PI / 180);
}

void			isometric_rotate(t_fpoint *begin, t_point *scaler)
{
	int			x;
	int			y;
	int			z;

	x = begin->x;
	y = begin->y;
	z = begin->z;
	begin->x = (x - y) * cos(0.523599);
	begin->y = -z + (x + y) * sin(0.523599);
}
