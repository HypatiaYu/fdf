/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:44:47 by hyu               #+#    #+#             */
/*   Updated: 2020/02/01 16:25:34 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_set_dimensions(t_point *dimensions, char *tile, char **split)
{
	t_fpoint	*iterate;

	split = ft_split(tile, dimensions, iterate);
	if (dimensions->valid == 0)
	{
		ft_putstr("Invalid Input");
		return (0);
		exit(0);
	}
	free(iterate);
	return (0);
}
