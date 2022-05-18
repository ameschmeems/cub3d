/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:43:55 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/18 14:59:22 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

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
}				t_data;

int	arr_len(char **s);

#endif
