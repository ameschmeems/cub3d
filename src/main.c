/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:43:05 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/25 19:46:24 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (write(2, "Error!\nNot the right amount of Arguments!\n", 43));
	data = init(argv[1]);
	if (data == NULL)
		return (1);
	render(data);
	mlx_hook(data->win, ON_DESTROY, 0, x_close, data);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	mlx_loop(data->mlx);
	return (0);
}
