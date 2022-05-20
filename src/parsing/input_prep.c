#include "../../includes/cube3d.h"
#include <stdio.h>

bool	error_message_bool(char *line)
{
	write(2, "Error!\n", 8);
	perror(line);
	return (false);
}

bool	read_textures(char *line, void *storage)
{
	int		fd;
	char	*buf;

	fd = open(line +2, O_RDONLY);
	if (fd < 0)
		return (error_message_bool(line + 2));
	buf = get_next_line(fd);
	if
	while ()
	
}

bool	load_texture(char *line, t_data *data)
{
	if (line[0] == 'N')
		if(!read_textures(line, data->place_holder_north))
			return (false);
	else if (line[0] == 'E')
		if(!read_textures(line, data->place_holder_east))
			return (false);
	else if (line[0] == 'S')
		if(!read_textures(line, data->place_holder_south))
			return (false);
	else if (line[0] == 'W')
		if(!read_textures(line, data->place_holder_west))
			return (false);
	return (true);
}

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
			load_texture(line, data);
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

bool	get_input(t_data *data, char *path_name)
{
	int	fd;

	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (read_input_file(data, fd) == false)
	{
		printf("read_textures == false\n");
		return (false);
	}
	printf("read_textures == true\n");
	return (true);
}

