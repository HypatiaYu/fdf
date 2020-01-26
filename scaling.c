/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 14:10:55 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			translation_xyz(t_fpoint *list, t_point *dimensions)
{
	list->x = list->x + dimensions->x_trans;
	list->y = list->y + dimensions->y_trans;
	list->z = list->z + dimensions->z_trans;
}

