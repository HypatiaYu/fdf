/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:59:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/07 19:09:41 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_list_frch(t_fpoint *begin, void (*f)(t_fpoint *begin, int scaler), int scaler)
{
	t_fpoint *tmp;

	tmp = begin;
	if (begin == 0)
		return;
	while (tmp != 0)
	{
		f(tmp, scaler);
		tmp = tmp->next;
	}
}

t_scaler		*ft_scaling(t_point dimensions, t_point window_size)
{
	t_scaler *scaler;

	scaler = malloc(sizeof(t_scaler));
	scaler->x_dim = dimensions.x;
	scaler->y_dim = dimensions.y;
	scaler->win_x = window_size.x;
	scaler->win_y = window_size.y;
	scaler->x_center = window_size.x/2;
	scaler->y_center = window_size.y/2;
	return (scaler);
}

void    ft_list_frch_center(t_fpoint *begin, void (*f)(t_fpoint *begin, t_scaler *scaler), t_scaler *scaler)
{
	if (begin == 0)
        return;
    while (begin != 0)
    {
        f(begin, scaler);
		begin = begin->next;
    }
}

void        center(t_fpoint *list, t_scaler *scaler)
{
	int		center;
	int		offset;
	t_fpoint	*begin;

	begin = (t_fpoint*)malloc(sizeof(t_fpoint));

	if (begin)
	{
		center = scaler->x_center;
		offset = scaler->x_dim;
		list->x = list->x + center - offset/2;
		list->y = list->y + scaler->y_center - (scaler->y_dim)/2;
	}
}

void	translation(t_fpoint *list, int x, int y)
{
	list->x = list->x + x;
	list->y = list->y + y;
}

void    ft_list_frch_trans(t_fpoint *begin, void (*f)(t_fpoint *begin, int x, int y), int x, int y)
{
    if (begin == 0)
        return;
    while (begin != 0)
    {
        f(begin, x, y);
        begin = begin->next;
    }
}

void	scaler_iterator(t_fpoint *head, t_scaler *scaler)
{
	t_fpoint *tmp;

	tmp = head;
	center(head, scaler);
	head = head->next;
	ft_putchar('a');
	if (head)
	{
		ft_putchar('a');
		scaler_iterator(head, scaler);
	}
	return;
}

void	x_scale(t_fpoint *begin, int scaler)
{
	begin->x = scaler * (begin->x);
	begin->y = scaler * (begin->y);
	begin->z = scaler * (begin->z);
}

void	aspect_ratio(t_fpoint *begin, int scaler, int ar)
{
	begin->x = scaler * (begin->x) * ar;
	begin->y = scaler * (begin->y);
}

void	x_y_minmax(t_scaler *scaler, t_fpoint *begin)
{
	t_fpoint *tmp;
	int	xmin;
	int	ymin;
	int	xmax;
	int	ymax;


	scaler->x_min = begin->x;
	xmax = begin->x;
	tmp = begin;
	while (tmp)
	{
		if (scaler->x_min > begin->x)
		{
			ft_putchar('a');
			ft_putnbr(xmin);
			scaler->x_min = begin->x;
		}
		if (scaler->x_max < begin->x)
		{
			ft_putchar('b');
			scaler->x_max = begin->x;
		}
		tmp = tmp->next;
	}
	tmp = begin;
	ymin = begin->y;
	while (tmp)
	{
		if (ymin > begin->y)
			ymin = begin->y;
		tmp = tmp->next;
	}
	scaler->y_min = ymin;
	return;
}

/*int		main(void)
{
	t_point dimensions;
	t_point	window_size;
	t_fpoint list;

	void	*mlx_ptr;
	void	*win_ptr;
	t_scaler *scale;

	//dimensions = (t_point)malloc(sizeof(t_point));
	dimensions.x = 3;
	dimensions.y = 3;
	window_size.x = 500;
	window_size.y = 500;
	scale = ft_scaling(dimensions, window_size);
	ft_putnbr(scale->x_dim);
	ft_putnbr(scale->y_dim);
	ft_putnbr(scale->win_x);
	ft_putnbr(scale->win_y);
	ft_putnbr(scale->x_center);
	ft_putnbr(scale->y_center);

	t_fpoint *ptra;
	t_fpoint *ptrb;
	t_fpoint *ptrc;
	t_fpoint *ptrd;
	int		n1;
	int		n2;
	int		n3;
	int n4;
    int n5;
    int n6;
	int n7;
	int n8;
	int n9;
	int n10;
	int n11;
	int n12;
	ptra = (t_fpoint*)malloc(sizeof(t_fpoint));
	ptrb = malloc(sizeof(t_fpoint));
	ptrc = malloc(sizeof(t_fpoint));
	ptrd = malloc(sizeof(t_fpoint));
	n1 = 0;
    n2 = 0;
    n3 = 50;
	n4 = 0;
    n5 = 1;
    n6 = 100;
	n7 = 0;
	n8 = 2;
	n9 = 2;
	n10 = 0;
	n11 = 3;
	n12 = 50;
	ptra->x = n1;
    ptra->y = n2;
    ptra->z = n3;
	ptrb->x = n4;
    ptrb->y = n5;
    ptrb->z = n6;
	ptrc->x = n7;
	ptrc->y = n8;
	ptrc->z = n9;
	ptrd->x = n10;
	ptrd->y = n11;
	ptrd->z = n12;

	ptra->next = ptrb;
	ptrb->next = ptrc;
	ptrc->next = ptrd;
	ptrd->next = NULL;

	//ptra->next = NULL;

	//scaler_iterator(ptra, scale);
	//x_scale(t_fpoint *begin, int scaler)
	int scaler;

	scaler = 100; 
    ft_list_frch(ptra, x_scale, scaler);
	ft_putnbr(ptrd->y);
	//int scaler;

	//scaler = 10;
	x_scale(ptrb, scaler);
	ft_putnbr(ptrb->x);
	ft_putnbr(ptrb->y);
	int x = 100;
	int y = 200;
	ft_list_frch_trans(ptra, translation, x, y);
	//ft_list_frch_center(ptra, center, scale);
	int	a_r;
	a_r = 1;
	ft_list_frch_trans(ptra, aspect_ratio, scaler, a_r);
	ft_putchar('\n');
	ft_putnbr(ptra->x);
	ft_putnbr(ptra->y);
	//center(t_fpoint *list, t_scaler *scaler);

	//x_y_minmax(scale, ptra);
	//ft_putchar('d');

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, scale->win_x, scale->win_y, "New Window");
	mlx_pixel_put(mlx_ptr, win_ptr, scale->x_center, scale->y_center, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	return (0);
}*/
