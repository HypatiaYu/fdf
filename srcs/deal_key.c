/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:26:03 by hyu               #+#    #+#             */
/*   Updated: 2020/01/29 21:41:43 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			deal_key_trans(int key, t_point *pointer)
{
	if (key == KEY_A)
		pointer->x_trans = 10;
	if (key == KEY_B)
		pointer->x_trans = -10;
	if (key == KEY_C)
		pointer->y_trans = 10;
	if (key == KEY_D)
		pointer->y_trans = -10;
	if (key == KEY_E)
		pointer->z_trans = 10;
	if (key == KEY_F)
		pointer->z_trans = -10;
	minx_miny(pointer->begin, pointer);
	null_x(pointer->begin, pointer);
	ft_list_frch_scale(pointer->begin, translation_xyz, pointer);
	return (0);
}

int			deal_key_rotate(int key, t_point *pointer)
{
	ft_list_frch_scale(pointer->begin, un_center, pointer);
	if (key == KEY_G || key == KEY_I || key == KEY_K)
	{
		pointer->angle = -.523598;
		pointer->angle2 = -.523598;
	}
	if (key == KEY_J || key == KEY_L || key == KEY_H)
	{
		pointer->angle = .523598;
		pointer->angle2 = .523598;
	}
	if (key == KEY_G || key == KEY_H)
		ft_list_frch_scale(pointer->begin, rotate_z, pointer);
	if (key == KEY_I || key == KEY_J)
		ft_list_frch_scale(pointer->begin, rotate_y, pointer);
	if (key == KEY_K || key == KEY_L)
		ft_list_frch_scale(pointer->begin, rotate_x, pointer);
	ft_list_frch_scale(pointer->begin, minx_miny, pointer);
	ft_list_frch_scale(pointer->begin, center, pointer);
	return (0);
}

int			deal_key_rescale(int key, t_point *pointer)
{
	ft_list_frch_scale(pointer->begin, un_center, pointer);
	if (key == KEY_N)
		pointer->scalez = 1.5;
	if (key == KEY_O)
		pointer->scalez = .75;
	if (key == KEY_P || key == KEY_N)
		pointer->scalex = 1.5;
	if (key == KEY_R || key == KEY_O)
		pointer->scalex = .75;
	if (key == KEY_S || key == KEY_N)
		pointer->scaley = 1.5;
	if (key == KEY_T || key == KEY_O)
		pointer->scaley = .75;
	ft_list_frch_scale(pointer->begin, minx_miny, pointer);
	ft_list_frch_scale(pointer->begin, re_scale, pointer);
	ft_list_frch_scale(pointer->begin, minx_miny, pointer);
	ft_list_frch_scale(pointer->begin, center, pointer);
	return (0);
}

int			deal_key(int key, t_point *pointer)
{
	zero_scale(pointer);
	mlx_clear_window(pointer->mlx, pointer->win);
	if (key == ESC)
		exit(0);
	deal_key_trans(key, pointer);
	deal_key_rescale(key, pointer);
	deal_key_rotate(key, pointer);
	zero_scale(pointer);
	null_x(pointer->begin, pointer);
	null_y(pointer->begin, pointer);
	ray_iterator(pointer->begin, pointer);
	return (0);
}
