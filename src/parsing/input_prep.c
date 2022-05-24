#include "../../includes/cube3d.h"
#include <stdio.h>

bool	error_message_bool(char *line)
{
	write(2, "Error!\n", 8);
	perror(line);
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
			xpm_to_int_arr(line, line[0], data);
			i++;
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			set_colour_f_and_c(line, data);
			i++;
		}
		else if (ft_strlen(line) > 1)
			return (false);
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
	char	*out;
	int		i;

	if (ft_strlen(line) > size)
	{
		line[size] = 0;
		return (line);
	}
	else
	{
		out = ft_calloc(sizeof(char), size + 1);
		ft_strlcpy(out, line, size);
		i = ft_strlen(out) - 1;
		while (i < size)
			out[i++] = ' ';
		free(line);
	}
	return (out);
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
	
	check_ma
	printf("map:%p\n", map[0]);
	print_map(map, 1);
	data->map = map;
	return true;
}



bool	get_input(t_data *data, char *path_name)
{
	int	fd;
	char *line;

	fd = open(path_name, O_RDONLY);
	if (fd < 0)
	{

		return (false);
	}
	if (read_input_file(data, fd) == false)
	{
		printf("Error!\n.cub file not properly formated!\n");
		// printf("read_textures == false\n");
		return (false);
	}
	// get_map();
	printf("read_textures == true\n");
	// print_2d_int_array(data->place_holder_north, data->north_size);
	// print_2d_int_array(data->place_holder_west, data->west_size);
	// print_2d_int_array(data->place_holder_east, data->east_size);
	// print_2d_int_array(data->place_holder_south, data->north_size);
	read_map(fd, data);
	print_map(data->map, 1);



	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// printf("%s",line);
	return (true);
}
