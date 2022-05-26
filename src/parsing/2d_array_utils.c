/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:57:43 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/26 16:59:31 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	print_2d_array(char	**arr, int fd)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			ft_putstr_fd(arr[i], fd);
			if (arr[i][ft_strlen(arr[i]) - 1] != '\n')
				ft_putstr_fd("\'\n", fd);
			else
				ft_putstr_fd("\'", fd);
			i++;
		}
	}
}

void	free_2d_array(char	**arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

bool	error_message_bool(char *line, bool err)
{
	write(2, "Error!\n", 8);
	if (err == true)
		perror(line);
	else
		write(2, line, ft_strlen(line));
	return (false);
}

char	**add_after_string(char **arr, char *new_el)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (arr[i])
		i++;
	temp = ft_calloc((sizeof(char *)), i + 2);
	j = 0;
	while (arr[j])
	{
		temp[j] = arr[j];
		j++;
	}
	temp[j] = new_el;
	free(arr);
	return (temp);
}

void	free_2d_int_array(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
