/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:21:24 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/19 17:07:52 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_ray_2(t_data *data)
{
	if (data->ray_dir.x < 0)
	{
		data->step_x = -1;
		data->side_dist.x = ((data->pos.x) - data->map_x) * data->delta_dist.x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist.x = (data->map_x + 1 - data->pos.x) * \
			data->delta_dist.x;
	}
	if (data->ray_dir.y < 0)
	{
		data->step_y = -1;
		data->side_dist.y = ((data->pos.y) - data->map_y) * data->delta_dist.y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist.y = (data->map_y + 1 - data->pos.y) * \
			data->delta_dist.y;
	}
	data->hit = 0;
}

void	init_ray(t_data *data, int i, int amount)
{
	data->camera_x = 2 * i / (double)amount - 1;
	data->ray_dir.x = data->dir.x + data->plane.x * data->camera_x;
	data->ray_dir.y = data->dir.y + data->plane.y * data->camera_x;
	data->map_x = (int)data->pos.x;
	data->map_y = (int)data->pos.y;
	if (data->ray_dir.x == 0)
		data->delta_dist.x = 1e30;
	else
		data->delta_dist.x = fabs(1 / data->ray_dir.x);
	if (data->ray_dir.y == 0)
		data->delta_dist.y = 1e30;
	else
		data->delta_dist.y = fabs(1 / data->ray_dir.y);
	init_ray_2(data);
}

void	dda(t_data *data)
{
	while (!data->hit)
	{
		if (data->side_dist.x < data->side_dist.y)
		{
			data->side_dist.x += data->delta_dist.x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist.y += data->delta_dist.y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y / 100][data->map_x / 100] == '1')
			data->hit = 1;
	}
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist.x - data->delta_dist.x;
	else
		data->perp_wall_dist = data->side_dist.y - data->delta_dist.y;
	if (data->perp_wall_dist == 0)
		data->perp_wall_dist = 1;
}

void	raycaster(t_data *data, int amount)
{
	int	i;
	int	color;
	int	num;

	i = -1;
	while (++i < amount)
	{
		init_ray(data, i, amount);
		dda(data);
		data->line_height = (int)(HEIGHT / (data->perp_wall_dist / 35));
		data->draw_start = (-data->line_height / 2 + HEIGHT / 2);
		if (data->draw_start < 0)
			data->draw_start = 0;
		data->draw_end = (data->line_height / 2 + HEIGHT / 2);
		if (data->draw_end >= HEIGHT)
			data->draw_end = HEIGHT - 1;
		if (data->side == 0)
			color = 0x00FF0000;
		else
			color = 0x0000FF00;
		draw_line(data, amount - i - 1, color);
	}
}
