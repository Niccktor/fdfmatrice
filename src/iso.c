/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:54:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/18 16:51:49 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>
/*
	y
	|
	|
	|
	|
	---------------------x
	i = y;
	j = x;

	*x = (previous_x - previous_y) * cos(mlx_all->cam->angle);
	*y = -z + (previous_x + previous_y) * sin(mlx_all->cam->angle);

*/
static void		ft_iso_right(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;
	int x_add;
	int y_add;

	x_add = (mlx_all->win->width / 2 - mlx_all->map->len / 2) + mlx_all->cam->left_right;
	y_add = (mlx_all->win->height / 2 - mlx_all->map->height / 2) + mlx_all->cam->up_down;
	mlx_all->win->x_ligne = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* cos(mlx_all->cam->angle) + x_add;
	mlx_all->win->y_ligne = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
		+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* sin(mlx_all->cam->angle) + y_add;
	if (j + 1 < mlx_all->map->len)
	{
		j++;
		x = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
			- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
			* cos(mlx_all->cam->angle) + x_add;
		y = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
			+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
			+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
			* sin(mlx_all->cam->angle) + y_add;
		ft_draw_ligne(mlx_all, x, y, 0xFF0000);
	}
}

static void		ft_iso_down(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;
	int x_add;
	int y_add;
	i++;
	x_add = (mlx_all->win->width / 2 - mlx_all->map->len / 2) + mlx_all->cam->left_right;
	y_add = (mlx_all->win->height / 2 - mlx_all->map->height / 2) + mlx_all->cam->up_down;
	x = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* cos(mlx_all->cam->angle) + x_add;
	y = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
		+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* sin(mlx_all->cam->angle) + y_add;
	ft_draw_ligne(mlx_all, x, y, 0xFF0000);
}

void			ft_iso(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
	ft_putstr("\ndi_x = ");
	ft_putnbr(mlx_all->cam->di_x);
	ft_putstr(" di_ y = ");
	ft_putnbr(mlx_all->cam->di_y);
	ft_putstr(" di_z = ");
	ft_putnbr(mlx_all->cam->di_z);
	ft_putstr("\n");
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			ft_iso_right(mlx_all, i, j);
			if (i < mlx_all->map->height - 1)
				ft_iso_down(mlx_all, i, j);
			j++;
		}
		i++;
	}
}
