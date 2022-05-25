#include "../../includes/cube3d.h"
#include <stdio.h>

bool	error_message_bool(char *line, bool err)
{
	write(2, "Error!\n", 8);
	if (err == true)
		perror(line);
	else
		write(2, line, ft_strlen(line));
	return (false);
}

// bool	load_texture(char *line, t_data *data)
// {
// 	if (line[0] == 'N')
// 	{
// 		if(!read_textures(line, data->place_holder_north))
// 			return (false);
// 	}
// 	else if (line[0] == 'E')
// 	{
// 		if(!read_textures(line, data->place_holder_east))
// 			return (false);
// 	}
// 	else if (line[0] == 'S')
// 	{
// 		if(!read_textures(line, data->place_holder_south))
// 			return (false);
// 	}
// 	else if (line[0] == 'W')
// 	{
// 		if(!read_textures(line, data->place_holder_west))
// 			return (false);
// 	}
// 	return (true);
// }

bool	read_input_file(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < 6)
	{
		if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S' || line[0] == 'W')
		{
			if (xpm_to_int_arr(line, line[0], data) == false)
				return (false);
			i++;
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			set_colour_f_and_c(line, data);
			i++;
		}
		else if (ft_strlen(line) > 1)
			return (false);
		usleep(5);
		free(line);
		line = get_next_line(fd);
	}
	if (i != 6)
		return (false);
	return (true);
}

char **add_after_string(char **arr, char *new_el)
{
	int i;
	int	j;
	char **temp;

	i = 0;
	while(arr[i])
		i++;
	temp = ft_calloc((sizeof(char *)), i + 2);
	j = 0;
	while(arr[j])
	{
		temp[j] = arr[j];
		j++;
	}
	temp[j] = new_el;
	free(arr);
	return (temp);
}

char	*fill_map_with_spaces_util(char	*line, int size)
{
	// char	*out;
	// int		i;

	// if (ft_strlen(line) > size)
	// {
	// 	line[size] = 0;
	// 	return (line);
	// }
	// else if (ft_strlen(line) == size)
	// {
	// 	line[size -1] = 0;
	// }
	// else
	// {
	// 	out = ft_calloc(sizeof(char), size + 1);
	// 	ft_strlcpy(out, line, size);
	// 	i = ft_strlen(out) - 1;
	// 	while (i < size)
	// 		out[i++] = ' ';
	// 	free(line);
	// }
	// return (out);

	char	*out;
	int		i;

	if ((int)ft_strlen(line) > size)
	{
		line[size] = 0;
		return (line);
	}
	else if ((int)ft_strlen(line) == size)
	{
		line[size -1] = ' ';
		line[size -1] = '\0';
		return(line);
	}
	else
	{
		out = ft_calloc(sizeof(char), size + 1);
		ft_strlcpy(out, line, size);
		i = ft_strlen(out) - 1;
		while (i < size)
			out[i++] = ' ';
		free(line);
		return(out);
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
		map[i] = fill_map_with_spaces_util(map[i], x);
		i++;
	}
}

void	print_map(char **arr, int fd)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			ft_putchar_fd('\'', fd);
			ft_putstr_fd(arr[i], fd);
			ft_putchar_fd('\'', fd);
			if (arr[i][ft_strlen(arr[i]) - 1] != '\n')
				ft_putchar_fd('\n', fd);
			i++;
		}
	}
}

bool	check_for_illegal_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '0'
				&& map[y][x] != 'N' && map[y][x] != 'E' && map[y][x] != 'S'
				&& map[y][x] != 'W')
				return(false);
			x++;
		}
		y++;
	}
	return (true);
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
	fill_map_with_spaces(map);
	if (check_for_illegal_chars(map) == false)
		return (error_message_bool("Illegal Characters.\n", false));
	if (check_for_surround_vertical(map) == false)
		return (error_message_bool("Map isn't enclosed vertically.\n", false));
	if (check_for_surround_horizontal(map) == false)
		return (error_message_bool("Map isn't enclosed horizontically.\n", false));
	data->map = map;
	// print_map(map, 1);
	return true;
}

bool	get_input(t_data *data, char *path_name)
{
	int	fd;

	if (ft_strncmp(path_name + ft_strlen(path_name) - 4, ".cub", 5))
		return (error_message_bool("Argument is not a \".cub\" file\n", false));
	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (error_message_bool(path_name, true));
	if (read_input_file(data, fd) == false)
		return (error_message_bool("Issue with cub file\n", false));
	// get_map();
	if (read_map(fd, data) == false)
		return (false);

	// print_map(data->map, 1);

	// print_2d_int_array(data->place_holder_north, data->north_size);
	// print_2d_int_array(data->place_holder_west, data->west_size);
	// print_2d_int_array(data->place_holder_east, data->east_size);
	// print_2d_int_array(data->place_holder_south, data->north_size);

	// line = get_next_line(fd);
	// line = get_next_line(fd);
	return (true);
}
