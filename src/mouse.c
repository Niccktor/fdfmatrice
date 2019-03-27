/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 18:43:35 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define BLUE 0x0A5FE8
#define WHITE 0xFFFFFF

int		ft_mouse_hook(int button, int x, int y, void *para)
{
	t_mlx		*mlx_all;

	mlx_all = (t_mlx *)para;
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
