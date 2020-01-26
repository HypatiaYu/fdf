/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:51:18 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 14:48:49 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void	make_bigger(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (begin->x) * (scaler->scale);
	begin->y = (begin->y) * (scaler->scale);
	begin->z = (begin->z) * (scaler->scale);
}

void	make_smaller(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = (begin->x) / (scaler->scale);
	begin->y = (begin->y) / (scaler->scale);
	begin->z = (begin->z) / (scaler->scale);
}

void	make_wider(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = begin->x * 1.5;
}

void	make_skinnier(t_fpoint *begin, t_scaler *scaler)
{
	begin->x = begin->x / 1.5;
}

void	make_taller(t_fpoint *begin, t_scaler *scaler)
{
	begin->y = begin->y * 1.5;
}

void	make_shorter(t_fpoint *begin, t_scaler *scaler)
{
	begin->y = begin->y / 1.5;
}

void	un_center(t_fpoint *begin, t_scaler *scaler)
{
	int center_x;
	int center_y;

	center_x = scaler->win_x / 2;
	center_y = scaler->win_y / 2;
	begin->x = begin->x - center_x +
	(scaler->x_dim) * (scaler->scale) * (scaler->aspect_ratio) / 2 -
	scaler->x_trans;
	begin->y = begin->y - center_y +
	(scaler->y_dim) * (scaler->scale) / (scaler->aspect_ratio * 2) -
	scaler->y_trans;
}
