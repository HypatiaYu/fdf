/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:38:53 by hyu               #+#    #+#             */
/*   Updated: 2020/02/01 16:45:59 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_atoi_base(int j)
{
	int			i;

	i = 0;
	while (j > 10)
	{
		i = i * 16 + (j % 16);
		j = j / 16;
	}
	return (j);
}

void			assign_hex(t_fpoint *node, char *str, int *i)
{
	int			num;

	num = 0;
	if (str[*i] == ',')
		*i = *i + 3;
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
	{
		num = num * 10 + str[*i] + '0';
		*i = *i + 1;
	}
	node->hex = 0xFFFFFF;
}

void			ft_ishex(char *str, t_fpoint *begin)
{
	int			i;

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
