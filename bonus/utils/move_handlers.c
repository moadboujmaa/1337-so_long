/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:55:18 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/07 12:06:45 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	get_door_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == EXIT)
			{
				data->door_x = i;
				data->door_y = j;
			}
			j++;
		}
		i++;
	}
}

static void	render_image(t_data *data, int x, int y, char type)
{
	if (type == 'g')
		mlx_image_to_window(data->mlx, data->textures.ground, y * 64, x * 64);
	else if (type == 'p')
		mlx_image_to_window(data->mlx, data->textures.player, y * 64, x * 64);
	else if (type == 'o')
		mlx_image_to_window(data->mlx, data->textures.exit, y * 64, x * 64);
	else if (type == 'a')
		mlx_image_to_window(data->mlx, data->textures.tl, y * 64, x * 64);
	else if (type == 'b')
		mlx_image_to_window(data->mlx, data->textures.top, y * 64, x * 64);
}

static void	count_move(t_data *data)
{
	data->movements++;
	render_image(data, 0, 0, 'a');
	render_image(data, 0, 1, 'b');
	render_image(data, 0, 2, 'b');
	mlx_put_string(data->mlx, "Movements: ", 10, 10);
	mlx_put_string(data->mlx, ft_itoa(data->movements), 140, 10);
}

static void	move_player(t_data *data, int x, int y)
{
	if (!data->is_over)
	{
		if (data->map[x][y] == ENEMY)
			end_game(data, LOSE);
		if (data->map[x][y] != WALL && data->map[x][y] != EXIT
				&& !data->is_over)
		{
			if (data->map[x][y] == COIN)
				data->coins--;
			get_door_pos(data);
			data->map[data->player_x][data->player_y] = '0';
			data->map[x][y] = 'P';
			render_image(data, x, y, 'p');
			render_image(data, data->player_x, data->player_y, 'g');
			data->player_x = x;
			data->player_y = y;
			count_move(data);
		}
		if (data->map[x][y] == EXIT && data->coins == 0)
			end_game(data, WIN);
		if (!data->flag_started)
			start_animation(data);
	}
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action)
		move_player(data, data->player_x - 1, data->player_y);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action)
		move_player(data, data->player_x + 1, data->player_y);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action)
		move_player(data, data->player_x, data->player_y - 1);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}
