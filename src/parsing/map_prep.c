#include "../../includes/cube3d.h"

char	**testing_map(void)
{
	char **map;
	char *line;
	int		i;

	i = 0;

	map = calloc(sizeof(char *) , 15);
	map[0] = ft_strdup("111111111 11111");
	map[1] = ft_strdup("100000001110001");
	map[2] = ft_strdup("100000000000001");
	map[3] = ft_strdup("100000011110001");
	map[4] = ft_strdup("100000011110001");
	map[5] = ft_strdup("100000011110001");
	map[6] = ft_strdup("100000000000001");
	map[7] = ft_strdup("100000010000111");
	map[8] = ft_strdup("1000000000001  ");
	map[9] = ft_strdup("100000000000111");
	map[10] = ft_strdup("100110000000001");
	map[11] = ft_strdup("100110000000001");
	map[12] = ft_strdup("100000000001111");
	map[13] = ft_strdup("100000000000001");
	map[14] = ft_strdup("111111111111111");
	return (map);
}

bool	check_for_surround_vertical(char **map, int x, int y)
{
	int	y_c;
	int	x_c;

	y_c = 0;
	while (y_c < y)
	{
		x_c = 0;
		while (x_c < x)
		{
			while (map[y_c][x_c] == ' ' && map[y_c][x_c] != 0)
				x_c++;
			if (map[y_c][x_c] == 0)
				break ;
			if (map[y_c][x_c] != '1')
				return (false);
			while (map[y_c][x_c] != ' ' && map[y_c][x_c] != 0)
				x_c++;
			if (map[y_c][x_c - 1] != '1')
				return (false);
		}
		y_c++;
	}
	return (true);
}

bool	check_for_surround_horizontal(char **map, int x, int y)
{
	int	y_c;
	int	x_c;

	x_c = 0;
	while (x_c < x)
	{
		y_c = 0;
		while (y_c < y)
		{
			while (y_c != y && map[y_c][x_c] == ' ')
				y_c++;
			
			if (y_c == y)
				break ;
			if (map[y_c][x_c] != '1')
				return (false);
			
			while (y_c != y && map[y_c][x_c] != ' ')
				y_c++; 
			if (map[y_c - 1][x_c] != '1')
				return (false);
		}
		x_c++;
	}
	return (true);
}

bool	set_colour(char *line, t_c3d_data *data)
{
	
}

bool	read_textures(t_c3d_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S' || line[0] == 'W')
		{
			load_texture(line, data);
			i++;
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			set_colour(line, data);
			i++;
		}
		else if (ft_strlen(line) > 0)
			return (false);
		line = get_next_line(fd);
	}
	if (i < 6)
		return (false);
	return (true);
}

bool	get_map(t_c3d_data *data, char *path_name)
{
	int	fd;

	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (read_textures(data, fd) == false)
		return (false);
}

int main()
{
	char ** map =testing_map();
	if (check_for_surround_vertical(map, 15,15) == true)
		printf("true\n");
	else
		printf("false\n");
	if (check_for_surround_horizontal(map, 15,15) == true)
		printf("true\n");
	else
		printf("false\n");
}