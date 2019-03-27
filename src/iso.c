/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:54:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 19:22:10 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

/*
** 	y
**	|
**	|
**	|
**	|
**	---------------------x
**	i = y;
**	j = x;
**
**	*x = (previous_x - previous_y) * cos(mlx_all->cam->angle);
**	*y = -z + (previous_x + previous_y) * sin(mlx_all->cam->angle);
*/

static void		ft_iso_right(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	mlx_all->win->x_ligne = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* cos(mlx_all->cam->angle) + mlx_all->cam->left_right;
	mlx_all->win->y_ligne = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
		+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* sin(mlx_all->cam->angle) + mlx_all->cam->up_down;
	if (j + 1 < mlx_all->map->len)
	{
		j++;
		x = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
			- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
			* cos(mlx_all->cam->angle) + mlx_all->cam->left_right;
		y = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
			+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
			+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
			* sin(mlx_all->cam->angle) + mlx_all->cam->up_down;
		ft_draw_ligne(mlx_all, x, y, mlx_all->map->map[i][j - 1]->color);
	}
}

static void		ft_iso_down(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	i++;
	x = (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		- mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* cos(mlx_all->cam->angle) + mlx_all->cam->left_right;
	y = -(mlx_all->map->map[i][j]->z * mlx_all->cam->di_z)
		+ (mlx_all->map->map[i][j]->x * mlx_all->cam->di_x
		+ mlx_all->map->map[i][j]->y * mlx_all->cam->di_y)
		* sin(mlx_all->cam->angle) + mlx_all->cam->up_down;
	ft_draw_ligne(mlx_all, x, y, mlx_all->map->map[i - 1][j]->color);
}

void			ft_iso(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
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

void			ft_set_iso(t_mlx *mlx_all, char para)
{
	if (mlx_all->cam->proj != 'i' || para == 'r')
	{
		mlx_all->cam->proj = 'i';
		mlx_all->cam->di_x = (mlx_all->win->height / mlx_all->map->height) / 2;
		mlx_all->cam->di_y = (mlx_all->win->width / mlx_all->map->len) / 2;
		mlx_all->cam->di_z = (mlx_all->win->width / mlx_all->map->len) / 5;
		mlx_all->cam->up_down = (mlx_all->map->height * mlx_all->cam->di_y
				+ mlx_all->map->len * mlx_all->cam->di_x) / 4;
		mlx_all->cam->left_right = ((mlx_all->map->height / 2
				- mlx_all->map->len / 2)
				* mlx_all->cam->di_y) + mlx_all->win->width / 2;
		mlx_all->cam->angle = 0.523599;
	}
}
