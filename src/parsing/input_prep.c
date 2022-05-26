/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:32:02 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 14:07:15 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	read_input_file(t_data *data, int fd)
{
	char	*l;
	int		i;

	i = 0;
	l = get_next_line(fd);
	while (l && i < 6)
	{
		if ((l[0] == 'N' || l[0] == 'E' || l[0] == 'S' || l[0] == 'W') && ++i)
		{
			if (xpm_to_int_arr(l, l[0], data) == false)
				return (false);
		}
		else if ((l[0] == 'F' || l[0] == 'C') && ++i)
		{
			if (set_colour_f_and_c(l, data) == false)
				return (false);
		}
		else if (ft_strlen(l) > 1)
			return (false);
		free(l);
		l = get_next_line(fd);
	}
	free(l);
	return (i);
}

char	*fill_map_with_spaces_util(char	*line, int size, char *out, int i)
{
	if ((int)ft_strlen(line) > size)
	{
		line[size] = 0;
		return (line);
	}
	else if ((int)ft_strlen(line) == size)
	{
		if (line[size - 1] != '\n')
			return (line);
		line[size -1] = ' ';
		line[size] = '\0';
		return (line);
	}
	else
	{
		out = ft_calloc(sizeof(char), size + 1);
		ft_strlcpy(out, line, size);
		i = ft_strlen(out) - 1;
		if (line[i] != '\n')
			i++;
		while (i < size)
			out[i++] = ' ';
		free(line);
		return (out);
	}
}

void	fill_map_with_spaces(char **map)
{
	int	x;
	int	i;
	int	len;

	i = 0;
	x = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > x)
			x = len;
		i++;
	}
	i = 0;
	x -= 1;
	while (map[i])
	{
		map[i] = fill_map_with_spaces_util(map[i], x, "", 0);
		i++;
	}
}

bool	read_map(int fd, t_data *data)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	map = ft_calloc(sizeof(char *), 1);
	while (line && ft_strlen(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		map = add_after_string(map, line);
		line = get_next_line(fd);
	}
	add_nl(map);
	fill_map_with_spaces(map);
	if (check_for_illegal_chars(map) == false)
		return (error_message_bool("Illegal Characters.\n", false));
	if (check_for_surround_vertical(map) == false)
		return (error_message_bool("Map isn't enclosed vertically.\n", false));
	if (check_for_surround_horizontal(map) == false)
		return (error_message_bool("Map isn't enclosed\
		 horizontically.\n", false));
	data->map = map;
	return (true);
}

bool	get_input(t_data *data, char *path_name)
{
	int	fd;

	if (ft_strncmp(path_name + ft_strlen(path_name) - 4, ".cub", 5))
		return (error_message_bool("Argument is not a \".cub\" file\n", false));
	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (error_message_bool(path_name, true));
	if (read_input_file(data, fd) != 6)
		return (error_message_bool("Issue with cub file\n", false));
	if (read_map(fd, data) == false)
		return (false);
	return (true);
}
