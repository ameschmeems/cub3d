/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surrounded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:19:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/24 15:45:29 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

bool	check_for_surround_vertical(char **map)
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
			{
				printf("hello '%s'", map[y_c]);
				printf("case 1: %d %d\n", x_c, y_c);
				return (false);
			}
			while (map[y_c][x_c] != ' ' && map[y_c][x_c] != 0)
				x_c++;
			if (map[y_c][x_c - 1] != '1')
			{
				printf("case 2: %d %d\n", x_c, y_c);
					return (false);
			}
		}
		y_c++;
	}
	return (true);
}

bool	check_for_surround_horizontal(char **map)
{
	int	y_c;
	int	x_c;

	x_c = 0;
	while (map[0][x_c] != 0)
	{
		y_c = 0;
		while (map[y_c] != NULL)
		{
			while (map[y_c] && map[y_c][x_c] == ' ')
				y_c++;
			if (map[y_c])
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

// bool	check_for_illegal_characters(char **map, int x, int y)
// {
	
// }