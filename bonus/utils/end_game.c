/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:16:19 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/03 15:54:31 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long_bonus.h"

static void	reset(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	end_game(t_data *data, int status)
{
	reset(data);
	data->player_x = 0;
	data->player_y = 0;
	data->map[0][0] = PLAYER;
	end_page(data, status);
}