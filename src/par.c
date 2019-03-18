/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:54:57 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/01 17:42:11 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_para(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	mlx_all->win->x_ligne =
		(i - j) * mlx_all->cam->di_x + mlx_all->cam->left_right
		+ (mlx_all->win->width / 2 - mlx_all->map->len / 2);
	mlx_all->win->y_ligne = 
		j * mlx_all->cam->di_y
		+ (mlx_all->cam->up_down
		+ (mlx_all->win->height / 2 - mlx_all->map->height / 2 ))
		- mlx_all->cam->di_z * mlx_all->map->map[i][j];
	if (i + 1 < mlx_all->map->height)
	{
		x = ((i + 1) - j) * mlx_all->cam->di_x + mlx_all->cam->left_right
			+ (mlx_all->win->width / 2 - mlx_all->map->len / 2);
		y = j * mlx_all->cam->di_y +
			(mlx_all->cam->up_down
			+ (mlx_all->win->height / 2 - mlx_all->map->height / 2 ))
			- mlx_all->cam->di_z * mlx_all->map->map[i + 1][j]; 
		ft_draw_ligne(mlx_all, x, y, 0x00FF00);
	}
	if (j + 1 < mlx_all->map->len)
	{
		x = (i - (j + 1)) * mlx_all->cam->di_x + mlx_all->cam->left_right
			+ (mlx_all->win->width / 2 - mlx_all->map->len / 2);
		y = (j + 1) * mlx_all->cam->di_y
			+ (mlx_all->cam->up_down
			+ (mlx_all->win->height / 2 - mlx_all->map->height / 2 ))
			- mlx_all->cam->di_z * mlx_all->map->map[i][j + 1]; 
		ft_draw_ligne(mlx_all, x, y, 0x00FF00);
	}
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
			ft_para(mlx_all, i, j);
			j++;
		}
		i++;
	}
}
