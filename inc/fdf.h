/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/27 18:30:00 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>

typedef struct		s_point
{
	double 			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_point;

typedef struct		s_map
{
	t_point			***map;
	int				height;
	int				len;
}					t_map;

typedef struct		s_bres
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			dx;
	double			dy;
	int				x_inc;
	int				y_inc;
	int				i;
	int				error;
}					t_bres;


typedef struct		s_win
{
	void			*win_ptr;
	char			*name;
	int 			width;
	int 			height;
	void			*img_ptr;
	unsigned int	*img_str;
	int				ligne;
	int				x_ligne;
	int				y_ligne;
}					t_win;

typedef struct		s_cam
{
	int				up_down;
	int				left_right;
	double			di_x;
	double			di_y;
	double			di_z;
	char			proj;
	unsigned int	opacity;
	double			angle;
}					t_cam;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	t_win			*win;
	t_map			*map;
	t_cam			*cam;
}					t_mlx;

/*
 *					main.c
 */

int		ft_close(t_mlx *mlx_all);

/*
 *					event.c
 */
int		ft_key_hook(int key, void *para);
int		ft_mouse_hook(int button, int x, int y, void *para);
void	ft_render(t_mlx *mlx_all);


/*
 *					util.c
 */
t_mlx	*ft_new_mlx();
t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int width, int height);
t_mlx	*ft_new_cam(t_mlx *mlx_all);
int		ft_ishexa(char c);
t_point	*ft_newpoint(int x, int y, char *line);
/*
 *					draw.c
 */
t_bres	*ft_new_bres(int x1, int y1, int x2, int y2);
void	ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color);
int		ft_draw_map(t_mlx *mlx_all);
/*
 *					read.c
 */
int		ft_parse_map(char *file, t_mlx *mlx_all);
int		ft_get_map(t_mlx *mlx_all, char **line, int k);
int		ft_check_line(char *line);
int		ft_get_height(char *file);

unsigned int	ft_get_color(char *rgb);

/*
 * 					iso.c
 */
void			ft_iso(t_mlx *mlx_all);
void			ft_set_iso(t_mlx *mlx_all, char para);
/*
 *					retation.c
 */
void			ft_x_rotation(t_mlx *mlx_all, double theta);
void			ft_y_rotation(t_mlx *mlx_all, double theta);
void			ft_z_rotation(t_mlx *mlx_all, double theta);
/*
 * 					par.c
 */
void			ft_parallel(t_mlx *mlx_all);
void			ft_set_para(t_mlx *mlx_all, char para);

double			ft_sin(double x);
double			ft_cos(double x);
double			ft_tan(double x);
void			ft_print_tab(t_mlx *mlx_all);

#endif
