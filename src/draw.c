/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:45:12 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 19:09:05 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

static void	ft_fill_pixel(t_mlx *mlx_all, int x, int y, unsigned int color)
{
	if (x >= 0 && x < mlx_all->win->width
			&& y >= 0 && y < mlx_all->win->height)
		mlx_all->win->img_str[y * mlx_all->win->width + x] =
			color + mlx_all->cam->opacity;
}

t_bres		*ft_new_bres(int x1, int y1, int x2, int y2)
{
	t_bres	*new;

	if ((new = (t_bres *)ft_memalloc(sizeof(t_bres))) == NULL)
		ft_close(NULL, "Error : Malloc bres\n");
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
		ft_fill_pixel(mlx_all, bres->x1, bres->y1, color);
	}
	ft_memdel((void **)&bres);
}

void		ft_render(t_mlx *mlx_all)
{
	ft_bzero((void *)mlx_all->win->img_str, mlx_all->win->width
			* mlx_all->win->height * 4);
	if (mlx_all->cam->proj == 'i')
		ft_iso(mlx_all);
	else if (mlx_all->cam->proj == 'p')
		ft_parallel(mlx_all);
	mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
	mlx_put_image_to_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr,
			mlx_all->win->img_ptr, 0, 0);
}
