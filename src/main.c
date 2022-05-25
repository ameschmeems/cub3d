/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:43:05 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/24 13:49:16 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init();
	render(data);
	mlx_hook(data->win, ON_DESTROY, 0, x_close, data);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	mlx_loop(data->mlx);
	return (0);
}
