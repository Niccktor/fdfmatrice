/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:18:24 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/20 17:49:19 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

/*	
 					rot x

	x = (x * 1)				+ (y * 0)			+ (z * 0);
	y = (x * 0)				+ (y * ft_cos()) 		+ (z * ft_sin());
	z = (x * 0)				+ (y * (ft_sin() * -1) + (z * ft_cos());

					rot y
	x = (x * ft_cos())			+ (y * 0)			+ (z * (ft_sin() * -1));
	y = (x * 0)				+ (y * 1)			+ (z * 0);
	z = (x * ft_sin())			+ (y * 0)			+ (z * ft_cos())

					rot z
	x = (x * ft_cos())			+ (y * ft_sin())		+ (z * 0);
	y = (x * (ft_sin() * -1))	+ (y * ft_cos())		+ (z * 0);
	z = (x * 0)				+ (y * 0)			+ (z * 1);


*/
void	ft_x_rotation(t_mlx *mlx_all, double theta)
{
	int		i;
	int		j;
	double	tmp_y;
	double	tmp_z;

	i = -1;
	while (mlx_all->map->height > ++i)
	{
		j = -1;
		while (mlx_all->map->len > ++j)
		{
			tmp_y = mlx_all->map->map[i][j]->y;
			tmp_z = mlx_all->map->map[i][j]->z;
			mlx_all->map->map[i][j]->y = tmp_y * ft_cos(theta)
				+ tmp_z * ft_sin(theta);
			mlx_all->map->map[i][j]->z = tmp_y * (ft_sin(theta) * -1)
				+ tmp_z * ft_cos(theta);
		}
	}
}

void	ft_y_rotation(t_mlx *mlx_all, double theta)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_z;

	i = -1;
	while (mlx_all->map->height > ++i)
	{
		j = -1;
		while (mlx_all->map->len > ++j)
		{
			tmp_x = mlx_all->map->map[i][j]->x;
			tmp_z = mlx_all->map->map[i][j]->z;
			mlx_all->map->map[i][j]->x = tmp_x * ft_cos(theta)
				+ tmp_z * (ft_sin(theta) * -1);
			mlx_all->map->map[i][j]->z = tmp_x * ft_sin(theta)
				+ tmp_z * ft_cos(theta);
		}
	}
}

void	ft_z_rotation(t_mlx *mlx_all, double theta)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = -1;
	while (mlx_all->map->height > ++i)
	{
		j = -1;
		while (mlx_all->map->len > ++j)
		{
			tmp_x = mlx_all->map->map[i][j]->x;
			tmp_y = mlx_all->map->map[i][j]->y;
			mlx_all->map->map[i][j]->x = tmp_x * ft_cos(theta)
				+ tmp_y * ft_sin(theta);
			mlx_all->map->map[i][j]->y = tmp_x * (ft_sin(theta) * -1)
				+ tmp_y * ft_cos(theta);
		}
	}
}
