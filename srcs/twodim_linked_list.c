/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_d_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:45:47 by hyu               #+#    #+#             */
/*   Updated: 2020/01/29 16:26:19 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fpoint		*x_move(t_fpoint *start, t_point *size)
{
	t_fpoint	*tmp;
	int			i;

	i = 0;
	tmp = start;
	while (i < size->x - 1 && start && tmp->next)
	{
		tmp->nextx = tmp->next;
		tmp = tmp->next;
		i = i + 1;
	}
	start = tmp;
	return (start);
}

void			y_listadd(t_fpoint *begin, t_point *size)
{
	t_fpoint	*start;
	t_fpoint	*tmp;
	t_fpoint	*node;
	int			j;

	start = begin;
	tmp = begin;
	node = begin;
	j = 0;
	while (j < size->y - 1)
	{
		start = x_move(start, size);
		tmp->nexty = start->next;
		start = start->next;
		tmp = start;
		j = j + 1;
	}
}

void			null_x(t_fpoint *begin, t_point *size)
{
	int			i;
	int			j;
	t_fpoint	*tmp;

	i = -1;
	j = -1;
	tmp = begin;
	while (++i < size->x - 1)
	{
		tmp = tmp->nextx;
	}
	while (++j < size->y - 1)
	{
		tmp->nextx = NULL;
		tmp = tmp->nexty;
	}
}

void			null_y(t_fpoint *begin, t_point *size)
{
	int			i;
	int			j;
	t_fpoint	*tmp;

	i = 0;
	j = 0;
	tmp = begin;
	while (j < size->y - 1)
	{
		tmp = tmp->nexty;
		j++;
	}
	while (i < size->x)
	{
		tmp->nexty = NULL;
		tmp = tmp->next;
		i++;
	}
}

void			y_list_iterator(t_fpoint *begin, t_point *size)
{
	int			i;
	t_fpoint	*start;

	start = begin;
	i = 0;
	y_listadd(start, size);
	i++;
	while (i <= size->x)
	{
		start = start->next;
		y_listadd(start, size);
		i++;
	}
	null_x(begin, size);
	null_y(begin, size);
}
