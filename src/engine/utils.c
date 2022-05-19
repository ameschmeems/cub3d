/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:36 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/19 17:22:52 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	arr_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	out_of_bounds(t_data *data, int i, int j)
{
	int	retval;

	retval = 0;
	if (i < 0 || j < 0 || i > arr_len(data->map) - 1)
		retval = 1;
	else if (j > ft_strlen(data->map[i]) - 1)
		retval = 1;
	return (retval);
}
