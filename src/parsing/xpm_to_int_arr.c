/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:00:33 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/25 15:37:36 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	*skip_lines_xpm(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line[0] != '"')
	{
		free(line);
		line =get_next_line(fd);
	}
	return (line);
}

void	fill_texture_size(char *line, t_xpm_data *data)
{
	char	**arr;

	arr = ft_split(line, ' ');
	data->size = ft_atoi(arr[0] + 1);
	if (ft_atoi(arr[1]) != data->size)
	{
		write(2, "Error\nTexture is not a square!\n", 32);
		data->size = -1;
		return ;
	}
	data->colours = ft_atoi(arr[2]);
	data->cpp = ft_atoi(arr[3]);
	free_2d_array(arr);
	free(line);
	data->code = ft_calloc(sizeof(char	*), data->colours + 1);
	data->value = ft_calloc(sizeof(int), data->colours +1 );
}

void	fill_var_arrays(t_xpm_data *data, int fd)
{
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	line = get_next_line(fd);
	while (i < data->colours)
	{
		data->code[i] = ft_strdup(line + 1);
		data->value[i] = u_hextoi(line + data->cpp + 5);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	print_int_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	printf("\nint array i == %d", i);
}

int	find_ind(char *line, t_xpm_data *tex_data)
{
	int	i;

	i = 0;
	while (i < tex_data->colours)
	{
		if (ft_strncmp(line, tex_data->code[i], 2) == 0)
			return (i);
		i++;
	}
	return (0);
}

int	**fill_texture_array(t_xpm_data *tex_data, t_data *data, int fd)
{
	int		y;
	int		x;
	int		ind;
	int		**out;
	char	*line;

	out = malloc(sizeof(int *) * tex_data->size);
	y = 0;
	while (y < tex_data->size)
	{
		line = get_next_line(fd);
		out[y] = malloc(sizeof(int) * tex_data->size);
		x = 0;
		while (x < tex_data->size)
		{
			out[y][x] = tex_data->value[find_ind(line + 1 + x * tex_data->cpp, tex_data)];
			x++;	
		}
		y++;
		free(line);
	}
	return (out);
}

void	print_2d_int_array(int **arr, int size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			printf("%d, ", arr[y][x]);
			x++;	
		}
		printf("\n");
		y++;
	}
}

void	free_2d_int_array(int **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);	
		i++;
	}
	free(arr);
}

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
	int	i;

	path += 2;
	while (path[0] == ' ')
		path++;
	path[ft_strlen(path) - 1] = 0;
	return (path);
}

bool	xpm_to_int_arr(char *path, char c, t_data *data)
{
	int			fd;
	char		*line;
	t_xpm_data	text_data;
	int			**arr;

	path = get_xpm_path(path);
	printf("XDLOL\n");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return(error_message_bool(path + 2, true));
	line = skip_lines_xpm(fd);
	fill_texture_size(line, &text_data);
	if (text_data.size == -1)
		return (false);
	fill_var_arrays(&text_data, fd);
	arr = fill_texture_array(&text_data, data, fd);
	printf("%p\n", text_data.value);
	free(text_data.value);
	free_2d_array(text_data.code);
	distribute_into_struct(c, text_data.size, arr, data);
	return (true);
}

// int main()
// {
// 	int **arr;
// 	t_data data;
// 	xpm_to_int_arr("./test.xpm", 'N', &data);
// 	free_2d_int_array(data.place_holder_north, data.north_size);
// }
