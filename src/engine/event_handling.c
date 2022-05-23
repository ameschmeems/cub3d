/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:46:51 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/23 13:11:47 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	x_close(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	mlx_destroy_window(data->mlx, data->win);
	//additional cleanup
	exit(0);
}

void	movement(int keycode, t_data *data)
{
	if (keycode == K_W && !collision_detection(data, FORWARD))
	{
		data->pos.x += 5 * data->dir.x;
		data->pos.y += 5 * data->dir.y;
	}
	if (keycode == K_S && !collision_detection(data, BACK))
	{
		data->pos.x -= 5 * data->dir.x;
		data->pos.y -= 5 * data->dir.y;
	}
	if (keycode == K_A && !collision_detection(data, LEFT))
	{
		data->pos.x += 5 * data->perp_dir.x;
		data->pos.y += 5 * data->perp_dir.y;
	}
	if (keycode == K_D && !collision_detection(data, RIGHT))
	{
		data->pos.x -= 5 * data->perp_dir.x;
		data->pos.y -= 5 * data->perp_dir.y;
	}
}

void	rotate_vectors(t_data *data, double alpha)
{
	double	temp;

	temp = data->dir.x;
	data->dir.x = data->dir.x * cos(alpha) - data->dir.y * sin(alpha);
	data->dir.y = temp * sin(alpha) + data->dir.y * cos(alpha);
	temp = data->perp_dir.x;
	data->perp_dir.x = data->perp_dir.x * cos(alpha) - \
		data->perp_dir.y * sin(alpha);
	data->perp_dir.y = temp * sin(alpha) + data->perp_dir.y * cos(alpha);
	temp = data->plane.x;
	data->plane.x = data->plane.x * cos(alpha) - data->plane.y * sin(alpha);
	data->plane.y = temp * sin(alpha) + data->plane.y * cos(alpha);
}

void	rotation(int keycode, t_data *data)
{
	if (keycode == K_LEFT)
		rotate_vectors(data, -0.05);
	else if (keycode == K_RIGHT)
		rotate_vectors(data, 0.05);
	normalize_vector(&data->dir, 1);
	normalize_vector(&data->perp_dir, 1);
	normalize_vector(&data->plane, 0.66);
}

int	key_handler(int keycode, void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		//additional cleanup
		exit(0);
	}
	movement(keycode, data);
	rotation(keycode, data);
	render(data);
	return (0);
}
