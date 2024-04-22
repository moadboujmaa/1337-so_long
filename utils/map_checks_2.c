
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/22 05:30:42 by mboujama         ###   ########.fr       */
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

int	count_items(t_data *data)
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
		return (0);
	return (1);
}
