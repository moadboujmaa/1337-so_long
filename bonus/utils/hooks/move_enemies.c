/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/07 13:13:24 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	render_enemy_image(t_data *data, int x, int y, char type)
{
	if (type == 'e')
		mlx_image_to_window(data->mlx, data->textures.enemy, y * 64, x * 64);
	else if (type == 'g')
		mlx_image_to_window(data->mlx, data->textures.ground, y * 64, x * 64);
}

static void	move(t_data *data, int x, int y)
{
	data->map[x][y] = 'Z';
	render_enemy_image(data, x, y, 'e');
}

static void	random_direction(t_data *data, int x, int y)
{
	if (data->map[x + 1][y] != WALL && data->map[x + 1][y] != EXIT)
		move(data, x + 1, y);
	else if (data->map[x][y + 1] != WALL && data->map[x][y + 1] != EXIT)
		move(data, x, y + 1);
	else if (data->map[x - 1][y] != WALL && data->map[x - 1][y] != EXIT)
		move(data, x - 1, y);
	else if (data->map[x][y - 1] != WALL && data->map[x][y - 1] != EXIT)
		move(data, x, y - 1);
	data->map[x][y] = '0';
	render_enemy_image(data, x, y, 'g');
	printf("x = %d | y =  %d\n", x, y);
}

void	move_enemies(void *param)
{
	t_data		*data;
	static int	time;
	int			i;
	int			j;

	i = 0;
	data = param;
	if (time == 70 && !data->is_over)
	{
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == ENEMY)
					random_direction(data, i, j);
				j++;
			}
			i++;
		}
		time = 0;
	}
	time++;
}
