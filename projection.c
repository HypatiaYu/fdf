/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:14:38 by hyu               #+#    #+#             */
/*   Updated: 2020/01/09 20:06:27 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	rows = m1.y;
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
	matrix[0][1] = coordinate->y;
	matrix[0][2] = coordinate->z;

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
	output = multiply_matrix(matrix1, output, m1, m3);
	coordinate->x = output[0][0];
	coordinate->y = output[0][1];
	coordinate->z = output[0][2];

	return;
}
int		main(void)
{
	double		**matrix1;
	double		**matrix2;
	double		matrix3[3][3];
	double		**matrix4;
	double		**matrix5;
	double		a;
	double		b;

	a = 35;
	b = 45;

	t_point	m1;
	t_point	m2;

	m1.x = 3;
	m1.y = 3;
	m2.x = 3;
	m2.y = 3;

	matrix1 = (double**)malloc((3) * sizeof(double*));
    matrix2 = (double**)malloc((3) * sizeof(double*));

	int j;
	j = 0;
	while (j < 3)
	{
		matrix1[j] = (double*)malloc((1) * sizeof(double));
		matrix2[j] = (double*)malloc((1) * sizeof(double));
		j++;
	}

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

	multiply_matrix(matrix1, matrix2, m1, m2);

	matrix4 = (double**)malloc((1) * sizeof(double*));
	matrix5 = (double**)malloc((3) * sizeof(double*));

	int		i;

	i = 0;

	matrix4[0] = (double*)malloc((3) * sizeof(double));
    
	while (i < 3)
    { 
		matrix5[i] = (double*)malloc((1) * sizeof(double));
        i++;
    }

	matrix4[0][0] = 1;
	matrix4[0][1] = 4;
	matrix4[0][2] = 0;
	
	matrix5[0][0] = 2;
	matrix5[1][0] = -1;
	matrix5[2][0] = 5;

	//multiply_matrix(matrix4, matrix5);
	t_point	m4;
	t_point m5;

	m4.x = 3;
	m4.y = 1;
	m5.x = 1;
	m5.y = 3;

	double **outputmatrix;

	outputmatrix = multiply_matrix(matrix4, matrix5, m4, m5);
	ft_putnbr(outputmatrix[0][0]);

	t_point	coordinate;
	coordinate.x = 0;
	coordinate.y = 0;
	coordinate.z = -1;
	
	return (0);
}
