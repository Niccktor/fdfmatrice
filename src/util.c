/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 00:01:02 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mlx		*ft_new_mlx(void)
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

t_mlx		*ft_new_win(t_mlx *mlx_all, char *s, int width, int height)
{
	int bpp;
	int	s_l;
	int	endian;

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

	mlx_all->win->img_ptr = mlx_new_image(mlx_all->mlx_ptr, width, height);
	mlx_all->win->img_str = (unsigned int *)mlx_get_data_addr(mlx_all->win->img_ptr
			, &bpp, &s_l, &endian);

	ft_putstr("bpp : ");
	ft_putnbr(bpp);
	ft_putstr(" s_l : ");
	ft_putnbr(s_l);
	ft_putstr(" endian : ");
	ft_putnbr(endian);
	ft_putstr("\n");
	mlx_all->win->ligne = 0;
	mlx_all->win->x_ligne = 0;
	mlx_all->win->y_ligne = 0;
	return (mlx_all);
}

t_mlx		*ft_new_cam(t_mlx *mlx_all)
{
	if ((mlx_all->cam = (t_cam *)ft_memalloc(sizeof(t_cam))) == NULL)
	{
		ft_memdel((void **)&(mlx_all->mlx_ptr));
		ft_memdel((void **)&(mlx_all->map));
		ft_memdel((void **)&(mlx_all->win));
		ft_memdel((void **)&mlx_all);
		return (NULL);
	}
	mlx_all->cam->opacity = 0;
	mlx_all->cam->proj = 'i';
	ft_set_iso(mlx_all, 'n');
	return (mlx_all);
}

int			ft_ishexa(char c)
{
	if (ft_isdigit(c) == 1
			|| ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
		return (1);
	return (0);
}

t_point		*ft_newpoint(int x, int y, char *line)
{
	t_point		*new;
	int			j;
	char		*rgb;

	if ((new = (t_point *)ft_memalloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(line);
	j = 0;
	while (line[j] != ',' && line[j] != '\0')
		j++;
	if (line[j] == ',')
	{
		rgb = ft_strsub(line, j + 3, 8);
		new->color = ft_atoi_base(rgb, 16);
		ft_memdel((void **)&rgb);
	}
	else
		new->color = ft_atoi_base("FF0000", 16);
	return (new);
}
