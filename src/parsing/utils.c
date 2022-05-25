/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:57:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/23 13:34:54 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (c - 55);
}

int	u_hextoi(char	*hex)
{
	int		i;
	int		sign;
	int		out;
	char	*hex_dig;

	i = 0;
	sign = 1;
	out = 0;
	while (hex[i] == 32 || (hex[i] > 8 && hex[i] < 14))
		i++;
	if (hex[i] == '+' || hex[i] == '-')
		sign = (hex[i++] - 44) * -1;
	while ((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f')
		|| (hex[i] >= 'A' && hex[i] <= 'F'))
		out = (out * 16) + get_value(hex[i++]);
	return (out * sign);
}
