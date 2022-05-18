/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:46:51 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/18 18:58:33 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	//additional cleanup
	exit(0);
}

void	movement(int keycode, t_data *data)
{
	if (keycode == K_W)
	{
		data->pos.x += 5 * data->dir.x;
		data->pos.y += 5 * data->dir.y;
	}
	if (keycode == K_S)
	{
		data->pos.x -= 5 * data->dir.x;
		data->pos.y -= 5 * data->dir.y;
	}
	if (keycode == K_A)
	{
		data->pos.x += 5 * data->perp_dir.x;
		data->pos.y += 5 * data->perp_dir.y;
	}
	if (keycode == K_A)
	{
		data->pos.x -= 5 * data->perp_dir.x;
		data->pos.y -= 5 * data->perp_dir.y;
	}
}

void	rotation(int keycode, t_data *data)
{
	//left off here
}

void	key_handler(int keycode, t_data *data)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		//additional cleanup
		exit(0);
	}
	movement(keycode, data);
}
