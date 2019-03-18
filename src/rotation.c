/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:18:24 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/18 14:34:52 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>
/*
void	ft_x_rotation(t_mlx *mlx_all)
{
	int	**new_map;
	int i;
	int j;
	int new_i;
	int new_j;

	ft_putstr("test\n");
	new_map =  (int **)ft_memalloc(sizeof(int *) * 100);
	ft_putstr("test\n");
	i = 0;
	while (100 > i)
	{
		new_map[i] = (int *)ft_memalloc(sizeof(int) * 101);
		j = 0;
		while (100 > j)
		{
			new_map[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_putstr("test\n");
	i = 0;
	while (mlx_all->map->height > i)
	{
		j = 0;
		while (mlx_all->map->len > j)
		{
			new_i = ft_abs(i * cos(1.5708) - j * sin(1.5708));
			new_j = ft_abs(i * sin(1.5708) + j * cos(1.5708));
			ft_putstr("\n----------------\ni = ");
			ft_putnbr(i);
			ft_putstr(" new_i = ");
			ft_putnbr(new_i);
			ft_putstr("\nj = ");
			ft_putnbr(j);
			ft_putstr(" new_j = ");
			ft_putnbr(new_j);
			ft_putstr("\n---------------");
			new_map[new_i][new_j] = mlx_all->map->map[i][j];
			j++;
		}
		i++;
	}
	ft_memdel((void**)&(mlx_all->map->map));
	mlx_all->map->map = new_map;
	ft_print_tab(mlx_all);
	//mlx_all->map->len = mlx_all->map->len;
}*/
