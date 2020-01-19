/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:59:50 by hyu               #+#    #+#             */
/*   Updated: 2020/01/19 15:17:01 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	translate_x_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
    pointer->x_trans = 10;
    ft_list_frch_scale(pointer->begin, translation_x, pointer);
    ray_iterator(pointer->begin, *pointer->size, pointer);
}

void	translate_mx_mlx(t_scaler *pointer)
{
	 mlx_clear_window(pointer->mlx, pointer->win);
	 pointer->x_trans = -10;
	 ft_list_frch_scale(pointer->begin, translation_x, pointer);
	 ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    translate_y_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
	pointer->y_trans = 10;
	ft_list_frch_scale(pointer->begin, translation_y, pointer);
	ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    translate_my_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
	pointer->y_trans = -10;
	ft_list_frch_scale(pointer->begin, translation_y, pointer);
	ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    translate_z_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->z_trans = 10;
        ft_list_frch_scale(pointer->begin, translation_z, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    translate_mz_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->z_trans = -10;
        ft_list_frch_scale(pointer->begin, translation_z, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    translate_rotz_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = 10;
        pointer->angle2 = 10;
        ft_list_frch_scale(pointer->begin, rotate_z, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    rotate_mz_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = -10;
        pointer->angle2 = -10;
        ft_list_frch_scale(pointer->begin, rotate_z, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    rotate_y_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = 10;
        pointer->angle2 = 10;
        ft_list_frch_scale(pointer->begin, rotate_y, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    rotate_my_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = -10;
        pointer->angle2 = -10;
        ft_list_frch_scale(pointer->begin, rotate_y, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    rotate_x_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = -10;
        pointer->angle2 = -10;
        ft_list_frch_scale(pointer->begin, rotate_x, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    make_bigger_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_bigger, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    make_smaller_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_smaller, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    make_wider_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_wider, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    make_skinnier_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_skinnier, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}

void    make_taller_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_taller, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    make_shorter_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, make_shorter, pointer);
        ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}


void    perspective_mlx(t_scaler *pointer)
{
	mlx_clear_window(pointer->mlx, pointer->win);
        pointer->angle = 15;
        pointer->angle2 = 25;

        //ft_list_frch_scale(pointer->begin, un_center, pointer);
        ft_list_frch_scale(pointer->begin, perspective_projection, pointer);
        //ft_list_frch_scale(pointer->begin, center, pointer);
        ray_iterator(pointer->begin, *pointer->size, pointer);
}
/*
void    translate_mx_mlx(t_scaler *pointer)
{
}*/

/*
void    translate_mx_mlx(t_scaler *pointer)
{
}*/
int		deal_key(int key, t_scaler *pointer)
{
	void 	(*ptr)(t_scaler *);
	if (key == ESC)
		exit(0);
	if (key == KEY_A)
		ptr = &translate_x_mlx;
	if (key == KEY_B)
		ptr = &translate_mx_mlx;
	if (key == KEY_C)
		ptr = &translate_y_mlx;
	if (key == KEY_D)
		ptr = &translate_my_mlx;
	if (key == KEY_G)
		ptr = &translate_rotz_mlx;
	if (key == KEY_H)
		ptr = &rotate_mz_mlx;
	if (key == KEY_I)
		ptr = &rotate_y_mlx;
	if (key == KEY_J)
		ptr = &rotate_my_mlx;
	if (key == KEY_L)
		ptr = &rotate_x_mlx;
	if (key == KEY_M)
	{
		mlx_clear_window(pointer->mlx, pointer->win);
		pointer->angle = 35;
		pointer->angle2 = 45;
		ft_list_frch_scale(pointer->begin, isometric_rotate, pointer);
		ray_iterator(pointer->begin, *pointer->size, pointer);
	}
	if (key == KEY_N)
		ptr = &make_bigger_mlx;
	if (key == KEY_O)
		ptr = &make_smaller_mlx;
	if (key == KEY_P)
		ptr = &make_wider_mlx;
	if (key == KEY_R)
		ptr = &make_skinnier_mlx;
	if (key == KEY_S)
		ptr = &make_taller_mlx;
	if (key == KEY_T)
		ptr = &perspective_mlx;
	ptr(pointer);
	return (0);
}
