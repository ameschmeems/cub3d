/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:24:54 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/19 18:16:06 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	put_sqr(t_data *data, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			my_mlx_pixel_put(&data->map_img, x + j, y + i, color);
		my_mlx_pixel_put(&data->map_img, x + j, y + i, 0x00000000);
	}
	k = x + j;
	i = -1;
	while (++i < 10)
		my_mlx_pixel_put(&data->map_img, k, y + i, 0x00000000);
}

void	generate_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->map_x = ((data->pos.x - 800) / 100);
	data->map_y = ((data->pos.y - 800) / 100);
	while (++i < 16)
	{
		while (++j < 15)
		{
			if (out_of_bounds(data, data->map_y + i, data->map_x + j))
				put_sqr(data, j * 10, i * 10, 0x00000000);
			else if (data->map[data->map_y + i][data->map_x + j] == '1')
				put_sqr(data, j * 10, i * 10, 0x00C8C8C8);
			else if (data->map[data->map_y + i][data->map_x + j] >= '0')
				put_sqr(data, j * 10, i * 10, 0x002C2C2C);
			else
				put_sqr(data, j * 10, i * 10, 0x00000000);
		}
		j = -1;
	}
}

void	draw_line(t_data *data, int x, unsigned int color)
{
	int	i;

	i = -1;
	while (++i < data->draw_start)
		my_mlx_pixel_put(&data->fps, x, i, 0x0000008B);
	i = -1;
	while (++i < data->draw_end - data->draw_start)
		my_mlx_pixel_put(&data->fps, x, data->draw_start + i, color);
	i = -1;
	while (++i < HEIGHT - data->draw_end)
		my_mlx_pixel_put(&data->fps, x, i + data->draw_end, 0x002C2C2C);
}

void	render(t_data *data)
{
	raycaster(data, WIDTH);
	generate_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map_img.img, \
		WIDTH - 150, 0);
}
