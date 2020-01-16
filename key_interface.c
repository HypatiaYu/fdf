/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:59:50 by hyu               #+#    #+#             */
/*   Updated: 2020/01/16 11:33:43 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

//void *mlx_ptr;

int		deal_key(int key, t_scaler *pointer)//void *param, void *mlx_ptr, void *win_ptr, t_scaler *scaler)
{
	
	if (key == ESC)
	{
		exit(0);
		/*mlx_destroy_window(mlx_ptr, win_ptr);
		free(mlx_ptr);
		free(win_ptr);
		//free_n_exit(mlx_ptr);
		exit(0);
		return (0);*/
		//ft_putchar('a');
	}
	
	else if (key == KEY_1)
	{
		mlx_new_window(pointer->mlx, 500, 500, "Window 2");
	}

	
	else if (key == KEY_A)
	{
		mlx_clear_window(pointer->mlx, pointer->win);
	}
	else
		ft_putchar('b');
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_scaler	*pointer;


	t_point data;

	pointer = malloc(sizeof(t_scaler));

	

	mlx_ptr = mlx_init();
	pointer->mlx = mlx_ptr;
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "New Window");
	pointer->win = win_ptr;
	mlx_pixel_put(pointer->mlx, pointer->win, 250, 250, 0xFFFFFF);
	//mlx_clear_window(mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, pointer);
	//key_hook((void*)0, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
