/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:00:20 by kpucylo           #+#    #+#             */
/*   Updated: 2021/11/20 23:54:57 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	size_t		i;
	char		*dup;

	size = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
	{
		return (NULL);
	}
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
