/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:07:21 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 14:12:28 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point        *ft_set_scaling(t_point *dimensions, t_fpoint *begin)
{
	dimensions->win_x = 1000;
	dimensions->win_y = 1000;
	dimensions->x_center = 500;
	dimensions->y_center = 500;
	dimensions->scale = 5;
	dimensions->aspect_ratio = 1;
	dimensions->begin = begin;
	dimensions->scalex = 20;
	dimensions->scaley = 20;
	dimensions->scalez = 20;
	dimensions->x_trans = 0;
	dimensions->y_trans = 0;
	return (dimensions);
}

void        pixel_ray_trace(t_fpoint *start, t_fpoint *stop, t_point *dimensions)
{
    t_gpoint    *pixels;

    pixels = malloc(sizeof(t_gpoint));
    pixels->dx = abs(stop->x - start->x);
    pixels->dy = abs(stop->y - start->y);
    pixels->x = start->x;
    pixels->y = start->y;
    pixels->margin = pixels->dx - pixels->dy;
    (stop->x > start->x) ? (pixels->signx = 1) : (pixels->signx = -1);
    (stop->y > start->y) ? (pixels->signy = 1) : (pixels->signy = -1);
    while (pixels->x != stop->x || pixels->y != stop->y)
    {
        if (start->hex)
		{
			mlx_pixel_put(dimensions->mlx, dimensions->win, pixels->x, pixels->y, start->hex);
		}
        else
		{
            mlx_pixel_put(dimensions->mlx, dimensions->win, pixels->x, pixels->y, 0xFFFFFF);
		}
        pixels->margin1 = pixels->margin*2;
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
}

void			ray_iterator(t_fpoint *begin, t_point *dimensions)
{
	t_fpoint	*tmp;
	t_fpoint	*stop;

	tmp = begin;
	stop = tmp->nextx;
	while (tmp)
	{
		if (tmp->nextx != NULL)
		{
			stop = tmp->nextx;
			begin->x = begin->x + 1;
			pixel_ray_trace(tmp, stop, dimensions);
		}
		if (tmp->nextx == NULL && tmp->nexty != NULL)
		{
			stop = tmp->nexty;
			begin->y = begin->y + 1;
			pixel_ray_trace(tmp, stop, dimensions);
		}
		if (tmp->nexty != NULL && tmp->nextx != NULL)
		{
			stop = tmp->nexty;
			begin->y = begin->y + 1;
			pixel_ray_trace(tmp, stop, dimensions);
		}
		tmp = tmp->next;
	}
}

void        graphics_display(t_point *dimensions, t_fpoint *begin)
{
    void    *mlx_ptr;
    void    *win_ptr;

    ft_set_scaling(dimensions, begin);

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, dimensions->win_x, dimensions->win_y, "New Window");
    dimensions = ft_set_scaling(dimensions, begin);
    dimensions->mlx = mlx_ptr;
    dimensions->win = win_ptr;
	ft_list_frch_scale(begin, re_scale, dimensions);
	ft_list_frch_scale(begin, center, dimensions);
	dimensions->x_trans = 300;
	ft_list_frch_scale(begin, translation_xyz, dimensions);
	//ft_list_frch_scale(begin, un_center, dimensions);
	ray_iterator(begin, dimensions);
    mlx_loop(mlx_ptr);
}
