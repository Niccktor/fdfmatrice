/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 18:55:31 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define BLUE 0x0A5FE8
#define WHITE 0xFFFFFF

static void	ft_proj_event(int key, t_mlx *mlx_all)
{
	if (key == 34)
		ft_set_iso(mlx_all, 'i');
	else if (key == 15)
	{
		if (mlx_all->cam->proj == 'i')
			ft_set_iso(mlx_all, 'r');
		else
			ft_set_para(mlx_all, 'r');
		ft_render(mlx_all);
	}
	else if (key == 35)
	{
		if (mlx_all->cam->proj != 'p')
			ft_set_para(mlx_all, 'p');
		ft_render(mlx_all);
	}
	ft_render(mlx_all);
}

static void	ft_mouv_event(int key, t_mlx *mlx_all)
{
	if (key == 78)
	{
		mlx_all->cam->di_x /= 1.2;
		mlx_all->cam->di_y /= 1.2;
		mlx_all->cam->di_z /= 1.2;
	}
	else if (key == 69)
	{
		mlx_all->cam->di_x *= 1.2;
		mlx_all->cam->di_y *= 1.2;
		mlx_all->cam->di_z *= 1.2;
	}
	else if (key == 126)
		mlx_all->cam->up_down -= 10;
	else if (key == 125)
		mlx_all->cam->up_down += 10;
	else if (key == 123)
		mlx_all->cam->left_right -= 10;
	else if (key == 124)
		mlx_all->cam->left_right += 10;
	else if (key == 116)
		mlx_all->cam->di_z += 1;
	else if (key == 121)
		mlx_all->cam->di_z -= 1;
	ft_render(mlx_all);
}

static void	ft_rot_event(int key, t_mlx *mlx_all)
{
	if (key == 12)
		mlx_all->cam->angle /= 1.2;
	else if (key == 86)
		ft_x_rotation(mlx_all, 0.1);
	else if (key == 88)
		ft_x_rotation(mlx_all, -0.1);
	else if (key == 91)
		ft_y_rotation(mlx_all, 0.1);
	else if (key == 84)
		ft_y_rotation(mlx_all, -0.1);
	else if (key == 89)
		ft_z_rotation(mlx_all, 0.1);
	else if (key == 85)
		ft_z_rotation(mlx_all, -0.1);
	else if (key == 12)
		mlx_all->cam->angle /= 1.2;
	else if (key == 14)
		mlx_all->cam->angle *= 1.2;
	ft_render(mlx_all);
}

static void	ft_color_event(int key, t_mlx *mlx_all)
{
	if (key == 43 && mlx_all->cam->opacity < 0xf0000000)
		mlx_all->cam->opacity += 0x10000000;
	else if (key == 47 && mlx_all->cam->opacity > 0)
		mlx_all->cam->opacity -= 0x10000000;
	ft_render(mlx_all);
}

int			ft_key_hook(int key, void *para)
{
	t_mlx *mlx_all;

	mlx_all = (t_mlx *)para;
	if (key == 53)
	{
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		exit(0);
		return (0);
	}
	else if (key == 15 || key == 34 || key == 35)
		ft_proj_event(key, mlx_all);
	else if (key == 78 || key == 69 || key == 116 || key == 121
			|| key == 123 || key == 124 || key == 125 || key == 126)
		ft_mouv_event(key, mlx_all);
	else if (key == 43 || key == 47)
		ft_color_event(key, mlx_all);
	else if (key == 12 || key == 14 || key == 84 || key == 85
			|| key == 86 || key == 88 || key == 89 || key == 91)
		ft_rot_event(key, mlx_all);
	return (0);
}
