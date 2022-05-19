#include "../../includes/cube3d.h"
#include <stdio.h>


bool	load_texture(char *line, t_data *data)
{
	return (true);
}

bool	read_textures(t_data *data, int fd)
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

bool	get_map(t_data *data, char *path_name)
{
	int	fd;

	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (read_textures(data, fd) == false)
		return (false);
	return (true);
}

