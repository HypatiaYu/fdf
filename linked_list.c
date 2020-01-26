/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:43:11 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 09:58:44 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fpoint		*ft_move_node(t_fpoint *iterate, t_point *size, char **str, t_fpoint *new)
{
	while (iterate->x <= size->x - 1)
	{
		new->next = create_fpoint_node(iterate->x, iterate->y, ft_atoi(str[iterate->z]));
		ft_ishex(str[iterate->z], new->next);
		new = new->next;
		iterate->z = iterate->z + 1;
		iterate->x = iterate->x + 1;
	}
	return (new);
}

t_fpoint		*ft_listadd_2(t_point *size, char **str, t_fpoint *iterate)
{
	t_fpoint 	*new;
	t_fpoint 	*start;

	iterate_zero(iterate);
	while (iterate->y <= size->y && iterate->z < size->word - 1)
	{
		iterate->x = 0;
		if (iterate->y == 0)
		{
			start = create_fpoint_node(iterate->x, iterate->y, ft_atoi(str[iterate->z]));
			new = start;
			iterate->x = iterate->x + 1;
		}
		while (iterate->x <= size->x - 1 && iterate->z < size->word)
		{
			new->next = create_fpoint_node(iterate->x, iterate->y, ft_atoi(str[iterate->z]));
			new = new->next;
			iterate->z = iterate->z + 1;
			iterate->x = iterate->x + 1;
		}
		iterate->y = iterate->y + 1;
	}
	new->next = NULL;
	return (start);
}

void		assign_hex(t_fpoint *node, char *str, int *i)
{
	int		num;

	num = 0;
	if (str[*i] == ',')
		*i = *i + 1;
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
	{
		num = num * 10 + str[*i] + '0';
		*i = *i + 1;
	}
	node->hex = num;
}

void		ft_ishex(char *str, t_fpoint *begin)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			assign_hex(begin, str, &i);
		}
		i = i + 1;
	}
}

t_fpoint        *create_fpoint_node(int x, int y, int z)
{
    t_fpoint    *new;

    new = malloc(sizeof(t_fpoint));
    new->x = x;
    new->y = y;
    new->z = z;
    new->nextx = NULL;
    new->nexty = NULL;
    return (new);
}
