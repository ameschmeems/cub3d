/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:26:55 by kpucylo           #+#    #+#             */
/*   Updated: 2021/11/26 14:46:49 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	front;
	size_t	back;
	char	*dest;

	if (!s1 && !set)
	{
		return (NULL);
	}
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
	{
		front++;
	}
	while (back && ft_strchr(set, s1[back - 1]) && back > front)
	{
		back--;
	}
	dest = malloc(sizeof(char) * (back - front + 1));
	if (!dest)
	{
		return (NULL);
	}
	ft_strlcpy(dest, s1 + front, back - front + 1);
	return (dest);
}
