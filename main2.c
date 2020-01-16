/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:50:43 by hyu               #+#    #+#             */
/*   Updated: 2020/01/15 17:19:31 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int     atoi_iterator(char *tile, int *i)
{
    int     j;

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

void	ft_space(char *str, int *i, int *j)
{
	while (str[*i] != '\0' && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
	{
		if (str[*i] == '\n')
		{
			ft_putnbr(*j);
			*j = *j + 1;
		}
	*i = *i + 1;
	}
}

void	ft_word(char *str, int *i, int *k)
{
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
		*i = *i + 1;
	*k = *k + 1;
}

int		ft_word_check(char *str, int *i, int *k, t_point *dimensions, int *j)
{
	int	j_initial;
	int	initial;

	initial = *k;
	j_initial = *j;
	while (str[*i] != '\0' && *j < j_initial + 1)
    {
		ft_word(str, i, k);
		ft_space(str, i, j);
	}
	if (*k - initial == dimensions->x)
		return (1);
	else
		return (0);
}

int		ft_numword(char *str, t_point *dimensions)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	ft_space(str, &i, &k);
	while (str[i] != '\0' && j < 1)
	{
		ft_word(str, &i, &k);
		ft_space(str, &i, &j);
	}
	dimensions->x = k;
	while (str[i] != '\0')
	{
		if (ft_word_check(str, &i, &k, dimensions, &j) == 0)
			dimensions->valid = 0;
		ft_space(str, &i, &j);
	}
	
	dimensions->y = j;
	dimensions->word = k;
	return (k);
}

char	**ft_split(char *str, t_point *dimensions)
{
	char **array;
	int		words;
	int		i;
	int		j;
	int		k;
	int		l;

	dimensions->valid = 1;
	dimensions->word = 0;
	words = ft_numword(str, dimensions);
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	array = (char**)malloc((words + 1)* sizeof(char*));
	ft_space(str, &i, &j);
	while (l < words)
	{
		array[l] = &str[i];
		l++;
		ft_word(str, &i, &k);
		str[i] = '\0';
		i++;
		ft_space(str, &i, &j);
	}
	
	array[words] = NULL;
	return (array);
}


t_fpoint    *create_fpoint_node(int x, int y, int z)
{
    t_fpoint *new;

    new = malloc(sizeof(t_fpoint));
    new->x = x;
    new->y = y;
    new->z = z;
    new->nextx = NULL;
    new->nexty = NULL;
    return (new);
}

t_fpoint	*ft_listadd_2(t_point *size, char **str)
{
	int i;
	int j;
	int k;
	t_fpoint *new;
	t_fpoint *node;
	t_fpoint *start;

	i = 0;
	j = 0;
	k = 0;

	node = create_fpoint_node(i, j, ft_atoi(str[k]));
	start = node;
	new = node;
	
	ft_putstr("new");
	ft_putnbr(start->x);
	new->next = NULL;
	i = 0;
	while (i <= size->x - 1)
	{
		node = create_fpoint_node(i, j, ft_atoi(str[k]));
		ft_putstr("new");
		ft_putnbr(new->x);
		new->next = node;
		new = new->next;
		ft_putchar('k');
		ft_putnbr(k);
		k++;
		i++;
	}
	j++;
	while (j <= size->y && k < size->word - 1)
	{
		i = 0;
		while (i <= size->x - 1 && k < size->word)
		{
			node = create_fpoint_node(i, j, ft_atoi(str[k]));
			new->next = node;
			new = new->next;
			ft_putchar('k');
			ft_putnbr(k);
			k++;
			i++;
		}
		j++;
	}
	new->next = NULL;
	ft_putstr("begin");
	return (start);
}

int     deal_key(int key, void *param, void *mlx_ptr, void *win_ptr, t_scaler *scaler, t_fpoint *begin)
{

    if (key == ESC)
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        free(mlx_ptr);
        free(win_ptr);
		free(begin);
		exit(0);
        //free_n_exit(mlx_ptr);
        //exit(0);
        return (0);
        //ft_putchar('a');
    }

    if (key == KEY_1)
    {
        mlx_new_window(mlx_ptr, 500, 500, "Window 2");
    }


    if (key == KEY_2)
    {
        mlx_clear_window(mlx_ptr, win_ptr);
    }
    else
        ft_putchar('b');
    return (0);
}

int		main(void)
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
	ft_putchar('a');

	dimensions = malloc(sizeof(t_point));

	split = ft_split(tile, dimensions);

	t_fpoint *begin;
	t_fpoint *head;

	begin = malloc(sizeof(t_fpoint));
	head = begin;
	
	begin = ft_listadd_2(dimensions, split);
	
	ft_putstr("begin->x");
	ft_putnbr(begin->x);

	ft_putchar('\n');

	i = 0;
	
	y_list_iterator(begin, *dimensions);
	ft_putchar('x');
	ft_putnbr(dimensions->x);
	ft_putchar('x');
	ft_putchar('y');
	ft_putnbr(dimensions->y);
	ft_putchar('y');
	//ft_putnbr(head->x);
	ft_putchar('x');

	i = 0;

	void    *mlx_ptr;
    void    *win_ptr;
	t_point window_size;

    window_size.x = 500;
    window_size.y = 500;
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window_size.x, window_size.y, "New Window");
	ft_putstr("start");
	ft_putnbr(begin->x);
	ft_putstr("start");
	
	int scaler;
    double  ar;
    t_scaler *scale;
    scaler = 10;
    window_size.x = 500;
    window_size.y = 500;
    ar = 1;

	scale = ft_scaling(*dimensions, window_size, scaler, ar);
	ft_list_frch_scale(begin, x_scale, scale);
	scale->angle = 40;
	scale->angle2 = -50;
	ft_list_frch_scale(begin, rotate_y, scale);
	ft_putstr("dimensions");
	ft_putnbr(dimensions->y);
	scale->x_trans = 0;
	scale->y_trans = 0;
	ft_list_frch_scale(begin, center, scale);
	//pixel_ray_trace(begin, begin->nexty, mlx_ptr, win_ptr);
	ray_iterator(begin, *dimensions, mlx_ptr, win_ptr);
	//scale->x_trans = 200;
	//scaler = 30;
	//mlx_new_window(mlx_ptr, 500, 500, "Window 2");
	//ft_list_frch_scale(begin, x_scale, scale);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);

	//int scaler;

	//scaler = 100;
    //ft_list_frch(ptra, x_scale, scaler);
	
	return (0);
}
