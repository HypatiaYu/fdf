/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:07:21 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 11:00:55 by hyu              ###   ########.fr       */
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
	return (dimensions);
}

void		graphics_display(t_point *dimensions, t_fpoint *begin)
{
	void    *mlx_ptr;
	void    *win_ptr;

	ft_set_scaling(dimensions, begin);
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, dimensions->win_x, dimensions->win_y, "New Window");
	dimensions = ft_set_scaling(dimensions, begin);
	dimensions->mlx = mlx_ptr;
	dimensions->win = win_ptr;
	//scale->size = dimensions;
	//ray_iterator(begin, *dimensions, scale);
	//mlx_key_hook(scale->win, deal_key, scale);
	mlx_loop(mlx_ptr);
}
