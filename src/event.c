/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/01 17:11:28 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define BLUE 0x0A5FE8
#define WHITE 0xFFFFFF

int 	ft_key_hook(int key, void *para)
{
	t_mlx *mlx_all;

	mlx_all = (t_mlx *)para;
	if (key == 53)
	{
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		exit(0);
		return (1);
	}
	else if (key == 15)
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
	else if (key == 12)
	{
		mlx_all->cam->angle /=1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 14)
	{
		mlx_all->cam->angle *=1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 78)
	{
		mlx_all->cam->di_x /=1.2;
		mlx_all->cam->di_y /=1.2;
		mlx_all->cam->di_z /=1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 69)
	{
		mlx_all->cam->di_x *=1.2;
		mlx_all->cam->di_y *=1.2;
		mlx_all->cam->di_z *=1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 34)
	{
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 32)
	{
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 126)
	{
		mlx_all->cam->up_down -= 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 125)
	{
		mlx_all->cam->up_down += 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 123)
	{
		mlx_all->cam->left_right -= 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 124)
	{
		mlx_all->cam->left_right += 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 116)
	{
		mlx_all->cam->di_z += 1;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 121)
	{
		mlx_all->cam->di_z -= 1;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);
	}
	else if (key == 86)
	{
		ft_x_rotation(mlx_all);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_iso(mlx_all);

	}
	else if (key == 3)
	{
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_parallel(mlx_all);
	}
	ft_putstr("----------------------key----------------------\n");
	ft_putnbr(key);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, void *para)
{
	t_mlx		*mlx_all;

	mlx_all = (t_mlx *)para;
	ft_putstr("----------------------mouse--------------------\n");
	ft_putnbr(button);
	ft_putstr("\n");
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	if (button == 1)
	{
		if (mlx_all->win->ligne == 1)
			ft_draw_ligne(mlx_all, x, y, BLUE);
		else
			mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, x, y, WHITE);
	}
	if (button == 2)
	{
		if (mlx_all->win->ligne == 1)
			mlx_all->win->ligne = 0;
		else
		{
			mlx_all->win->ligne = 1;
			mlx_all->win->x_ligne = x;
			mlx_all->win->y_ligne = y;
		}
	}
	return (0);
}
