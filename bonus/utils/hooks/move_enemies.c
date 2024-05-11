/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/11 16:10:39 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static int	get_random(void)
{
	int	random_number;

	random_number = rand() % 4 + 1;
	return (random_number);
}

static void	render_enemy_image(t_data *data, int x, int y, t_old_pos pos)
{
	if (data->map[x][y] != WALL && data->map[x][y] != COIN
		&& data->map[x][y] != EXIT && data->map[x][y] != ENEMY
		&& data->map[x][y] != PLAYER)
	{
		mlx_image_to_window(data->mlx, data->textures.ground,
			pos.y * 64, pos.x * 64);
		mlx_image_to_window(data->mlx, data->textures.enemy,
			y * 64, x * 64);
		data->map[x][y] = ENEMY;
		data->map[pos.x][pos.y] = EMPTY;
	}
	else if (data->map[x][y] == PLAYER)
		end_game(data, LOSE);
}

// random number: TOP = 1; RIGHT = 2; DOWN = 3; LEFT = 4
static int	move(t_data *data, int *x, int *y)
{
	int			rand;
	t_old_pos	pos;

	pos.x = *x;
	pos.y = *y;
	rand = get_random();
	if (rand == 1)
		render_enemy_image(data, *x - 1, *y, pos);
	else if (rand == 2)
		return (render_enemy_image(data, *x, ++(*y), pos), 1);
	else if (rand == 3)
		render_enemy_image(data, ++(*x), *y, pos);
	else if (rand == 4)
		render_enemy_image(data, *x, *y - 1, pos);
	return (0);
}

void	move_enemies(void *param)
{
	t_data		*data;
	static int	time;
	int			i;
	int			j;

	data = param;
	if (time == 50 && !data->is_over)
	{
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == ENEMY)
				{
					move(data, &i, &j);
				}
				j++;
			}
			i++;
		}
		time = 0;
	}
	time++;
}
