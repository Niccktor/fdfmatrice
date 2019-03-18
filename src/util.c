/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/18 12:35:54 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mlx	*ft_new_mlx()
{
	t_mlx	*new;

	if ((new = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((new->mlx_ptr = mlx_init()) == NULL)
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	if ((new->map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
	{
		ft_memdel((void **)&(new->mlx_ptr));
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->map->len = -1;
	return (new);
}

t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int width, int height)
{
	if ((mlx_all->win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
	{	
		ft_memdel((void **)&(mlx_all->mlx_ptr));
		ft_memdel((void **)&(mlx_all->map));
		ft_memdel((void **)&mlx_all);
		return (NULL);
	}
	mlx_all->win->name = s;
	mlx_all->win->width = width;
	mlx_all->win->height = height;
	mlx_all->win->win_ptr = mlx_new_window(mlx_all->mlx_ptr,
			mlx_all->win->width, mlx_all->win->height, mlx_all->win->name);
	mlx_all->win->ligne = 0;
	mlx_all->win->x_ligne = 0;
	mlx_all->win->y_ligne = 0;

	return (mlx_all);
}

t_mlx	*ft_new_cam(t_mlx *mlx_all)
{
	if ((mlx_all->cam = (t_cam *)ft_memalloc(sizeof(t_cam))) == NULL)
	{
		ft_memdel((void **)&(mlx_all->mlx_ptr));
		ft_memdel((void **)&(mlx_all->map));
		ft_memdel((void **)&(mlx_all->win));
		ft_memdel((void **)&mlx_all);
		return (NULL);
	}
	mlx_all->cam->proj = 'i';
	mlx_all->cam->di_x = 16;
	mlx_all->cam->di_y = 9;
	mlx_all->cam->di_z = 1;
	mlx_all->cam->up_down = 0;
	mlx_all->cam->left_right = 0;
	mlx_all->cam->angle = 0.523599;
	return (mlx_all);
}

int		ft_ishexa(char c)
{
	if (ft_isdigit(c) == 1
			|| ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
		return (1);
	return (0);
}
