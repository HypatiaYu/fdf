/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:02:43 by hyu               #+#    #+#             */
/*   Updated: 2020/01/18 16:54:59 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# define PI 3.14159265

typedef struct		s_fpoint
{
	int				x;
	int				y;
	int				z;
	int				hex;
	struct s_fpoint	*next;
	struct s_fpoint	*nexty;
	struct s_fpoint	*nextx;
}					t_fpoint;

typedef	struct	s_point
{
	int			x;
	int			y;
	int			valid;
	int			word;
}				t_point;

typedef	struct	s_1point
{
	void		*mlx;
	void		*win;
}				w_point;

typedef struct	x_point
{
	t_point		*size;
	int			x_dim;
	int			y_dim;
	int			win_x;
	int			win_y;
	int			x_center;
	int			y_center;
	double		aspect_ratio;
	int			scale;
	int			x_trans;
	int			y_trans;
	int			z_trans;
	int			d;
	double		angle;
	double		angle2;
	t_fpoint	*begin;
	t_fpoint	*head;
	void		*mlx;
	void		*win;
}				t_scaler;

void			ft_list_foreach(t_fpoint *begin, void (*f)(int *));
void			ft_listadd(t_fpoint *begin, t_point size, t_point current,
				int **map);
void			y_listadd(t_fpoint *begin, t_point size);
void			y_list_iterator(t_fpoint *begin, t_point size);
t_point			dimensions(char *tile, t_point dimensions);
int				atoi_iterator(char *tile, int *i);
void			skipletter(char *tile, int *i);
void			ft_space(char *str, t_fpoint *iterate);
void			ft_word(char *str, t_fpoint *iterate);
int				ft_word_check(char *str, t_fpoint *iterate,
				t_point *dimensions);
void			pixel_ray_trace(t_fpoint *start, t_fpoint *stop,
				t_scaler *pointer);
void			ray_iterator(t_fpoint *begin, t_point size, t_scaler *pointer);
t_scaler		*ft_scaling(t_point dimensions, t_point window_size,
				int scaling, int ar);
void			x_scale(t_fpoint *begin, t_scaler *scaler);
void			translation_x(t_fpoint *list, t_scaler *scale);
void			translation_y(t_fpoint *list, t_scaler *scaler);
void			translation_z(t_fpoint *list, t_scaler *scaler);
void			center(t_fpoint *list, t_scaler *scaler);
void			aspect_ratio(t_fpoint *begin, t_scaler *scaler);

void			ft_list_frch_scale(t_fpoint *begin, void (*f)(t_fpoint *begin,
				t_scaler *scaler), t_scaler *scaler);
void			un_center(t_fpoint *begin, t_scaler *scaler);
void			make_smaller(t_fpoint *begin, t_scaler *scaler);
void			rotate_z(t_fpoint *begin, t_scaler *scaler);
void			rotate_x(t_fpoint *begin, t_scaler *scaler);
void			rotate_y(t_fpoint *begin, t_scaler *scaler);

void			make_bigger(t_fpoint *begin, t_scaler *scaler);
void			make_wider(t_fpoint *begin, t_scaler *scaler);
void			make_skinnier(t_fpoint *begin, t_scaler *scaler);
void			make_taller(t_fpoint *begin, t_scaler *scaler);
void			make_shorter(t_fpoint *begin, t_scaler *scaler);

void			isometric_rotate(t_fpoint *begin, t_scaler *scaler);
void			perspective_projection(t_fpoint *begin, t_scaler *scaler);

int				deal_key(int key, t_scaler *pointer);

#endif
