/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/09 14:11:38 by mboujama         ###   ########.fr       */
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

static void	move_horizontal(t_data *data, int x, int y)
{
	static int	i;

	printf("%d\n", i);
	if (i <= 3)
	{
		printf("%d\n", i);
		if (data->map[x][y + 1] != WALL)
		{
			data->map[x][y + 1] = ENEMY;
			data->map[x][y] = EMPTY;
			render_enemy_image(data, x, y, 'g');
			render_enemy_image(data, x, y + 1, 'e');
		}
		i++;
	}
	else
	{
		printf("%d\n", i);
		if (data->map[x][y - 1] != WALL)
		{
			data->map[x][y - 1] = ENEMY;
			data->map[x][y] = EMPTY;
			render_enemy_image(data, x, y, 'g');
			render_enemy_image(data, x, y - 1, 'e');
		}
		if (i == 6)
			i = 0;
		i++;
	}
}

static void	move_vertical(t_data *data, int x, int y)
{
	static int	i;

	printf("x = %d | y = %d\n", x, y);
	if (i <= 3)
	{
		printf("%d\n", i);
		if (data->map[x + 1][y] != WALL)
		{
			data->map[x + 1][y] = ENEMY;
			data->map[x][y] = EMPTY;
			render_enemy_image(data, x, y, 'g');
			render_enemy_image(data, x + 1, y, 'e');
		}
		i++;
	}
	else
	{
		printf("%d\n", i);
		if (data->map[x - 1][y] != WALL)
		{
			data->map[x - 1][y] = ENEMY;
			data->map[x][y] = EMPTY;
			render_enemy_image(data, x, y, 'g');
			render_enemy_image(data, x - 1, y, 'e');
		}
		if (i == 6)
			i = 0;
		i++;
	}
}

static void	random_direction(t_data *data, int x, int y)
{
	if (data->map[x][y - 1] != WALL || data->map[x][y + 1] != WALL)
		move_horizontal(data, x, y);
	else if (data->map[x - 1][y] != WALL || data->map[x + 1][y] != WALL)
		move_vertical(data, x, y);
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
