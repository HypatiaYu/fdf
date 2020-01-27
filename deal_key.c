/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:26:03 by hyu               #+#    #+#             */
/*   Updated: 2020/01/27 12:46:04 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void        zero_scale(t_point *scale)
{
    scale->angle = 30;
    scale->angle2 = 30;
    scale->x_trans = 0;
    scale->y_trans = 0;
    scale->z_trans = 0;
    scale->scalex = 1;
    scale->scaley = 1;
    scale->scalez = 1;
    scale->scale = 1;
}

int		deal_key_trans(int key, t_point *pointer)
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
	NULL_x(pointer->begin, pointer);
	ft_list_frch_scale(pointer->begin, translation_xyz, pointer);
	return (0);
}

int		deal_key_rescale(int key, t_point *pointer)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_N)
		pointer->scalex = pointer->scaley = pointer->scalez = 1.5;
	if (key == KEY_O)
		pointer->scalex = pointer->scaley = pointer->scalez = .75;
	if (key == KEY_P)
		pointer->scalex = 1.5;
	if (key == KEY_R)
		pointer->scalex = .75;
	if (key == KEY_S)
		pointer->scaley = 1.5;
	if (key == KEY_T)
		pointer->scaley = .75;
	ft_list_frch_scale(pointer->begin, un_center, pointer);
	ft_list_frch_scale(pointer->begin, re_scale, pointer);
	minx_miny(pointer->begin, pointer);
	ft_list_frch_scale(pointer->begin, center, pointer);
	return (0);
}

int		deal_key(int key, t_point *pointer)
{
	zero_scale(pointer);
    mlx_clear_window(pointer->mlx, pointer->win);
	deal_key_trans(key, pointer);
	deal_key_rescale(key, pointer);
	zero_scale(pointer);
    NULL_x(pointer->begin, pointer);
    NULL_y(pointer->begin, pointer);
    ray_iterator(pointer->begin, pointer);
	return (0);
}
