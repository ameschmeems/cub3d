/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:43:55 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/24 15:22:19 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>


# define WIDTH 1280
# define HEIGHT 720
# define MAP_W 160
# define MAP_H 160

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

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_xpm_data
{
	int		size;
	int		colours;
	int		cpp;
	char	**code;
	int		*value;
}	t_xpm_data;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			start_dir;
	t_vector	pos;
	t_vector	dir;
	t_vector	perp_dir;
	t_vector	plane;
	t_vector	ray_dir;
	t_img		map_img;
	t_img		fps;
	char		**map;
	int			f_colour;
	int			c_colour;
	int			north_size;
	int			east_size;
	int			south_size;
	int			west_size;
	int 		**place_holder_east;
	int			**place_holder_south;
	int			**place_holder_west;	
	int			**place_holder_north;

}				t_data;

int		arr_len(char **s);
bool	get_input(t_data *data, char *path_name);
bool	set_colour_f_and_c(char *line, t_data *data);
bool	error_message_bool(char *line);
void	print_2d_array(char	**arr, int fd);
void	free_2d_array(char	**arr);
int		u_hextoi(char	*hex);
bool	xpm_to_int_arr(char *path, char c, t_data *data);
void	print_2d_int_array(int **arr, int size);
bool	check_for_surround_vertical(char **map);
bool	check_for_surround_horizontal(char **map);
#endif
