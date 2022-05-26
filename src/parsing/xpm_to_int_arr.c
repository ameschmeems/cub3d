/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:00:33 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 14:40:58 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	*skip_lines_xpm(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line[0] != '"')
	{
		free(line);
		line = get_next_line(fd);
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
	data->code = ft_calloc(sizeof(char *), data->colours + 1);
	data->value = ft_calloc(sizeof(int), data->colours + 1);
}

void	fill_var_arrays(t_xpm_data *data, int fd)
{
	char	*line;
	int		i;

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

int	find_ind(char *line, t_xpm_data *tex_data)
{
	int	i;

	i = 0;
	while (i < tex_data->colours)
	{
		if (ft_strncmp(line, tex_data->code[i], tex_data->cpp) == 0)
			return (i);
		i++;
	}
	return (0);
}

int	**fill_texture_array(t_xpm_data *tex_data, int fd)
{
	int		y;
	int		x;
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
			out[y][x] = tex_data->value[find_ind(line + 1
					+ x * tex_data->cpp, tex_data)];
			x++;
		}
		y++;
		free(line);
	}
	return (out);
}
