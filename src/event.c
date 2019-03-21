/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/21 22:49:18 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define BLUE 0x0A5FE8
#define WHITE 0xFFFFFF

static void		ft_render(t_mlx *mlx_all)
{
	if (mlx_all->cam->proj == 'i')
		ft_iso(mlx_all);
	else if (mlx_all->cam->proj == 'p')
		ft_parallel(mlx_all);
}

int 		ft_key_hook(int key, void *para)
{
	t_mlx *mlx_all;

	mlx_all = (t_mlx *)para;
	if (key == 53) /* key ==  'esc'*/
	{
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		exit(0);
		return (1);
	}
	else if (key == 15) /* Key == 'r' */
	{
		if (mlx_all->cam->proj == 'i')
			ft_set_iso(mlx_all, 'r');
		else
			ft_set_para(mlx_all, 'r');
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 12) /* key == 'q' */
	{
		mlx_all->cam->angle /= 1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 14) /* key == 'e' */
	{
		mlx_all->cam->angle *= 1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 78) /* key == '-' pav num */
	{
		mlx_all->cam->di_x /= 1.2;
		mlx_all->cam->di_y /= 1.2;
		mlx_all->cam->di_z /= 1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 69) /* key == '+' pav num */
	{
		mlx_all->cam->di_x *= 1.2;
		mlx_all->cam->di_y *= 1.2;
		mlx_all->cam->di_z *= 1.2;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 34) /* key == 'i' */
	{
		ft_set_iso(mlx_all, 'i');
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 126) /* key == 'arrow up' */
	{
		mlx_all->cam->up_down -= 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 125) /* key == 'arrow down' */
	{
		mlx_all->cam->up_down += 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 123) /* key == 'arrow left' */
	{
		mlx_all->cam->left_right -= 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 124) /* key == 'arrow right' */
	{
		mlx_all->cam->left_right += 10;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 116) /* key == 'page up' */
	{
		mlx_all->cam->di_z += 1;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 121) /* key == 'page down' */
	{
		mlx_all->cam->di_z -= 1;
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 86) /* key == '4' pav num */
	{
		ft_x_rotation(mlx_all, 0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 88) /* key == '6' pav num */
	{
		ft_x_rotation(mlx_all, -0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 91) /* key == '8' pav num */
	{
		ft_y_rotation(mlx_all, 0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 84) /* key == '2' pav num */
	{
		ft_y_rotation(mlx_all, -0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 89) /* key == '7' pav num */
	{
		ft_z_rotation(mlx_all, 0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 85) /* key == '3' pav num */
	{
		ft_z_rotation(mlx_all, -0.1);
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
	}
	else if (key == 35) /* key ==  'p'*/
	{
		if (mlx_all->cam->proj != 'p')
			ft_set_para(mlx_all, 'p');
		mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
		ft_render(mlx_all);
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
