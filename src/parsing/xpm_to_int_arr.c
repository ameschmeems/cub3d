/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:00:33 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/20 11:21:40 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

bool	xpm_to_int_arr(char *path, int **arr)
{
	int		fd;
	char	*line;
	int		column;
	int		row;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return(error_message_bool(path + 2));
	line = get_next_line(fd);
	i = 0;	
	while ()
	
	
}
