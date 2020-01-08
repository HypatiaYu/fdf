/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:51:18 by hyu               #+#    #+#             */
/*   Updated: 2019/12/28 16:46:19 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "minilibx/mlx.h"
#include "stdlib.h"
#include "libft/libft.h"
#include <unistd.h>
#define PI 3.14159265

void	rotate_z(t_point *coord, double angle, t_point dimensions)
{
	int		i;
	int		length;

	i = 0;
	length = (dimensions.x)*(dimensions.y) + 1;

	while (i < length)
	{
		ft_putnbr(coord[i].x);
		coord[i].x = (coord[i].x)*cos(angle*PI/180) - (coord[i].y)*sin(angle * PI/180);
		ft_putnbr(coord[i].x);
		ft_putnbr(coord[i].y);
		coord[i].y = (coord[i].x)*sin(angle*PI/180) + (coord[i].y)*cos(angle*PI/180);
		ft_putnbr(coord[i].y);
		i++;
	}
}

void	rotate_x(t_point *coord, double angle, t_point dimensions)
{
	int		i;
	int		length;

	i = 0;
	length = (dimensions.x)*(dimensions.y) + 1;
	while (i < length)
	{
		ft_putnbr(coord[i].y);
		coord[i].y = (coord[i].y) * cos(angle*PI/180) - (coord[i].z) * sin(angle*PI/180);
		ft_putnbr(coord[i].y);
		ft_putnbr(coord[i].z);
		coord[i].z = (coord[i].y) * sin(angle*PI/180) + (coord[i].z) * cos(angle*PI/180);
		ft_putnbr(coord[i].z);
		i++;
	}
}

void	rotate_y(t_point *coord, double angle, t_point dimensions)
{
	int		i;
	int		length;

	i  = 0;
	length = (dimensions.x)*(dimensions.y) + 1;
	while (i < length)
	{
		ft_putnbr(coord[i].x);
		coord[i].x = (coord[i].x)*cos(angle*PI/180) + (coord[i].z) * sin(angle*PI/180);
		ft_putnbr(coord[i].x);
		ft_putnbr(coord[i].z);
		coord[i].z = (coord[i].x) * (-1) * sin(angle*PI/180) + (coord[i].z) * cos(angle*PI/180);
		ft_putnbr(coord[i].z);
		i++;
	}
}

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
	void	*mlx_ptr;
	void	*window_ptr;
	t_point *coord;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "New_Window");
//	mlx_loop(mlx_ptr);
//
	coord = (t_point*)malloc(sizeof(t_point));

	coord[0].x = 100;
	coord[0].y = 200;
	coord[0].z = 200;

	coord[1].x = 400;
	coord[1].y = 100;
	coord[1].z = 100;

	//int	i;

	//i = 0;

	//while (i < 2)
    //{
        //convert_coordinate(&array[i]);
	t_point	dimensions;

	dimensions.x = 1;
	dimensions.y = 1;

	//mlx_pixel_put(mlx_ptr, window_ptr, coord[0].x, coord[0].y, 0xFFFFFF);
	//ft_putnbr(sin(90));
	double	angle;
	double	angle2;

	angle = 15.0;
	angle2 = 15.0;
	rotate_z(coord, angle, dimensions);
    mlx_pixel_put(mlx_ptr, window_ptr, coord[0].x, coord[0].y, 0xFFFFFF);
	//isometric_rotate( coord, angle, angle2, dimensions);
	//mlx_pixel_put(mlx_ptr, window_ptr, coord[1].x, coord[1].y, 0xFFFFFF);
      //  i++;
   // }

	mlx_loop(mlx_ptr);
	return (0);
}
