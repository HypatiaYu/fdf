/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/27 19:24:44 by hyu              ###   ########.fr       */
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
	begin->x = (x) * cos(scaler->angle) -
	(y) * sin(scaler->angle);
	begin->y = (x) * sin(scaler->angle) +
	(y) * cos(scaler->angle);
}

void			rotate_x(t_fpoint *begin, t_point *scaler)
{
	int			y;
	int			z;

	y = begin->y;
	z = begin->z;
	begin->y = (y) * cos(scaler->angle) -
	(z) * sin(scaler->angle);
	begin->z = (y) * sin(scaler->angle) +
	(z) * cos(scaler->angle);
}

void			rotate_y(t_fpoint *begin, t_point *scaler)
{
	int			x;
	int			z;

	x = begin->x;
	z = begin->z;
	begin->x = (x) * cos(scaler->angle) +
	(z) * sin(scaler->angle);
	begin->z = (x) * (-1) * sin(scaler->angle) +
	(z) * cos(scaler->angle);
}

void			isometric_rotate(t_fpoint *begin, t_point *scaler)
{
	int			x;
	int			y;
	int			z;

	x = begin->x;
	y = begin->y;
	z = begin->z;
	begin->x = (x - y) * cos(scaler->angle);
	begin->y = -z + (x + y) * sin(scaler->angle);
}
