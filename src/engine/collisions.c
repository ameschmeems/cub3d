/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:39:36 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/19 17:09:51 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	collision_detection(t_data *data, int state)
{
	if (state == FORWARD)
	{
		data->map_x = (data->pos.x + 20 * data->dir.x) / 100;
		data->map_y = (data->pos.y + 20 * data->dir.y) / 100;
	}
	else if (state == BACK)
	{
		data->map_x = (data->pos.x - 20 * data->dir.x) / 100;
		data->map_y = (data->pos.y - 20 * data->dir.y) / 100;
	}
	else if (state == LEFT)
	{
		data->map_x = (data->pos.x + 20 * data->perp_dir.x) / 100;
		data->map_y = (data->pos.y + 20 * data->perp_dir.y) / 100;
	}
	else if (state == RIGHT)
	{
		data->map_x = (data->pos.x - 20 * data->perp_dir.x) / 100;
		data->map_y = (data->pos.y - 20 * data->perp_dir.y) / 100;
	}
	if (data->map[data->map_y][data->map_x] == '1')
		return (1);
	return (0);
}
