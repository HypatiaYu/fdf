/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:29:50 by hyu               #+#    #+#             */
/*   Updated: 2020/01/07 18:57:30 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_list_foreach(t_fpoint *begin, void (*f)(int *))
{
	if (begin == 0)
		return;
	while (begin != 0)
	{
		f(&begin->x);
		f(&begin->y);
		f(&begin->z);
		begin = begin->next;
	}
}

t_fpoint	*create_fpoint_node(int x, int y, int z)
{
	t_fpoint *new;

	new = malloc(sizeof(t_fpoint));
	new->x = x;
	new->y = y;
	new->z = z;
	new->nextx = NULL;
	new->nexty = NULL;
	return (new);
}

void	ft_listadd(t_fpoint *begin, t_point size, t_point current, int **map)
{
	t_fpoint *new;

	if (current.x >= size.x || current.y >= size.y)
	{
		begin->next = NULL;
		return;
	}
	new = create_fpoint_node(current.x, current.y, map[current.y][current.x]);
	begin->next = new;
	begin = begin->next;
	if (current.x + 1 < size.x)
	{
		current.x = current.x + 1;
		ft_listadd(begin, size, current, map);
	}
	else if (current.x + 1 == size.x)
	{
		current.x = 0;
		if (current.y + 1 < size.y)
		{
			current.y = current.y + 1;
			ft_listadd(begin, size, current, map);
		}
		else
			begin->next = NULL;
	}
}

void	x_move(t_fpoint *start, t_point size, int *i)
{
	while (*i < size.x && start)
	{
		ft_putnbr(*i);
		start->nextx = start->next;
		start = start->next;
		ft_putchar('a');
		*i = *i + 1;
	}
}

void	y_listadd(t_fpoint *begin, t_point size)
{
	t_fpoint	*start;
	t_fpoint	*tmp;

	start = begin;
	tmp = begin;
	//int *i;
	
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	
	while (j < size.y)
	{
		ft_putnbr(j);
		i = 0;
		//x_move(start, size, &i);
		
		while(i < size.x && start)
		{
			ft_putnbr(i);
			start->nextx = start->next;
			start = start->next;
			ft_putchar('a');
			i++;
		}
		if (j == size.y - 1)
			tmp->nexty = NULL;
		else
			tmp->nexty = start->next;
		if (i == size.x)
		{
			ft_putchar('c');
			tmp->nextx = NULL;
		}
		else
			tmp->nextx = tmp->next;
		tmp = start;
		j++;
	}
	ft_putchar('b');
}

void	y_list_iterator(t_fpoint *begin, t_point size)
{
	int	i;
	t_fpoint *start;
	
	start = begin;
	i = 0;

	y_listadd(start, size);
	i++;
	while(i <= size.x)
	{
		start = start->next;
		y_listadd(start, size);
		ft_putnbr(i);
		i++;
	}
}

void	ray_iterator(t_fpoint *begin, t_point size)
{
	t_fpoint *tmp;
	t_fpoint *stop;
	void    *mlx_ptr;
    void    *win_ptr;

	tmp = begin;
	t_point window_size;
    window_size.x = 500;
    window_size.y = 500;
	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, window_size.x, window_size.y, "New Window");
	while (tmp)
	{
		if (tmp->nextx != NULL)
		{
			ft_putchar('x');
			stop = tmp->nextx;
			pixel_ray_trace(tmp, stop, mlx_ptr, win_ptr);
		}
		if (tmp->nexty != NULL)
        {
			ft_putchar('y');
			stop = tmp->nexty;
            pixel_ray_trace(tmp, stop, mlx_ptr, win_ptr);
        }
		tmp = tmp->next;
	}
	mlx_loop(mlx_ptr);
}

/*
int			main(void)
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
    n4 = 100;
    n5 = 100;
    n6 = 100;
	n7 = 50;
	n8 = 100;
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
	//ptrd->nexty = NULL;
	//ptrc->nexty = NULL;

	int	i;
	t_point size;
	t_fpoint *begin;
	t_fpoint *begin2 = ptra;	

	begin = ptra;
	size.x = 1;
	size.y = 1;

	i = 0;
	while (ptra)
	{
		ft_putnbr(i);
		ptra = ptra->next;
		i++;
	}

	y_list_iterator(begin, size);
	
	i = 0;
	while(begin2)
    {
        ft_putnbr(i);
		ft_putchar('\n');
		ft_putchar('x');
		ft_putnbr(*begin2->x);
        begin2 = begin2->nexty;
        i++;
    }
	
	begin2 = ptra;
	//begin2 = begin2->next;
	
	ft_putchar('x');
	ft_putnbr(*begin2->x);
	y_listadd(begin2, size);
	
	i = 0;
	while(begin2)
	{
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putchar('x');
		ft_putnbr(*begin2->x);
		begin2 = begin2->nexty;
		i++;
	}
	
	//ft_putnbr(*begin2->x);
	//begin2->nexty = NULL;
	t_point window_size;
	window_size.x = 500;
    window_size.y = 500;
	//pixel_ray_trace(begin2, begin2->nextx, size, window_size);
	ray_iterator(begin2, size);
	ft_putchar('i');

	return (0);
}
*/
