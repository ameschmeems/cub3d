/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:35:07 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/27 13:37:11 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	*init_double_check(t_checking_doubles *datas, int fd)
{
	char	*line;

	datas->east = false;
	datas->north = false;
	datas->west = false;
	datas->south = false;
	datas->floor = false;
	datas->ceiling = false;
	datas->doubles = false;
	line = get_next_line(fd);
	return (line);
}

void	check_for_doubles_util(bool *check, t_checking_doubles *data)
{
	if (*check == true)
		data->doubles = true;
	else
		*check = true;
}

bool	check_for_doubles(int fd)
{
	char				*line;
	t_checking_doubles	check;

	line = init_double_check(&check, fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			check_for_doubles_util(&check.north, &check);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			check_for_doubles_util(&check.south, &check);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			check_for_doubles_util(&check.west, &check);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			check_for_doubles_util(&check.east, &check);
		else if (ft_strncmp(line, "F ", 2) == 0)
			check_for_doubles_util(&check.floor, &check);
		else if (ft_strncmp(line, "C ", 2) == 0)
			check_for_doubles_util(&check.ceiling, &check);
		free(line);
		if (check.doubles == true)
			return (false);
		line = get_next_line(fd);
	}
	return (close(fd) + 1);
}
