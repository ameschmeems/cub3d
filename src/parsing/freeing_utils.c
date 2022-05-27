/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:59:21 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 16:15:27 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	free_image_arr(int **array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(array[i]);
	free(array);
}

void	free_stuff_2(t_data *data)
{
	if (data->tex_east == true)
		free_2d_int_array(data->place_holder_east, data->east_size);
	if (data->tex_west == true)
		free_2d_int_array(data->place_holder_west, data->west_size);
	if (data->tex_south == true)
		free_2d_int_array(data->place_holder_south, data->south_size);
	if (data->tex_north == true)
		free_2d_int_array(data->place_holder_north, data->north_size);
	if (data->map)
		free_2d_array(data->map);
	free(data);
}

bool	free_str_and_return_false(char *s1)
{
	free(s1);
	return (false);
}
