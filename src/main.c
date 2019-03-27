/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 19:02:05 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx_all;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf map_file\n");
		return (-1);
	}
	if ((mlx_all = ft_new_mlx()) == NULL)
		return (-1);
	if ((mlx_all = ft_new_win(mlx_all, "fdf", 1920, 1080)) == NULL)
		return (-1);
	if ((mlx_all = ft_new_cam(mlx_all)) == NULL)
		return (-1);
	if (ft_parse_map(argv[1], mlx_all) == -1)
	{
		ft_putstr("error\n");
		ft_close(mlx_all);
	}
	ft_set_iso(mlx_all, 'r');
	ft_render(mlx_all);
	mlx_key_hook(mlx_all->win->win_ptr, ft_key_hook, (void *)mlx_all);
	mlx_mouse_hook(mlx_all->win->win_ptr, ft_mouse_hook, (void *)mlx_all);
	mlx_loop(mlx_all->mlx_ptr);
	return (0);
}

int		ft_close(t_mlx *mlx_all)
{
	if (mlx_all != NULL)
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
	exit(0);
	return (0);
}
