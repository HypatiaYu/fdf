/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:02:35 by hyu               #+#    #+#             */
/*   Updated: 2020/01/28 12:44:57 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_space(char *str, t_fpoint *iterate)
{
	while (str[iterate->x] != '\0' && (str[iterate->x] == ' '
	|| str[iterate->x] == '\t' || str[iterate->x] == '\n'))
	{
		if (str[iterate->x] == '\n')
		{
			ft_putnbr(iterate->y);
			iterate->y = iterate->y + 1;
		}
		iterate->x = iterate->x + 1;
	}
}

void	ft_word(char *str, t_fpoint *iterate)
{
	while (str[iterate->x] != '\0' && str[iterate->x] != ' '
	&& str[iterate->x] != '\t' && str[iterate->x] != '\n')
		iterate->x = iterate->x + 1;
	iterate->z = iterate->z + 1;
}

int		ft_word_check(char *str, t_fpoint *iterate, t_point *dimensions)
{
	int	j_initial;
	int	initial;

	initial = iterate->z;
	j_initial = iterate->y;
	while (str[iterate->x] != '\0' && iterate->y < j_initial + 1)
	{
		ft_word(str, iterate);
		ft_space(str, iterate);
	}
	if (iterate->z - initial == dimensions->x)
		return (1);
	else
		return (0);
}
