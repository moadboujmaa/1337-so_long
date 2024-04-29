/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 13:52:08 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_file_ext(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (ft_strnstr(file_name, ".ber", len))
		return (1);
	return (0);
}

void	check_len(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
			print_error_f(data, "Not equal length");
		i++;
	}
}

void	check_chars(t_data *data, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr(set, data->map[i][j]))
				print_error_f(data, "Map contain undefined chars");
			j++;
		}
		i++;
	}
}

void	check_walls(t_data *data, int arr_len, int str_len)
{
	char	*first_wall;
	char	*last_wall;
	int		i;

	i = 0;
	first_wall = data->map[i];
	last_wall = data->map[arr_len - 1];
	while (first_wall[i])
	{
		if (first_wall[i] != WALL || last_wall[i] != WALL)
			print_error_f(data, "Map not surrounded by walls");
		i++;
	}
	i = 1;
	while (data->map[i] && i < arr_len - 1)
	{
		if (data->map[i][0] != WALL || data->map[i][str_len - 1] != WALL)
			print_error_f(data, "Map not surrounded by walls");
		i++;
	}
}
