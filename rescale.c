/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:20:01 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 11:24:09 by hyu              ###   ########.fr       */
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
