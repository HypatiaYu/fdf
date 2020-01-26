/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:07:21 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 10:34:50 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point        *ft_set_scaling(t_point *dimensions, t_fpoint *begin)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	dimensions->mlx = mlx_ptr;
	dimensions->win_x = 1000;
	dimensions->win_y = 1000;
	dimensions->x_center = 500;
	dimensions->y_center = 500;
	dimensions->scale = 5;
	dimensions->aspect_ratio = 1;
	dimensions->begin = begin;
	win_ptr = mlx_new_window(dimensions->mlx, dimensions->win_x, dimensions->win_y, "New Window");
	dimensions->win = win_ptr;
	return (dimensions);
}

