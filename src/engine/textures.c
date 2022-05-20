/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:34:29 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/20 18:12:10 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	read_from_texture(t_data *data, int **tex, int size, int i)
{
	double	percentage;
	int		color;

	if (data->side == NORTH || data->side == SOUTH)
		percentage = fmod(data->v.y, 100);
	else
		percentage = fmod(data->v.x, 100);
	percentage /= 100;
	if (data->rev)
		percentage = 1 - percentage;
	data->pixel_y = (int)(size * i / data->line_height);
	data->pixel_x = (int)(percentage * size);
	color = tex[data->pixel_y][data->pixel_x];
	return (color);
}

int	get_pixel(t_data *data, int i)
{
	int	color;

	data->v.x = data->perp_wall_dist * data->ray_dir.x + data->pos.x;
	data->v.y = data->perp_wall_dist * data->ray_dir.y + data->pos.y;
	if (data->side == SOUTH || data->side == WEST)
		data->rev = 1;
	else
		data->rev = 0;
	if (data->side == NORTH)
		color = read_from_texture(data, data->place_holder_north, i, \
			data->north_size);
	else if (data->side == SOUTH)
		color = read_from_texture(data, data->place_holder_south, i, \
			data->south_size);
	else if (data->side == WEST)
		color = read_from_texture(data, data->place_holder_west, i, \
			data->west_size);
	else if (data->side == EAST)
		color = read_from_texture(data, data->place_holder_east, i, \
			data->east_size);
	return (color);
}
