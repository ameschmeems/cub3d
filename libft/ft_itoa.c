/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:47:08 by kpucylo           #+#    #+#             */
/*   Updated: 2021/11/21 00:03:04 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	long_n;

	len = int_len(n);
	long_n = n;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (long_n < 0)
	{
		result[0] = '-';
		long_n = -long_n;
	}
	else if (long_n == 0)
		result[0] = '0';
	while (long_n)
	{
		len--;
		result[len] = (long_n % 10) + '0';
		long_n /= 10;
	}
	return (result);
}
