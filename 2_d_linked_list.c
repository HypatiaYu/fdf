/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_d_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:45:47 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 21:08:45 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	//start->nextx = NULL;
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
	node  = begin;
	j = 0;
	while (j < size->y - 1)
	{
		start = x_move(start, size);
		//start->nextx = NULL;
		tmp->nexty = start->next;
		start = start->next;
		tmp = start;
		//ft_putnbr(j);
		j = j + 1;
	}
	//tmp->nexty = NULL;
}

void			NULL_x(t_fpoint *begin, t_point *size)
{
	int i;
	int j;
	t_fpoint *tmp;

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

void		NULL_y(t_fpoint *begin, t_point *size)
{
	int i;
	int j;
	t_fpoint *tmp;

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
	NULL_x(begin, size);
	NULL_y(begin, size);
}

