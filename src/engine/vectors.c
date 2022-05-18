/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:59:20 by kpucylo           #+#    #+#             */
/*   Updated: 2022/05/18 15:23:43 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_vector(t_vector *dir, double len)
{
	double	v;
	double	f;

	v = sqrt(dir->x * dir->x + dir->y * dir->y);
	f = len / v;
	dir->x *= f;
	dir->y *= f;
}
