/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:32:29 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 11:00:32 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	char *tile;
	t_fpoint *iterate;
	t_fpoint *begin;
	t_point	*dimensions;

	if (argc != 2)
    {
        ft_putstr("Error: Invalid number of arguments");
        exit(0);
    }
	dimensions = malloc(sizeof(t_point));	
	tile = ft_error(argv[1]);
	begin = ft_set_dimensions(tile, dimensions);
	y_listadd(begin, dimensions);
	dimensions = ft_set_scaling(dimensions, begin);
	graphics_display(dimensions, begin);

	/*int i;

	i = 0;
	
	while (begin)
    {
		ft_putchar('a');
		ft_putnbr(i);
		ft_putchar('y');
        ft_putnbr(begin->y);
		begin = begin->nextx;
		i++;
	}*/
	
	//y_list_iterator(begin, dimensions);
	//ft_putchar('e');
	/*while (begin)
	{
		ft_putchar('z');
		ft_putnbr(begin->y);
		begin = begin->next;
	}*/
	return (0);
}
