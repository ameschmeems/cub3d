/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:36 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/26 13:45:14 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	arr_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	out_of_bounds(t_data *data, int i, int j)
{
	int	retval;

	retval = 0;
	if (i < 0 || j < 0 || i > arr_len(data->map) - 1)
		retval = 1;
	else if (j > (int)ft_strlen(data->map[i]) - 1)
		retval = 1;
	return (retval);
}

void	free_stuff(t_data *data)
{
	free_2d_array(data->map);
	free_image_arr(data->place_holder_east, data->east_size);
	free_image_arr(data->place_holder_west, data->west_size);
	free_image_arr(data->place_holder_south, data->south_size);
	free_image_arr(data->place_holder_north, data->north_size);
	mlx_destroy_image(data->mlx, data->map_img.img);
	mlx_destroy_image(data->mlx, data->fps.img);
	mlx_destroy_window(data->mlx, data->win);
}
