/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:44:47 by hyu               #+#    #+#             */
/*   Updated: 2020/01/29 14:50:23 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_error(char *file_name)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: FD Failed");
		close (fd);
		exit (0);
	}
	close(fd);
	return (0);
}

char			*ft_readfile(char *name)
{
	int			fd;
	char		*line;
	char		*tile;

	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (tile == NULL)
			tile = ft_strnew(1);
		if (tile)
		{
			tile = ft_strjoin(tile, line);
			tile = ft_strjoin(tile, "\n");
		}
	}
	return (tile);
}

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
	return (0);
}
