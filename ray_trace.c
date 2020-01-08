/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:50:13 by hyu               #+#    #+#             */
/*   Updated: 2020/01/07 10:17:22 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"

void    pixel_ray_trace(t_fpoint *start, t_fpoint *stop, void *mlx_ptr, void *win_ptr)
{
	int slope;
    int y_0;
	int y_f;
    int x_0;
	int	x_f;

	int	i;

	i = 0;
    y_0 = (start->y);
	x_0 = start->x;
	x_f = stop->x;
	y_f = stop->y;
	int	y;

	ft_putnbr(1);
	ft_putnbr(x_0);
	ft_putnbr(x_f);

	if ((x_0) == (x_f))
	{
		while ( (y_0 + i) < y_f)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
			i++;
		}
	}
		
	else
	{
		slope = (stop->y - start->y)/(stop->x - start->x);
		while ((x_0 + i) < x_f)
		{
			y = y_0 + slope * i;
			mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
			i++;
		}
	}
}

void	make_square(t_point window_size, t_point size)
{
	void    *mlx_ptr;
    void    *win_ptr;
	
	int y_0;
    int x_0;
    int x_f;
	int	y_f;

	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, window_size.x, window_size.y, "New Window");

	y_0 = 0;
    x_0 = 0;
    x_f = (window_size.x);
	y_f = 0;

	while (x_0 < x_f)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
        x_0++;
    }
	
	y_0 = 0;
    x_0 = window_size.x - 1;
    x_f = (window_size.x);
    y_f = window_size.y;

	while (y_0 < y_f)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
        y_0++;
    }

	y_0 = 0;
    x_0 = 0;
    x_f = 0;
    y_f = window_size.y;

	while (y_0 < y_f)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
        y_0++;
    }

	y_0 = window_size.y - 1;
    x_0 = 0;
    x_f = window_size.x;
    y_f = window_size.y - 1;

	while (x_0 < x_f)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
        x_0++;
    }

    /*y_0 = 0;
    x_0 = window_size.x - 1;
    x_f = (window_size.x);
    y_f = window_size.y;*/

	mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 0xFFFFFF);
	
	mlx_loop(mlx_ptr);
}
/*
int		main(void)
{
	t_fpoint *ptra;
    t_fpoint *ptrb;
    t_fpoint *ptrc;
    t_fpoint *ptrd;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
    int n7;
    int n8;
    int n9;
    int n10;
    int n11;
    int n12;

    ptra = malloc(sizeof(t_fpoint));
    ptrb = malloc(sizeof(t_fpoint));
    ptrc = malloc(sizeof(t_fpoint));
    ptrd = malloc(sizeof(t_fpoint));

	n1 = 50;
    n2 = 50;
    n3 = 50;
    n4 = 450;
    n5 = 50;
    n6 = 50;
    n7 = 50;
    n8 = 450;
    n9 = 50;
    n10 = 450;
    n11 = 450;
    n12 = 50;

    ptra->x = &n1;

    ptra->y = &n2;
    ptra->z = &n3;
    ptrb->x = &n4;
    ptrb->y = &n5;
    ptrb->z = &n6;
    ptrc->x = &n7;
    ptrc->y = &n8;
    ptrc->z = &n9;
    ptrd->x = &n10;
    ptrd->y = &n11;
    ptrd->z = &n12;

    ptra->next = ptrb;
    ptrb->next = ptrc;
    ptrc->next = ptrd;
    ptrd->next = NULL;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point window_size;
	t_fpoint *start;
	t_fpoint *stop;
	t_point size;

	int		x0;
	int		xf;
	int		y0;
	int		yf;

	x0 = 200;
	y0 = 200;
	xf = 300;
	yf = 300;

	start = malloc(sizeof(t_fpoint));
	stop = malloc(sizeof(t_fpoint));

	window_size.x = 500;
	window_size.y = 500;

	start->x = &x0;
	start->y = &y0;

	stop->x = &xf;
	stop->y = &yf;

	size.x = 500;
	size.y = 500;
	
	pixel_ray_trace(start, stop, size, window_size);
	//make_square(window_size, size);
	return (0);
}*/
