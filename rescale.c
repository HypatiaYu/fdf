/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:20:01 by hyu               #+#    #+#             */
/*   Updated: 2020/01/27 12:38:15 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_list_frch_scale(t_fpoint *begin, void (*f)(t_fpoint *begin,
t_point *dimensions), t_point *dimensions)
{
	t_fpoint	*tmp;

	tmp = begin;
	if (begin == 0)
		return ;
	while (tmp != 0)
	{
		f(tmp, dimensions);
		tmp = tmp->next;
	}
}

void			re_scale(t_fpoint *begin, t_point *dimensions)
{
	begin->x = (dimensions->scalex) * (begin->x);
	begin->y = (dimensions->scaley) * (begin->y);
	begin->z = (dimensions->scalez) * (begin->z);
}

void	minx_miny(t_fpoint *pointer, t_point *dimensions)
{
	if (dimensions->min_x > pointer->x)
		dimensions->min_x = pointer->x;
	if (dimensions->max_x < pointer->x)
		dimensions->max_x = pointer->x;
	if (dimensions->min_y > pointer->y)
		dimensions->min_y = pointer->y;
	if (dimensions->max_y < pointer->y)
		dimensions->max_y = pointer->y;
}

void    un_center(t_fpoint *begin, t_point *dimensions)
{
	int center_x;
	int center_y;

	ft_list_frch_scale(begin, minx_miny, dimensions);
	center_x = dimensions->win_x / 2;
	center_y = dimensions->win_y / 2;
	begin->x = begin->x - center_x + (dimensions->max_x - dimensions->min_x) / 2 -
		dimensions->x_trans + dimensions->min_x;
	begin->y = begin->y - center_y + (dimensions->max_y - dimensions->min_y) / 2 -
		dimensions->y_trans + dimensions->min_y;
}

void            center(t_fpoint *list, t_point *dimensions)
{
	int         center_x;
	int         center_y;

	ft_list_frch_scale(list, minx_miny, dimensions);
	center_x = dimensions->win_x / 2;
	center_y = dimensions->win_y / 2;
	list->x = list->x + center_x - (dimensions->max_x - dimensions->min_x)/2 +
		dimensions->x_trans - dimensions->min_x;
	list->y = list->y + center_y - (dimensions->max_y - dimensions->min_y)/2 +
		dimensions->y_trans - dimensions->min_y;
}

