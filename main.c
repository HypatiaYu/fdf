/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:32:29 by hyu               #+#    #+#             */
/*   Updated: 2020/02/01 18:36:01 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void			free_begin(t_fpoint *begin)
{
	t_fpoint	*tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

void			free_dimensions(t_point *dimensions)
{
	free(dimensions->mlx);
	free(dimensions->win);
	free(dimensions);
}

int				main(int argc, char **argv)
{
	char		*tile;
	t_fpoint	*iterate;
	t_fpoint	*begin;
	t_point		*dimensions;

	if (argc != 2)
	{
		ft_putstr("Error: Invalid number of arguments");
		exit(0);
	}
	dimensions = malloc(sizeof(t_point));
	tile = ft_error(argv[1]);
	//ft_putstr(tile);
	begin = ft_set_dimensions(tile, dimensions);
	/*while (begin)
	{
		ft_putnbr(begin->z);
		begin = begin->next;
	}*/
	y_list_iterator(begin, dimensions);
	dimensions = ft_set_scaling(dimensions, begin);
	graphics_display(dimensions, begin);
	free(tile);
	free_begin(begin);
	free(iterate);
	return (0);
}
