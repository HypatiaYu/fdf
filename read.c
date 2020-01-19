/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:29:50 by hyu               #+#    #+#             */
/*   Updated: 2020/01/18 16:57:57 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_list_foreach(t_fpoint *begin, void (*f)(int *))
{
	if (begin == 0)
		return ;
	while (begin != 0)
	{
		f(&begin->x);
		f(&begin->y);
		f(&begin->z);
		begin = begin->next;
	}
}

t_fpoint		*x_move(t_fpoint *start, t_point size)
{
	t_fpoint	*tmp;
	int			i;

	i = 0;
	tmp = start;
	while (i <= size.x - 1 && start && tmp->next)
	{
		tmp->nextx = tmp->next;
		tmp = tmp->next;
		i = i + 1;
	}
	start = tmp;
	return (start);
}

void			y_listadd(t_fpoint *begin, t_point size)
{
	t_fpoint	*start;
	t_fpoint	*tmp;
	int			j;

	start = begin;
	tmp = begin;
	j = 0;
	while (j < size.y && start)
	{
		start = x_move(start, size);
		tmp->nexty = start;
		j++;
		if (j == size.y && start)
		{
			start->nextx = start->next;
			break ;
		}
		tmp = start->next;
		start = start->next;
	}
}

void			y_list_iterator(t_fpoint *begin, t_point size)
{
	int			i;
	t_fpoint	*start;

	start = begin;
	i = 0;
	y_listadd(start, size);
	i++;
	while (i <= size.x)
	{
		start = start->next;
		y_listadd(start, size);
		i++;
	}
}

void			ray_iterator(t_fpoint *begin, t_point size, t_scaler *pointer)
{
	t_fpoint	*tmp;
	t_fpoint	*stop;

	tmp = begin;
	stop = tmp->nextx;
	while (tmp)
	{
		if (tmp->nextx != NULL)
		{
			stop = tmp->nextx;
			begin->x = begin->x + 1;
			pixel_ray_trace(tmp, stop, pointer);
		}
		if (tmp->nextx == NULL && tmp->nexty != NULL)
		{
			stop = tmp->nexty;
			begin->y = begin->y + 1;
			pixel_ray_trace(tmp, stop, pointer);
		}
		if (tmp->nexty != NULL && tmp->nextx != NULL)
		{
			stop = tmp->nexty;
			begin->y = begin->y + 1;
			pixel_ray_trace(tmp, stop, pointer);
		}
		tmp = tmp->next;
	}
}
