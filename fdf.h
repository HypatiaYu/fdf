/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:02:43 by hyu               #+#    #+#             */
/*   Updated: 2020/01/07 19:03:55 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_fpoint
{
	int		x;
	int		y;
	int		z;
	struct s_fpoint *next;
	struct s_fpoint *nexty;
	struct s_fpoint *nextx;
}				t_fpoint;

typedef	struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct x_point
{
	int			x_dim;
	int			y_dim;
	int			win_x;
	int			win_y;
	int			x_min;
	int			y_min;
	int			x_max;
	int			y_max;
	int			x_scale;
	int			y_scale;
	int			x_center;
	int			y_center;
}				t_scaler;

#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

void    ft_list_foreach(t_fpoint *begin, void (*f)(int *));
void    ft_listadd(t_fpoint *begin, t_point size, t_point current, int **map);
void	y_listadd(t_fpoint *begin, t_point size);
void	y_list_iterator(t_fpoint *begin, t_point size);

int     x_dimensions(char *tile);
int     y_dimensions(char *tile);
int     atoi_iterator(char *tile, int *i);
void        skipletter(char *tile, int *i);
int     **makemap(t_point size, char *tile);

void	pixel_ray_trace(t_fpoint *start, t_fpoint *stop, void *mlx_ptr, void *win_ptr);//t_point size, it_point window_size);
void	ray_iterator(t_fpoint *begin, t_point size);

void	ft_list_frch(t_fpoint *begin, void (*f)(t_fpoint *begin, int scaler), int scaler);
t_scaler		*ft_scaling(t_point dimensions, t_point window_size);
void	x_scale(t_fpoint *begin, int scaler);
void    ft_list_frch_center(t_fpoint *begin, void (*f)(t_fpoint *begin, t_scaler *scaler), t_scaler *scaler);
