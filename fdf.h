/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:50:41 by hyu               #+#    #+#             */
/*   Updated: 2020/01/26 10:35:58 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

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
	int			win_x;
	int			win_y;
	int			x_center;
	int			y_center;
	double		aspect_ratio;
	double		scale;
	double		scalex;
	double		scaley;
	double		scalez;
	int			x_trans;
	int			y_trans;
	int			z_trans;
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			min_z;
	int			d;
	double		angle;
	double		angle2;
	t_fpoint	*begin;
	t_fpoint	*head;
	void		*mlx;
	void		*win;
	int			z_avg;
}				t_point;

int     get_next_line(const int fd, char **line);
int				ft_word_check(char *str, t_fpoint *iterate, t_point *dimensions);
int				ft_numword(char *str, t_point *dimensions);

void			ft_space(char *str, t_fpoint *iterate);
void			ft_word(char *str, t_fpoint *iterate);
void        ft_ishex(char *str, t_fpoint *begin);
t_fpoint         *ft_move_node(t_fpoint *iterate, t_point *size, char **str, t_fpoint *new);
void        iterate_zero(t_fpoint *iterate);
void        y_listadd(t_fpoint *begin, t_point *size);
void            y_list_iterator(t_fpoint *begin, t_point *size);

char	*ft_error(char *file_name);
char            **ft_split(char *str, t_point *dimensions);

t_fpoint        *ft_listadd_2(t_point *size, char **str, t_fpoint *iterate);
t_fpoint        *create_fpoint_node(int x, int y, int z);
t_fpoint        *ft_set_dimensions(char *tile, t_point *dimensions);
t_fpoint        *x_move(t_fpoint *start, t_point *size);

# define BUFF_SIZE 32
# define MAX_FD 1024 + 1

#endif
