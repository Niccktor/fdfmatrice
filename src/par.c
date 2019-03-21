/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/0mlx_all->cam->di_z6:54:57 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/21 19:10:58 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


/*
 *		x = (x - y) * di_x + left_right;
 *		y = y * di_y + up_down - di_z * z;
 */


static void	ft_para_right(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	mlx_all->win->x_ligne = (mlx_all->map->map[i][j]->x
			- mlx_all->map->map[i][j]->y)
		* mlx_all->cam->di_x + mlx_all->cam->left_right;
	mlx_all->win->y_ligne = mlx_all->map->map[i][j]->y * mlx_all->cam->di_y
		- mlx_all->map->map[i][j]->z * mlx_all->cam->di_z;
	if (j + 1 < mlx_all->map->len)
	{
		j++;
		x = (mlx_all->map->map[i][j]->x
				- mlx_all->map->map[i][j]->y)
			* mlx_all->cam->di_x + mlx_all->cam->left_right;
		y = mlx_all->map->map[i][j]->y * mlx_all->cam->di_y
			- mlx_all->map->map[i][j]->z * mlx_all->cam->di_z;
		ft_draw_ligne(mlx_all, x, y, mlx_all->map->map[i][j - 1]->color);
	}
}

static void ft_para_down(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	i++;
	x = (mlx_all->map->map[i][j]->x
			- mlx_all->map->map[i][j]->y)
		* mlx_all->cam->di_x + mlx_all->cam->left_right;
	y = mlx_all->map->map[i][j]->y * mlx_all->cam->di_y
		- mlx_all->map->map[i][j]->z * mlx_all->cam->di_z;
	ft_draw_ligne(mlx_all, x, y, mlx_all->map->map[i - 1][j]->color);
}

void		ft_parallel(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			ft_para_right(mlx_all, i, j);
			if (i < mlx_all->map->height - 1)
				ft_para_down(mlx_all, i, j);
			j++;
		}
		i++;
	}
	mlx_all->cam->di_x /= 2;
}

void		ft_set_para(t_mlx *mlx_all, char para)
{
	if (mlx_all->cam->proj != 'p' || para == 'r')
	{
		mlx_all->cam->proj = 'p';
		mlx_all->cam->di_x = mlx_all->win->width
			/ (mlx_all->map->len + mlx_all->map->height) / 2;
		mlx_all->cam->di_y = mlx_all->win->width
			/ (mlx_all->map->len + mlx_all->map->height) / 2;
		mlx_all->cam->di_z = mlx_all->win->width
			/ (mlx_all->map->len + mlx_all->map->height) / 2;
		mlx_all->cam->left_right = (mlx_all->win->width + mlx_all->win->height)
			/ 3;
		mlx_all->cam->up_down = mlx_all->win->height
			/ (mlx_all->map->len + mlx_all->map->height);
		mlx_all->cam->angle = 0;
	}
}
