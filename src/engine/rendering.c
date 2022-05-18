/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:24:54 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/18 18:41:41 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	put_sqr(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (++i < 10)
	{
		while (++j < 10)
			my_mlx_pixel_put(&data->map_img, x + i, y + j, color);
		my_mlx_pixel_put(&data->map_img, x + i, y + j, 0x00000000);
	}
	k = x + i;
	i = -1;
	while (++i < 11)
		my_mlx_pixel_put(&data->map_img, k, y + i, 0x00000000);
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
	//generate minimap
	raycaster(data, WIDTH);
}
