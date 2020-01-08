/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:50:43 by hyu               #+#    #+#             */
/*   Updated: 2020/01/07 09:58:38 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"
#include "minilibx/mlx.h"
#include <math.h>
#define PI 3.14159265

int		x_dimensions(char *tile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (tile[i] != '\n')
	{
		if (tile[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int		y_dimensions(char *tile)
{
	int	i;
	int	len;

	i = 0;
	while (tile[i] != '\n')
		i++;
	len = ft_strlen(tile);
	return (len/i);
}

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

int		**makemap(t_point size, char *tile)
{
	int **map;
	int		i;
	int		j;
	int		k;

	map = (int**)malloc(sizeof(int*)*((int)size.y));

	i = 0;
	k = 0;
	while (i < (int)size.y)
	{
		j = 0;
		map[i] = (int*)malloc(((int)size.x)*sizeof(int));

		while (j < (int)size.x)
		{
			map[i][j] = atoi_iterator(tile, &k);
			skipletter(tile, &k);
			j++;
		}
		ft_putchar('\n');
		i++;
	}

	return (map);
}

t_point *coordinate(int **map, t_point size)
{
	int		spaces;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	t_point *coord;

	spaces = (size.x)*(size.y) + 1;
	coord = (t_point*)malloc(spaces*sizeof(t_point));
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			coord[k].x = i;
			ft_putnbr(coord[k].x);
			coord[k].y = j;
			ft_putnbr(k);
			ft_putchar('\n');
			ft_putnbr(coord[k].y);
			coord[k].z = map[j][i];
			k++;
			i++;
		}
		j++;
	}
	ft_putchar('\n');
	ft_putnbr(coord[50].x);
	return (coord);
}

void    pixel_ray_trace(t_point *array, t_point size, t_point window_size)
{
    void    *mlx_ptr;
    void    *win_ptr;

    int slope;
    int y_0;
    int x_0;
    int x_f;

    int i;
	int	length;

    i = 0;
	length = size.x * size.y + 1;

    slope = (array[i + 1].y - array[i].y)/(array[i + 1].x - array[i].x);
    y_0 = (window_size.y)*(array[i].y)/size.y;
    x_0 = (window_size.x)*(array[i].x)/size.x;
    x_f = (window_size.x)*(array[i].x)/size.x;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, window_size.x, window_size.y, "New Window");
	while (i < length - 1)
	{
		slope = (array[i + 1].y - array[i].y)/(array[i + 1].x - array[i].x);
		y_0 = (window_size.y)*(array[i].y)/size.y;
		x_0 = (window_size.x)*(array[i].x)/size.x;
		x_f = (window_size.x)*(array[i + 1].x)/size.x;
		while (x_0 < x_f)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
			x_0++;
			y_0 = y_0 + slope;
		}
		i++;
	}

    mlx_loop(mlx_ptr);
}

/*void	glOrtho(int *r, int *l, int *t, int *b, int *f, int *n, t_lpoint Matrix)
{
	Matrix.x0[0] = 2 / (*r - *l);
	Matrix.x0[1] = 0;
	Matrix.x0[2] = 0;
	Matrix.x0[3] = -(*r + *l)/(*r - *l);
	Matrix.x1[0] = 0;
    Matrix.x1[1] = 2 / (*t - *b);
    Matrix.x1[2] = 0;
    Matrix.x1[3] = -(*t + *b)/(*t - *b);
    Matrix.x2[0] = 0;
    Matrix.x2[1] = 0;
    Matrix.x2[2] = -2/(*f - *n);
    Matrix.x2[3] = -(*f + *n)/(*f - *n);
    Matrix.x3[0] = 0;
    Matrix.x3[1] = 0;
    Matrix.x3[2] = 0;
    Matrix.x3[3] = 1;
}
*/

void	isometric_rotate(t_point *coord, double angle, double angle2, t_point dimensions)
{
	int		i;
	int		length;
	int	bx;
	int by;
	int bz;

	i = 0;
	length = (dimensions.x) * (dimensions.y) + 1;

	while (i < length)
	{
		bx = (coord[i].x) * (cos(angle*PI/180)) - (coord[i].z)*sin(angle*PI/180);
		by = coord[i].y;
		bz = (coord[i].x) * (sin(angle*PI/180)) + (coord[i].z) * cos(angle*PI/180);
		coord[i].x = bx;
		coord[i].y = by * cos(angle2*PI/180) + bz * sin(angle2*PI/180);
		coord[i].z = -by * sin(angle2*PI/180) + bz * cos(angle2*PI/180);
		i++;
	}
}

int		main(void)
{
	int		fd;
	char	*line;
	char	*tile;
	char 	*tile2;

	fd = open("10-2_fdf_test", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (tile == NULL)
		{
			tile = ft_strnew(0);
			tile2 = tile;
		}
		if (tile)
		{
			tile = ft_strjoin(tile, line);
			tile = ft_strjoin(tile, "\n");
		}
	}

	int	i;
	i = 0;
	
	t_point		dimensions;
	ft_putchar('a');
	dimensions.x = x_dimensions(tile);
	ft_putnbr(dimensions.x);
	ft_putchar('\n');
	dimensions.y = y_dimensions(tile);
	ft_putnbr(dimensions.y);

	int **map;

	map = makemap(dimensions, tile);
	int	j;
	j = 0;
	while (j < dimensions.y)
	{
		i = 0;
		while (i < dimensions.x)
		{
			ft_putnbr(map[j][i]);
			ft_putchar(' ');
			i++;
		}
		j++;
		ft_putchar('\n');
	}
	
	//ft_putnbr(ft_atoi(&tile[1]));
	t_point *coord;

	coord = coordinate(map, dimensions);
	//ft_putnbr(dimensions.x);
	//ft_putchar('\n');
	//ft_putnbr(dimensions.y);
	//ft_putchar('\n');
	//ft_putnbr(coord[3].y);
	
	int		length;

	length = dimensions.x * dimensions.y + 1;
	ft_putnbr(length);

//	pixel_display(coord, dimensions);

	void		*mlx_ptr;
	void		*window_ptr;

	//mlx_ptr = mlx_init();
	//window_ptr = mlx_new_window(mlx_ptr, 500, 500, "New_Window");
	//mlx_loop(mlx_ptr);
	//
	double  angle;
    double  angle2;

    angle = 15.0;
    angle2 = 15.0;
	//isometric_rotate( coord, angle, angle2, dimensions);

	//pixel_display(coord, dimensions);
	t_point window_size;

	window_size.x = 500;
	window_size.y = 500;

	pixel_ray_trace(coord, dimensions, window_size);
	return (0);
}
