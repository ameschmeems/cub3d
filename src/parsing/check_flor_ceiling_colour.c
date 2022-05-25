/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flor_ceiling_colour.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:17:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/18 18:32:25 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	check_rgb_line_util2(char *line, int i, int j)
{
	char	*temp;

	temp = ft_substr(line, j, i - j);
	if (ft_atoi(temp) > 255 || ft_atoi(temp) < 0)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (1);
}

int	check_rgb_line_util(char *line, int i)
{
	int		j;
	int		y;
	char	*temp;

	y = 0;
	while (line[i])
	{
		j = i;
		while (ft_isdigit(line[i]))
			i++;
		if (i - j > 3)
			return (-1);
		if (check_rgb_line_util2(line, i, j) == -1)
			return (-1);
		if (line[i] == 0 || line[i] == '\n')
			break ;
		if (y < 2 && line[i] != ',')
			return (-1);
		i++;
		y++;
	}
	return (y);
}

bool	check_rgb_line(char *line)
{
	int		i;
	int		y;
	int		j;
	char	*temp;

	i = 1;
	j = 1;
	y = 0;
	while (line[i] == ' ')
		i++;
	if (i - y == 0)
		return (false);
	y = check_rgb_line_util(line, i);
	if (y != 2)
		return (false);
	return (true);
}

int	get_colour(char *line)
{
	int		i;
	int		j;
	int		y;
	char	*temp;
	int		rgb;

	i = 1;
	rgb = 0;
	y = 0;
	while (line[i] && y < 3)
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (ft_isdigit(line[i]))
			i++;
		if (i - j - 1> 2)
			return (false);
		temp = ft_substr(line, j, i - j);
		rgb = (ft_atoi(temp) * pow(256, y)) + rgb;
		free(temp);
		i++;
		y++;
	}
	return (rgb);
}


bool	set_colour_f_and_c(char *line, t_data *data)
{
	if (line[0] == 'F')
	{
		if(!check_rgb_line(line))
			return (false);
		data->f_colour = get_colour(line);
	}
	else if (line[0] == 'C')
	{
		if(!check_rgb_line(line))
			return (false);
		data->c_colour = get_colour(line);
	}
	if (data->c_colour < 0)
		write(STDERR_FILENO, "Error!\n Ceiling colour isn't formatted right!\n", 47);
	if (data->f_colour < 0)
		write(STDERR_FILENO, "Error!\n Floor colour isn't formatted right!\n", 45);
	if (data->c_colour < 0 || data->f_colour < 0)
		return (false);
	return(true);
}
