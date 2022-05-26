/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:49:09 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/26 15:45:29 by kpucylo          ###   ########.fr       */
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
				data->pos.x = j * 100 + 50;
				data->pos.y = i * 100 + 50;
				set_start_pos(data, i, j);
			}
		}
		j = -1;
	}
}

bool	check_player_start(char **map)
{
	int	i;
	int	j;
	int	p_count;

	i = -1;
	p_count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || \
				map[i][j] == 'E' || map[i][j] == 'S')
				p_count++;
		}
	}
	if (p_count != 1)
		return (false);
	return (true);
}

void	free_image_arr(int **array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(array[i]);
	free(array);
}

t_data	*init(char *path)
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
	if (get_input(data, path) == false)
		return (NULL);
	if (!check_player_start(data->map))
	{
		error_message_bool("Invalid amount of player positions\n", false);
		free_stuff(data);
		exit(0);
	}
	set_vectors(data);
	return (data);
}
