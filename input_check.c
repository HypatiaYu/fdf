/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:02:35 by hyu               #+#    #+#             */
/*   Updated: 2020/01/10 22:02:02 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		search_space(t_point dimensions, char *tile, int *i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;

	if (tile[*i] == '-' || tile[*i] == '+')
            *i = *i + 1;
	if (tile[*i] >= '0' && tile[*i] <= '9')
	{
		k++;
	}
	while (tile[*i] >= '0' && tile[*i] <= '9')
            *i = *i + 1;
	while (tile[*i] == ' '|| tile[*i] == '\t')
            *i = *i + 1;
	while (tile[*i] && tile[*i] != '\n')
	{
		if (tile[*i] == '-' || tile[*i] == '+')
			*i = *i + 1;
		if (tile[*i] >= '0' && tile[*i] <= '9')
		{
			k++;
		}
		else
			break;
		while (tile[*i] >= '0' && tile[*i] <= '9')
			*i = *i + 1;
		while (tile[*i] == ' '|| tile[*i] == '\t')
            *i = *i + 1;
	}
	if (k == dimensions.x)
		return (1);
	else
		return (0);
}

int		search_iterator(t_point dimensions, char *tile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (search_space(dimensions, tile, &i) == 1)
	{
		ft_putchar('s');
		/*ft_putnbr(search_space(dimensions, tile, &i));
		ft_putchar(tile[i]);
		ft_putnbr(i);
		i++;*/
		/*
		
		if (search_space(dimensions, tile, &i) == 1)
		{
			ft_putnbr(j);
			ft_putnbr(i);
			j++;
		}*/
		j++;
		i++;
	}
	ft_putchar('j');
	ft_putchar('\n');
	ft_putnbr(j);
	ft_putchar('\n');
	ft_putnbr(dimensions.y);
	ft_putchar('\n');
	if (j == dimensions.y)
		return (1);
	return (0);
}
