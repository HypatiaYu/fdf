/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:43:11 by hyu               #+#    #+#             */
/*   Updated: 2020/01/31 21:20:56 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fpoint		*ft_move_node(t_fpoint *iterate, t_point *size, char **str,
				t_fpoint *new)
{
	while (iterate->x <= size->x - 1)
	{
		new->next = create_fpoint_node(iterate, str, new->next);
		new = new->next;
		iterate->z = iterate->z + 1;
		iterate->x = iterate->x + 1;
	}
	return (new);
}

void			iterate_x_z(t_fpoint *iterate)
{
	iterate->x = iterate->x + 1;
	iterate->z = iterate->z + 1;
}

t_fpoint		*ft_listadd_2(t_point *size, char **str, t_fpoint *iterate)
{
	t_fpoint	*new;
	t_fpoint	*start;

	iterate_zero(iterate);
	while (iterate->y <= size->y && iterate->z < size->word - 1)
	{
		iterate->x = 0;
		if (iterate->y == 0)
		{
			new = create_fpoint_node(iterate, str, new);
			start = new;
			iterate_x_z(iterate);
		}
		while (iterate->x <= size->x - 1 && iterate->z < size->word)
		{
			new->next = create_fpoint_node(iterate, str, new->next);
			new = new->next;
			iterate_x_z(iterate);
		}
		iterate->y = iterate->y + 1;
	}
	new->next = NULL;
	return (start);
}

t_fpoint		*create_fpoint_node(t_fpoint *iterate, char **str,
				t_fpoint *new)
{
	new = malloc(sizeof(t_fpoint));
	new->x = iterate->x;
	new->y = iterate->y;
	new->z = ft_atoi(str[iterate->z]);
	new->nextx = NULL;
	new->nexty = NULL;
	ft_ishex(str[iterate->z], new);
	return (new);
}
