/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:43:00 by kpucylo           #+#    #+#             */
/*   Updated: 2021/11/17 13:26:30 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else if (dest > src)
	{
		while (n--)
		{
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}
