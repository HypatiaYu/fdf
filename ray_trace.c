/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:50:13 by hyu               #+#    #+#             */
/*   Updated: 2020/01/15 14:59:13 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    pixel_ray_trace(t_fpoint *start, t_fpoint *stop, void *mlx_ptr, void *win_ptr)
{
	int	i;
	int	y;

	i = 0;
	if ((start->x) == (stop->x))
	{
		while ((start->y + i) < stop->y)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, start->x, start->y + i, 0xFFFFFF);
				i++;
			}		
	}
	else if (start->y == stop->y)
	{
		while (start->x + i < stop->x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, start->x + i, start->y, 0xFFFFFF);
			i++;
		}
	}
		
	else
	{
		while ((start->x + i) < stop->x)
		{
			y = start->y + ((stop->y - start->y)/(stop->x - start->x)) * i;
			mlx_pixel_put(mlx_ptr, win_ptr, start->x + i, y, 0xFFFFFF);
			i++;
		}
	}
}

