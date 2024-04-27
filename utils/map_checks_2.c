/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/25 08:19:22 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_items(t_data *data)
{
	int	i;
	int	j;

	data->coins = 0;
	data->player = 0;
	data->exit = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == PLAYER)
			{
				data->player_x = i;
				data->player_y = j;
			}
			j++;
		}
		i++;
	}
}

void	count_items(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	init_items(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == COIN)
				data->coins++;
			else if (data->map[i][j] == PLAYER)
				data->player++;
			else if (data->map[i][j] == EXIT)
				data->exit++;
			j++;
		}
		i++;
	}
	if (data->coins < 1 || data->exit != 1 || data->player != 1)
		print_error("Invalid number of items");
}

int	count_coins(t_data *data)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == COIN)
				coins++;
			j++;
		}
		i++;
	}
	if (data->coins != coins)
		return (0);
	return (1);
}

void	check_routes(t_data *data, int x_pos, int y_pos)
{
	char	pos;

	pos = data->map_copy[x_pos][y_pos];
	if (pos == WALL || pos == CHECKED)
		return ;
	data->map_copy[x_pos][y_pos] = CHECKED;
	check_routes(data, x_pos + 1, y_pos);
	check_routes(data, x_pos, y_pos - 1);
	check_routes(data, x_pos, y_pos + 1);
	check_routes(data, x_pos - 1, y_pos);
}

void	check_accessibility(t_data *data)
{
	int	i;
	int	j;
	int	coins;
	int	exit;

	i = 0;
	coins = 0;
	exit = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == COIN)
				coins++;
			else if (data->map_copy[i][j] == EXIT)
				exit++;
			j++;
		}
		i++;
	}
	if (exit > 0 || coins > 0)
		print_error("You can't reach some coins or the exit in this map");
}
