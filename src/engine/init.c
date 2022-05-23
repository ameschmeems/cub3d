/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:49:09 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/23 14:19:47 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	set_start_pos(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->dir.x = 0;
		data->dir.y = -1;
	}
	else if (data->map[i][j] == 'S')
	{
		data->dir.x = 0;
		data->dir.y = 1;
	}
	else if (data->map[i][j] == 'W')
	{
		data->dir.x = -1;
		data->dir.y = 0;
	}
	else if (data->map[i][j] == 'E')
	{
		data->dir.x = 1;
		data->dir.y = 0;
	}
	data->perp_dir.x = data->dir.y;
	data->perp_dir.y = data->dir.x * -1;
	data->plane.x = data->perp_dir.x;
	data->plane.y = data->perp_dir.y;
	normalize_vector(&data->plane, 0.66);
}

void	set_vectors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < arr_len(data->map))
	{
		while (++j < (int)ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->pos.x = j * 100;
				data->pos.y = i * 100;
				set_start_pos(data, i, j);
			}
		}
		j = -1;
	}
}

char	**testing_map(void)
{
	char	**map;
	int		i;

	i = 0;
	map = calloc(sizeof(char *), 15);
	map[0] = ft_strdup("111111111 11111");
	map[1] = ft_strdup("100000001110001");
	map[2] = ft_strdup("100000000000001");
	map[3] = ft_strdup("100000011110001");
	map[4] = ft_strdup("100000011110001");
	map[5] = ft_strdup("100000011110001");
	map[6] = ft_strdup("100000000000001");
	map[7] = ft_strdup("100000010000111");
	map[8] = ft_strdup("1000000000001  ");
	map[9] = ft_strdup("100000000000111");
	map[10] = ft_strdup("100110000000001");
	map[11] = ft_strdup("100110000000001");
	map[12] = ft_strdup("100000N00001111");
	map[13] = ft_strdup("100000000000001");
	map[14] = ft_strdup("111111111111111");
	return (map);
}

t_data	*init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->map_img.img = mlx_new_image(data->mlx, MAP_W, MAP_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.img, \
		&data->map_img.bits_per_pixel, \
		&data->map_img.line_length, &data->map_img.endian);
	data->fps.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->fps.addr = mlx_get_data_addr(data->fps.img, \
		&data->fps.bits_per_pixel, \
		&data->fps.line_length, &data->fps.endian);
	//map here maybe
	data->place_holder_east = malloc(sizeof(int *) * 4);
	data->place_holder_east[0] = malloc(sizeof(int) * 4);
	data->place_holder_east[1] = malloc(sizeof(int) * 4);
	data->place_holder_east[2] = malloc(sizeof(int) * 4);
	data->place_holder_east[3] = malloc(sizeof(int) * 4);
	data->place_holder_east[0][0] = 0x00FF0000;
	data->place_holder_east[0][1] = 0x00FF0000;
	data->place_holder_east[0][2] = 0x00FF0000;
	data->place_holder_east[0][3] = 0x00FF0000;
	data->place_holder_east[1][0] = 0x00FF0000;
	data->place_holder_east[1][1] = 0x00000000;
	data->place_holder_east[1][2] = 0x00000000;
	data->place_holder_east[1][3] = 0x00FF0000;
	data->place_holder_east[2][0] = 0x00FF0000;
	data->place_holder_east[2][1] = 0x00000000;
	data->place_holder_east[2][2] = 0x00000000;
	data->place_holder_east[2][3] = 0x00FF0000;
	data->place_holder_east[3][0] = 0x00FF0000;
	data->place_holder_east[3][1] = 0x00FF0000;
	data->place_holder_east[3][2] = 0x00FF0000;
	data->place_holder_east[3][3] = 0x00FF0000;
	data->c_colour = 0x000000FF;
	data->f_colour = 0x002C2C2C;
	data->place_holder_north = data->place_holder_east;
	data->place_holder_west = data->place_holder_east;
	data->place_holder_south = data->place_holder_east;
	data->east_size = 4;
	data->west_size = 4;
	data->south_size = 4;
	data->north_size = 4;
	data->map = testing_map();
	set_vectors(data);
	return (data);
}
