/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:07:21 by hyu               #+#    #+#             */
/*   Updated: 2020/02/01 18:40:08 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point			*ft_set_scaling(t_point *dimensions, t_fpoint *begin)
{
	dimensions->win_x = 1000;
	dimensions->win_y = 1000;
	dimensions->x_center = 500;
	dimensions->y_center = 500;
	dimensions->scale = 5;
	dimensions->aspect_ratio = 1;
	dimensions->begin = begin;
	dimensions->scalex = 1;
	dimensions->scaley = 1;
	dimensions->scalez = 1;
	dimensions->x_trans = 0;
	dimensions->y_trans = 0;
	return (dimensions);
}

t_gpoint		*assign_pixels(t_fpoint *start, t_fpoint *stop)
{
	t_gpoint	*pixels;

	pixels = malloc(sizeof(t_gpoint));
	pixels->dx = abs(stop->x - start->x);
	pixels->dy = abs(stop->y - start->y);
	pixels->x = start->x;
	pixels->y = start->y;
	pixels->margin = pixels->dx - pixels->dy;
	if (stop->x > start->x)
		pixels->signx = 1;
	else
		pixels->signx = -1;
	if (stop->y > start->y)
		pixels->signy = 1;
	else
		pixels->signy = -1;
	return (pixels);
}

void			pixel_ray_trace(t_fpoint *start, t_fpoint *stop,
				t_point *dimensions)
{
	t_gpoint	*pixels;

	pixels = assign_pixels(start, stop);
	while (pixels->x != stop->x || pixels->y != stop->y)
	{
		mlx_pixel_put(dimensions->mlx, dimensions->win, pixels->x,
		pixels->y, 0xFFFFFF);
		pixels->margin1 = pixels->margin * 2;
		if (pixels->margin1 > pixels->dy * -1)
		{
			pixels->margin = pixels->margin - pixels->dy;
			pixels->x = pixels->x + pixels->signx;
		}
		if (pixels->margin1 < pixels->dx)
		{
			pixels->margin = pixels->margin + pixels->dx;
			pixels->y = pixels->y + pixels->signy;
		}
	}
	free(pixels);
}

void			ray_iterator(t_fpoint *begin, t_point *dimensions)
{
	t_fpoint	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->nextx)
			pixel_ray_trace(tmp, tmp->nextx, dimensions);
		if (tmp->nexty)
			pixel_ray_trace(tmp, tmp->nexty, dimensions);
		tmp = tmp->next;
	}
}

void			graphics_display(t_point *dimensions, t_fpoint *begin)
{
	void		*mlx_ptr;
	void		*win_ptr;

	ft_set_scaling(dimensions, begin);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, dimensions->win_x, dimensions->win_y,
	"New Window");
	dimensions = ft_set_scaling(dimensions, begin);
	dimensions->mlx = mlx_ptr;
	dimensions->win = win_ptr;
	dimensions->scalex = 30;
	dimensions->scaley = 30;
	dimensions->scalez = 30;
	dimensions->angle = 0.523599;
	dimensions->angle2 = 0.523599;
	null_x(begin, dimensions);
	ft_list_frch_scale(begin, re_scale, dimensions);
	ft_list_frch_scale(begin, isometric_rotate, dimensions);
	ft_list_frch_scale(begin, center, dimensions);
	mlx_key_hook(dimensions->win, deal_key, dimensions);
	ray_iterator(begin, dimensions);
	mlx_loop(mlx_ptr);
}
