/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:02:43 by hyu               #+#    #+#             */
/*   Updated: 2019/12/21 21:14:53 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;
*/

typedef	struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		u;
	int		v;
}				t_point;

typedef	struct	s_lpoint
{
	int			x0[4];
	int			x1[4];
	int			x2[4];
	int			x3[4];
}				t_lpoint;
