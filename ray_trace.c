/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:50:13 by hyu               #+#    #+#             */
/*   Updated: 2020/01/19 15:08:28 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void		y_z_recalculate(t_fpoint *start, t_fpoint *stop)
{
	int z;
	double dy;
	double dz;
	double	scaler;

	dz = stop->z - start->z;
	dy = stop->y - start->y;
	scaler = sqrt(pow(dz, 2) + pow(dy, 2));
	dz = dz / scaler;
	dy = dy / scaler;

}*/
void		pixel_ray_trace(t_fpoint *start, t_fpoint *stop, t_scaler *pointer)
{
	int	i;
	int	y;
	int x;
	int z;
	double dy;
	double dx;
	double dz;
	double	diag;

	dx = (stop->x - start->x);
	dy = (stop->y - start->y);
	dz = stop->z - start->z;
	diag = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2)); 
	dx = dx/diag;
	dy = dy/diag;
	dz = dz/diag;

	i = 0;
	x = start->x;
	if ((start->x) == (stop->x))
	{
		while ((start->y + i) < stop->y)
		{
			if (start->hex)
				mlx_pixel_put(pointer->mlx, pointer->win, start->x,
				start->y + i, start->hex);
			else
				mlx_pixel_put(pointer->mlx, pointer->win, start->x,
				start->y + i, 0xFFFFFF);
			i++;
		}
	}
	else if (start->y == stop->y)
	{
		while (start->x + i < stop->x)
		{
			if (start->hex)
				mlx_pixel_put(pointer->mlx, pointer->win, start->x + i, start->y, start->hex);
			else
				mlx_pixel_put(pointer->mlx, pointer->win, start->x + i, start->y,0xFFFFFF);
			i++;
		}
	}
	else
	{
		while (diag > 0)
		{
			if (start->hex)
				mlx_pixel_put(pointer->mlx, pointer->win, x, y, start->hex);
			else
				mlx_pixel_put(pointer->mlx, pointer->win, x, y,0xFFFFFF);
			y = y + dy;
			x = x + dx;
			z = z + dz;
			diag--;
		}
	}
}
