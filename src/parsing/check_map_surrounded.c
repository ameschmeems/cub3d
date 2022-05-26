/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surrounded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:19:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 12:48:23 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

bool	check_for_surround_horizontal(char **map)
{
	int	y_c;
	int	x_c;

	y_c = 0;
	while (map[y_c])
	{
		x_c = 0;
		while (map[y_c][x_c])
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

bool	check_for_surround_vertical(char **map)
{
	int	y_c;
	int	x_c;

	x_c = 0;
	print_2d_array(map, 1);
	while (map[0][x_c] != 0)
	{
		y_c = 0;
		while (map[y_c] != NULL)
		{
			while (map[y_c] && map[y_c][x_c] == ' ')
				y_c++;
			if (map[y_c] == NULL)
				break ;
			if (map[y_c][x_c] != '1')
				return (false);
			while (map[y_c] && map[y_c][x_c] != ' ')
				y_c++;
			if (map[y_c - 1][x_c] != '1')
				return (false);
		}
		x_c++;
	}
	return (true);
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
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
