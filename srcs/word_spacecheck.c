/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_spacecheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:18:38 by hyu               #+#    #+#             */
/*   Updated: 2020/01/31 20:51:35 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_space(char *str, t_fpoint *iterate)
{
	while (str[iterate->x] != '\0' && (str[iterate->x] == ' '
	|| str[iterate->x] == '\t' || str[iterate->x] == '\n'))
	{
		if (str[iterate->x] == '\n')
		{
			iterate->y = iterate->y + 1;
		}
		iterate->x = iterate->x + 1;
	}
}

void			ft_word(char *str, t_fpoint *iterate)
{
	while (str[iterate->x] != '\0' && str[iterate->x] != ' '
	&& str[iterate->x] != '\t' && str[iterate->x] != '\n')
		iterate->x = iterate->x + 1;
	iterate->z = iterate->z + 1;
}

int				ft_word_check(char *str, t_fpoint *iterate, t_point *dimensions)
{
	int			j_initial;
	int			initial;

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

int				ft_numword(char *str, t_point *dimensions)
{
	t_fpoint	*iterate;
	int			words;

	iterate = malloc(sizeof(t_fpoint));
	iterate->x = 0;
	iterate->y = 0;
	iterate->z = 0;
	ft_space(str, iterate);
	while (str[iterate->x] != '\0' && iterate->y < 1)
	{
		ft_word(str, iterate);
		ft_space(str, iterate);
	}
	dimensions->x = iterate->z;
	while (str[iterate->x] != '\0')
	{
		if (ft_word_check(str, iterate, dimensions) == 0)
			dimensions->valid = 0;
		ft_space(str, iterate);
	}
	dimensions->y = iterate->y;
	dimensions->word = iterate->z;
	words = iterate->z;
	free(iterate);
	return (words);
}

void			zero_scale(t_point *scale)
{
	scale->angle = 30;
	scale->angle2 = 30;
	scale->x_trans = 0;
	scale->y_trans = 0;
	scale->z_trans = 0;
	scale->scalex = 1;
	scale->scaley = 1;
	scale->scalez = 1;
	scale->scale = 1;
}
