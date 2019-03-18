/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:45:12 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/01 16:31:26 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

t_bres		*ft_new_bres(int x1, int y1, int x2, int y2)
{
	t_bres	*new;

	new = (t_bres *)ft_memalloc(sizeof(t_bres));
	new->x1 = x1;
	new->y1 = y1;
	new->x2 = x2;
	new->y2 = y2;
	new->dx = x1 - x2;
	new->dy = y1 - y2;
	new->x_inc = (new->dx < 0) ? 1 : -1;
	new->y_inc = (new->dy < 0) ? 1 : -1;
	new->i = 1;
	new->dx = fabs(new->dx);
	new->dy = fabs(new->dy);
	new->error = (new->dx >= new->dy) ? new->dx / 2 : new->dy / 2;
	return (new);
}

void		ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color)
{
	t_bres *bres;

	bres = ft_new_bres(mlx_all->win->x_ligne, mlx_all->win->y_ligne, x, y);
	while ((bres->i <= bres->dx && bres->dx >= bres->dy)
			|| (bres->i <= bres->dy && bres->dx <= bres->dy))
	{
		bres->i++;
		bres->error += (bres->dx >= bres->dy) ? bres->dy : bres->dx;
		if (bres->dx >= bres->dy)
			bres->x1 += bres->x_inc;
		else
			bres->y1 += bres->y_inc;
		if ((bres->error >= bres->dx && bres->dx >= bres->dy)
				|| (bres->error >= bres->dy && bres->dx <= bres->dy))
		{
			bres->error -= (bres->dx >= bres->dy) ? bres->dx : bres->dy;
			if (bres->dx >= bres->dy)
				bres->y1 += bres->y_inc;
			else
				bres->x1 += bres->x_inc;
		}
		mlx_pixel_put(mlx_all->mlx_ptr,
				mlx_all->win->win_ptr, bres->x1, bres->y1, color);
	}
	ft_memdel((void **)&bres);
}
