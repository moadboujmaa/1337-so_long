/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/25 08:19:10 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_ext(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (ft_strnstr(file_name, ".ber", len))
		return (1);
	return (0);
}

void	check_len(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			print_error("Not equal length");
		i++;
	}
}

void	check_chars(char **map, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(set, map[i][j]))
				print_error("Map contain undefined chars");
			j++;
		}
		i++;
	}
}

void	check_walls(char **map, int arr_len, int str_len)
{
	char	*first_wall;
	char	*last_wall;
	int		i;

	i = 0;
	first_wall = map[i];
	last_wall = map[arr_len - 1];
	while (first_wall[i])
	{
		if (first_wall[i] != WALL || last_wall[i] != WALL)
			print_error("Map not surrounded by walls");
		i++;
	}
	i = 1;
	while (map[i] && i < arr_len - 1)
	{
		if (map[i][0] != WALL || map[i][str_len - 1] != WALL)
			print_error("Map not surrounded by walls");
		i++;
	}
}
