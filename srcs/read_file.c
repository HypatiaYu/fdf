/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:55:21 by hyu               #+#    #+#             */
/*   Updated: 2020/01/30 16:38:42 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char				*ft_error(char *file_name)
{
	int				fd;
	char			*line;
	char			*tile;
	char			*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: FD Failed");
		close (fd);
		exit (0);
	}
	tile = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		if (tile)
		{
			tmp = line;
			line = ft_strjoin(line, "\n");
			tmp = ft_strjoin(tile, line);
			tile = tmp;
		}
	}
	close(fd);
	return (tile);
}

void			iterate_zero(t_fpoint *iterate)
{
	iterate->x = 0;
	iterate->y = 0;
	iterate->z = 0;
}

char			**ft_split(char *str, t_point *dimensions)
{
	t_fpoint	*iterate;
	char		**array;
	int			words;
	int			l;

	iterate = malloc(sizeof(t_fpoint));
	iterate_zero(iterate);
	dimensions->valid = 1;
	dimensions->word = 0;
	words = ft_numword(str, dimensions);
	l = 0;
	array = (char**)malloc((words + 1) * sizeof(char*));
	ft_space(str, iterate);
	while (l < words)
	{
		array[l] = &str[iterate->x];
		l++;
		ft_word(str, iterate);
		str[iterate->x] = '\0';
		iterate->x = iterate->x + 1;
		ft_space(str, iterate);
	}
	array[words] = NULL;
	return (array);
}

t_fpoint		*ft_set_dimensions(char *tile, t_point *dimensions)
{
	t_fpoint	*iterate;
	t_fpoint	*begin;
	char		**split;

	split = ft_split(tile, dimensions);
	iterate = malloc(sizeof(iterate));
	if (dimensions->valid == 0)
	{
		ft_putstr("Invalid Input");
		exit(0);
	}
	begin = ft_listadd_2(dimensions, split, iterate);
	return (begin);
}
