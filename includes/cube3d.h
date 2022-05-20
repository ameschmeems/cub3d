/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:43:55 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/20 15:27:45 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAP_W 150
# define MAP_H 150

enum
{
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_W = 13,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_DOWN = 125,
	K_UP = 126
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	FORWARD,
	RIGHT,
	BACK,
	LEFT
};

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_vector	pos;
	t_vector	dir;
	t_vector	perp_dir;
	t_vector	plane;
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_img		map_img;
	t_img		fps;
	char		**map;
	int			f_colour;
	int			c_colour;
	int			noth_size;
	int			east_size;
	int			south_size;
	int			west_size;
	int			**place_holder_north;
	int			**place_holder_east;
	int			**place_holder_south;
	int			**place_holder_west;
	double		camera_x;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_data;

int		arr_len(char **s);
void	normalize_vector(t_vector *dir, double len);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_line(t_data *data, int x, unsigned int color);
void	raycaster(t_data *data, int amount);
t_data	*init(void);
void	render(t_data *data);
int		x_close(void *ptr);
int		key_handler(int keycode, void *ptr);
int		collision_detection(t_data *data, int state);
int		out_of_bounds(t_data *data, int i, int j);

#endif
