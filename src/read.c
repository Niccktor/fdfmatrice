/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:52 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/01 16:34:12 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <fcntl.h>

void	ft_print_tab(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			ft_putnbr(mlx_all->map->map[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

void	ft_print_color(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			ft_putnbr(mlx_all->map->color[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int		ft_parse_map(char *file, t_mlx *mlx_all)
{
	char	*line;
	int		fd;
	int 	i;

	if ((mlx_all->map->height = ft_get_height(file)) == 0)
			return (-1);
	mlx_all->map->map = (int **)ft_memalloc(sizeof(int *) *
			(mlx_all->map->height + 1));
	mlx_all->map->color = (unsigned int **)ft_memalloc(sizeof(int *) *
			(mlx_all->map->height + 1));
	if ((fd = open(file, O_RDONLY)) < 0 || mlx_all->map->color == NULL
			|| mlx_all->map->map == NULL)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == -1
				|| ft_get_map(mlx_all, ft_strsplit(line, ' '), i) == -1)
			return (-1);
		ft_memdel((void **)&line);
		i++;
	}
	ft_print_tab(mlx_all);
	ft_putstr("\n");
	ft_print_color(mlx_all);
	//ft_draw_map(mlx_all);
	return (0);
}

int		ft_get_map(t_mlx *mlx_all, char **line, int k)
{
	int		i;
	int		j;
	int		len;
	char	*rgb;

	len = 0;
	while (line[len] != '\0')
		len++;
	if (mlx_all->map->len != -1 && (mlx_all->map->len != len))
		return (-1);
	if (mlx_all->map->len == -1)
		mlx_all->map->len = len;
	mlx_all->map->map[k] = (int *)ft_memalloc(sizeof(int) * (len + 1));
	mlx_all->map->map[k][len + 1] = '\0';
	mlx_all->map->color[k] =
		(unsigned int *)ft_memalloc(sizeof(unsigned int) * (len + 1));
	mlx_all->map->color[k][len + 1] = '\0';
	i = 0;
	while (line[i] != '\0')
	{
		mlx_all->map->map[k][i] = ft_atoi(line[i]);
		j = 0;
		while (line[i][j] != ',' && line[i][j] != '\0')
			j++;
		if (line[i][j] == ',')
		{
			rgb = ft_strsub(line[i], j + 3, 8);
			mlx_all->map->color[k][i] = ft_atoi_base(rgb, 16);
			ft_memdel((void **)&rgb);
		}
		else
			mlx_all->map->color[k][i] = ft_atoi_base("FF0000", 16);
		ft_memdel((void **)&(line[i]));
		i++;
	}
	ft_memdel((void **)&line);
	return (0);
}

int		ft_check_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i + j] != '\0')
	{
		j = 0;
		if (line[i] == ',')
		{
			j = 1;
			while (line[i + j] != ' ' && line[i + j] != '\0')
			{
				if ((j == 1 && line[i + j] == '0')
						|| (j == 2 && line[i + j] == 'x')
						|| (j > 2 && j < 9 && ft_ishexa(line[i + j ]) == 1))
					j++;
				else  
					return (-1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
