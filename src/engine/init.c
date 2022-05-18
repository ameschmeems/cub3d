/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:49:09 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/18 14:57:39 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_start_pos(t_data *data, int i, int j)
{
}

void	set_vectors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < arr_len(data->map))
	{
		while (++j < ft_strlen(data->map[i]))
		{
			if (data->map[i] == 'N')
			{
				data->start_dir = FORWARD;
			}
		}
	}
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
	set_vectors(data);
	return (data);
}
