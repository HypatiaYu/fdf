/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:14:38 by hyu               #+#    #+#             */
/*   Updated: 2020/01/19 15:17:21 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void	rotate_z(t_fpoint *begin, t_scaler *scaler)
{
	int	x;
	int	y;

	x = begin->x;
	y = begin->y;
	begin->x = (x) * cos((scaler->angle) * PI / 180) -
	(y) * sin((scaler->angle) * PI / 180);
	begin->y = (x) * sin((scaler->angle) * PI / 180) +
	(y) * cos((scaler->angle) * PI / 180);
}

void	rotate_x(t_fpoint *begin, t_scaler *scaler)
{
	int	y;
	int	z;

	y = begin->y;
	z = begin->z;
	begin->y = (y) * cos((scaler->angle) * PI / 180) -
	(z) * sin((scaler->angle) * PI / 180);
	begin->z = (y) * sin((scaler->angle) * PI / 180) +
	(z) * cos((scaler->angle) * PI / 180);
}

void	rotate_y(t_fpoint *begin, t_scaler *scaler)
{
	int	x;
	int	z;

	x = begin->x;
	z = begin->z;
	begin->x = (x) * cos((scaler->angle) * PI / 180) +
	(z) * sin((scaler->angle) * PI / 180);
	begin->z = (x) * (-1) * sin((scaler->angle) * PI / 180) +
	(z) * cos((scaler->angle) * PI / 180);
}

void	isometric_rotate(t_fpoint *begin, t_scaler *scaler)
{
	t_fpoint *b_int;
	t_fpoint *b_int0;

	b_int = malloc(sizeof(t_fpoint));
	b_int0 = malloc(sizeof(t_fpoint));
	b_int0->x = begin->x;
	b_int0->y = begin->y;
	b_int0->z = begin->z;
	b_int->x = (b_int0->x) * (cos((scaler->angle) * PI / 180)) -
	(b_int0->z) * sin((scaler->angle) * PI / 180);
	b_int->y = b_int0->y;
	b_int->z = (b_int0->x) * (sin((scaler->angle) * PI / 180)) +
	(b_int->z) * cos((scaler->angle) * PI / 180);
	begin->x = b_int0->x;
	begin->y = b_int0->y * cos((scaler->angle2) * PI / 180) +
	b_int->z * sin((scaler->angle2) * PI / 180);
	begin->z = -b_int->y * sin((scaler->angle2) * PI / 180) +
	b_int->z * cos((scaler->angle2) * PI / 180);
}

void	perspective_projection(t_fpoint *begin, t_scaler *scaler)
{
	int	x;
	int	y;
	int z;

	x = begin->x;
	y = begin->y;
	z = begin->z;
	
	begin->x = x/z;
	begin->y = y/z;
	begin->z = 1;
}
