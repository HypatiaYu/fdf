/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:50:43 by hyu               #+#    #+#             */
/*   Updated: 2019/12/21 21:43:18 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"
#include "minilibx/mlx.h"
#include <math.h>

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

double	entry_sum(int i, int j, double **matrix1, double **matrix2)
{
	double	sum;
	int		k;

	sum = 0;
	k = 0;
	while (matrix1[j][k] && matrix2[k][i])
	{
		sum = sum + (matrix1[j][k]) * (matrix2[k][i]);
		k++;
	}
	return (sum);
}

double	**multiply_matrix(double **matrix1, double **matrix2, t_point m1, t_point m2)
{
	int	column;
	int rows;
	int	i;
	int	j;
	double	**rmatrix;
	double	sum;

	column = m2.x;
	//ft_putnbr(column);
	//ft_putchar('\n');
	rows = m1.y;
	//ft_putnbr(rows);
	i = 0;
	j = 0;

	rmatrix = (double**)malloc((rows + 1) * sizeof(double*));

	while (j < rows)
	{
		rmatrix[j] = (double*)malloc((column + 1) * sizeof(double));
		j++;
	}

	j = 0;
	while (j < rows)
	{
		i = 0;
		while (i < column)
		{
			rmatrix[j][i] = entry_sum(i, j, matrix1, matrix2);
			i++;
		}
		j++;
	}
	return (rmatrix);
}

void	convert_coordinate(t_point *coordinate)
{
	double	**matrix1;
	double	**matrix2;
	double	**matrix;
	double	**output;
	int		i;

	i = 0;
	matrix1 = (double**)malloc((3) * sizeof(double*));
    matrix2 = (double**)malloc((3) * sizeof(double*));
	matrix = (double**)malloc((3) * sizeof(double*));
	while (i < 3)
	{
		matrix1[i] = (double*)malloc((1) * sizeof(double));
        matrix2[i] = (double*)malloc((1) * sizeof(double));
		matrix[i] = (double*)malloc(sizeof(double));
		i++;
	}

	double      a;
    double      b;

    a = 35;
    b = 45;

	matrix1[0][0] = 1;
    matrix1[0][1] = 0;
    matrix1[0][2] = 0;
    matrix1[1][0] = 0;
    matrix1[1][1] = cos(a);
    matrix1[1][2] = sin(a);
    matrix1[2][0] = 0;
    matrix1[2][1] = -sin(a);
    matrix1[2][2] = cos(a);

    matrix2[0][0] = cos(b);
    matrix2[0][1] = 0;
    matrix2[0][2] = -sin(b);
    matrix2[1][0] = 0;
    matrix2[1][1] = 1;
    matrix2[1][2] = 0;
    matrix2[2][0] = sin(b);
    matrix2[2][1] = 0;
    matrix2[2][2] = cos(b);

	/*convert t_point to double matrix*/
	matrix[0][0] = coordinate->x;
	matrix[1][0] = coordinate->y;
	matrix[2][0] = coordinate->z;

	/*get matrix dimensions*/

	t_point m1;
    t_point m2;
	t_point m3;

    m1.x = 3;
    m1.y = 3;
    m2.x = 1;
    m2.y = 3;
	m3.x = 3;
	m3.y = 1;

	output = multiply_matrix(matrix2, matrix, m1, m2);
	output = multiply_matrix(matrix1, output, m1, m2);
	coordinate->x = output[0][0];
	coordinate->y = output[1][0];
	//coordinate->z = output[2][0];

	return;
}

void    pixel_display(t_point *array, t_point size)
{
    void    *mlx_ptr;
    void    *win_ptr;
	int		length;
    int     i;

    i = 0;
	length = size.x * size.y + 1;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "New_Window");
	
    while (i < length)
    {
		convert_coordinate(&array[i]);
		mlx_pixel_put(mlx_ptr, win_ptr, (500/size.x)*array[i].x, (500/size.y)*array[i].y, 0xFFFFFF);
        i++;
	}
	mlx_loop(mlx_ptr);
}

/*int		**glOrtho(int *r, int *l, int *t, int *b, int *f, int *n)
{
	int		Matrix[4][4];

	Matrix[0][0] = 2 / (*r - *l);
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;
	Matrix[0][3] = -(*r + *l)/(*r - *l);
	Matrix[1][0] = 0;
	Matrix[1][1] = 2 / (*t - *b);
	Matrix[1][2] = 0;
	Matrix[1][3] = -(*t + *b)/(*t - *b);
	Matrix[2][0] = 0;
	Matrix[2][1] = 0;
	Matrix[2][2] = -2/(*f - *n);
	Matrix[2][3] = -(*f + *n)/(*f - *n);
	Matrix[3][0] = 0;
	Matrix[3][1] = 0;
	Matrix[3][2] = 0;
	Matrix[3][3] = 1;

	return (Matrix);
}
*/

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
	ft_putnbr(dimensions.x);
	ft_putchar('\n');
	ft_putnbr(dimensions.y);
	//ft_putchar('\n');
	//ft_putnbr(coord[3].y);
	
	int		length;

	length = dimensions.x * dimensions.y + 1;
	ft_putnbr(length);

	//pixel_display(coord, dimensions);

	/*void		*mlx_ptr;
	void		*window_ptr;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "New_Window");
	mlx_loop(mlx_ptr);*/
	//coordinate_change(coord, dimensions);
	pixel_display(coord, dimensions);
	return (0);
}
