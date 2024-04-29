/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:55:18 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/28 18:18:41 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = NULL;
	if (type == 'g')
		texture = mlx_load_png("./imgs/ground/ground.png");
	else if (type == 'p')
		texture = mlx_load_png("./imgs/player/player.png");
	else if (type == 'o')
		texture = mlx_load_png("./imgs/door/door_opened.png");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
}

static void	move_player(t_data *data, int x, int y)
{
	if (data->map[x][y] != WALL && data->map[x][y] != EXIT)
	{
		if (data->map[x][y] == COIN)
			data->coins--;
		if (data->coins == 0)
		{
			get_door_pos(data);
			render_image(data, data->door_x, data->door_y, 'o');
		}
		data->map[data->player_x][data->player_y] = '0';
		data->map[x][y] = 'P';
		render_image(data, x, y, 'p');
		render_image(data, data->player_x, data->player_y, 'g');
		data->player_x = x;
		data->player_y = y;
		data->movements += 1;
		ft_printf("%d %d\n", data->movements, data->coins);
	}
	if (data->map[x][y] == EXIT && data->coins == 0)
	{
		ft_printf("You won!!\n");
		mlx_close_window(data->mlx);
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
