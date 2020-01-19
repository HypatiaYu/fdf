/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:10:26 by hyu               #+#    #+#             */
/*   Updated: 2020/01/18 17:51:21 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int			atoi_iterator(char *tile, int *i)
{
	int		j;

	j = ft_atoi(&tile[*i]);
	while (tile[*i] != '\0' && (tile[*i] == ' ' || tile[*i] == '\t'))
		*i = *i + 1;
	return (j);
}

void		skipletter(char *tile, int *i)
{
	while (tile[*i] != '\0' && tile[*i] != ' ' && tile[*i] != '\t')
		*i = *i + 1;
}

void		assign_hex(t_fpoint *node, char *str, int *i)
{
	int num;

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
	int	i;

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

int			ft_numword(char *str, t_point *dimensions)
{
	t_fpoint *iterate;

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
	return (iterate->z);
}

char			**ft_split(char *str, t_point *dimensions)
{
	char		**array;
	int			words;
	t_fpoint	*iterate;
	int			l;

	iterate = malloc(sizeof(t_fpoint));
	iterate->x = 0;
	iterate->y = 0;
	iterate->z = 0;
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

t_fpoint		*create_fpoint_node(int x, int y, int z)
{
	t_fpoint 	*new;

	new = malloc(sizeof(t_fpoint));
	new->x = x;
	new->y = y;
	new->z = z;
	new->nextx = NULL;
	new->nexty = NULL;
	return (new);
}

t_fpoint		*ft_listadd_2(t_point *size, char **str)
{
	t_fpoint	iterate;
	t_fpoint 	*new;
	t_fpoint 	*node;
	t_fpoint 	*start;

	iterate.x = 0;
	iterate.y = 0;
	iterate.z = 0;
	node = create_fpoint_node(iterate.x, iterate.y, ft_atoi(str[iterate.z]));
	start = node;
	new = node;
	new->next = NULL;

	while (iterate.x <= size->x - 1)
	{
		node = create_fpoint_node(iterate.x, iterate.y, ft_atoi(str[iterate.z]));
		ft_ishex(str[iterate.z], node);
		new->next = node;
		new = new->next;
		iterate.z = iterate.z + 1;
		iterate.x = iterate.x + 1;
	}
	iterate.y = iterate.y + 1;
	while (iterate.y <= size->y && iterate.z < size->word - 1)
	{
		iterate.x = 0;
		while (iterate.x <= size->x - 1 && iterate.z < size->word)
		{
			node = create_fpoint_node(iterate.x, iterate.y, ft_atoi(str[iterate.z]));
			new->next = node;
			new = new->next;
			iterate.z = iterate.z + 1;
			iterate.x = iterate.x + 1;
		}
		iterate.y = iterate.y + 1;
	}
	new->next = NULL;
	return (start);
}

int			main(void)
{
	int		fd;
	char	*line;
	char	*tile;
	char 	*tile2;

	fd = open("test_maps/test_maps/42.fdf", O_RDONLY);
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

	char **split;
	t_point *dimensions;
	int		i;

	i = 0;
	dimensions = malloc(sizeof(t_point));
	split = ft_split(tile, dimensions);
	if (dimensions->valid == 0)
	{
		ft_putstr("Invalid Input");
		return (0);
	}	
	t_fpoint *begin;
	t_fpoint *head;
	begin = malloc(sizeof(t_fpoint));
	head = begin;
	begin = ft_listadd_2(dimensions, split);
	y_list_iterator(begin, *dimensions);
	i = 0;
	void    *mlx_ptr;
	void    *win_ptr;
	t_point window_size;
	window_size.x = 500;
	window_size.y = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window_size.x, window_size.y, "New Window");
	int scaler;
	double  ar;
	t_scaler *scale;
	scaler = 3;
	ar = 1;
	scale = ft_scaling(*dimensions, window_size, scaler, ar);
	ft_list_frch_scale(begin, x_scale, scale);
	scale->angle = 10;
	scale->angle2 = 10;
	scale->x_trans = 0;
	scale->y_trans = 0;
	scale->z_trans = 0;
	scale->begin = begin;
	scale->head = head;
	scale->scale = 3;
	ft_list_frch_scale(begin, center, scale);
	ft_putstr("begin");
	ft_putnbr(begin->x);
	scale->mlx = mlx_ptr;
	scale->win = win_ptr;
	scale->size = dimensions;
	y_list_iterator(begin, *dimensions);
	ray_iterator(begin, *dimensions, scale);
	mlx_key_hook(scale->win, deal_key, scale);
	mlx_loop(mlx_ptr);
	return (0);
}
