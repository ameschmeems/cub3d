/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_int_arr_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:49:25 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 17:05:05 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	distribute_into_struct(char c, int size, int **arr, t_data *data)
{
	if (c == 'N')
	{
		data->north_size = size;
		data->place_holder_north = arr;
	}
	else if (c == 'E')
	{
		data->east_size = size;
		data->place_holder_east = arr;
	}
	else if (c == 'S')
	{
		data->south_size = size;
		data->place_holder_south = arr;
	}
	else if (c == 'W')
	{
		data->west_size = size;
		data->place_holder_west = arr;
	}
}

char	*get_xpm_path(char *path)
{
	path += 2;
	while (path[0] == ' ')
		path++;
	path[ft_strlen(path) - 1] = 0;
	return (path);
}

void	set_bool_tex(char c, t_data *data)
{
	if (c == 'N')
		data->tex_north = true;
	else if (c == 'S')
		data->tex_south = true;
	else if (c == 'E')
		data->tex_east = true;
	else if (c == 'W')
		data->tex_west = true;
}

bool	xpm_to_int_arr(char *path, char c, t_data *data)
{
	int			fd;
	char		*line;
	t_xpm_data	text_data;
	int			**arr;

	path = get_xpm_path(path);
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 5))
		return (error_message_bool("Texture is not a .xpm File!", false));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_message_bool(path + 2, true));
	line = skip_lines_xpm(fd);
	fill_texture_size(line, &text_data);
	if (text_data.size == -1)
		return (false);
	fill_var_arrays(&text_data, fd);
	arr = fill_texture_array(&text_data, fd);
	free(text_data.value);
	free_2d_array(text_data.code);
	distribute_into_struct(c, text_data.size, arr, data);
	set_bool_tex(c, data);
	return (true);
}
