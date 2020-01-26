/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 11:29:27 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_list_frch_scale(t_fpoint *begin, void (*f)(t_fpoint *begin,
t_scaler *scaler), t_scaler *scaler)
{
	t_fpoint	*tmp;
	
	tmp = begin;
	if (begin == 0)
		return ;
	while (tmp != 0)
	{
		f(tmp, scaler);
		tmp = tmp->next;
	}
}

t_scaler		*ft_scaling(t_point dimensions, t_point window_size,
int scaling, int ar)
{
	t_scaler	*scaler;

	scaler = malloc(sizeof(t_scaler));
	scaler->x_dim = dimensions.x;
	scaler->y_dim = dimensions.y;
	scaler->win_x = window_size.x;
	scaler->win_y = window_size.y;
	scaler->x_center = window_size.x / 2;
	scaler->y_center = window_size.y / 2;
	scaler->scale = scaling;
	scaler->aspect_ratio = ar;
	return (scaler);
}

void			center(t_fpoint *list, t_scaler *scaler)
{
	int			center_x;
	int			center_y;

	center_x = scaler->win_x / 2;
	center_y = scaler->win_y / 2;
	list->x = list->x + center_x -
	(scaler->x_dim) * (scaler->scale) * (scaler->aspect_ratio) / 2 +
	scaler->x_trans;
	list->y = list->y + center_y -
	(scaler->y_dim) * (scaler->scale) / (scaler->aspect_ratio * 2) +
	scaler->y_trans;
}

void			translation_x(t_fpoint *list, t_scaler *scaler)
{
	list->x = list->x + scaler->x_trans;
}

void			translation_y(t_fpoint *list, t_scaler *scaler)
{
	list->y = list->y + scaler->y_trans;
}

void			translation_z(t_fpoint *list, t_scaler *scaler)
{
	list->z = list->z + scaler->z_trans;
}

void			x_scale(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (scaler->scale) * (begin->x);
	begin->y = (scaler->scale) * (begin->y);
	begin->z = (scaler->scale) * (begin->z);
}
