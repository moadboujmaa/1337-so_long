/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/10 12:08:44 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	choose_image(t_data *data, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_image_to_window(data->mlx, data->textures.tl, y * 64, x * 64);
	else if (x == 0 && y == data->width / 64 - 1)
		mlx_image_to_window(data->mlx, data->textures.tr, y * 64, x * 64);
	else if (x == data->height / 64 - 1 && y == 0)
		mlx_image_to_window(data->mlx, data->textures.dl, y * 64, x * 64);
	else if (x == data->height / 64 - 1 && y == data->width / 64 - 1)
		mlx_image_to_window(data->mlx, data->textures.dr, y * 64, x * 64);
	else if (x == 0)
		mlx_image_to_window(data->mlx, data->textures.top, y * 64, x * 64);
	else if (y == 0)
		mlx_image_to_window(data->mlx, data->textures.left, y * 64, x * 64);
	else if (y == data->width / 64 - 1)
		mlx_image_to_window(data->mlx, data->textures.right, y * 64, x * 64);
	else if (x == data->height / 64 - 1)
		mlx_image_to_window(data->mlx, data->textures.down, y * 64, x * 64);
	else
		mlx_image_to_window(data->mlx, data->textures.inside, y * 64, x * 64);
}

void	put_image(t_data *data, int x, int y)
{
	char			pos;

	pos = data->map[x][y];
	if (pos == '1')
		choose_image(data, x, y);
	else if (pos == 'C')
		mlx_image_to_window(data->mlx, data->textures.coin, y * 64, x * 64);
	else if (pos == 'P')
		mlx_image_to_window(data->mlx, data->textures.player, y * 64, x * 64);
	else if (pos == 'E')
		mlx_image_to_window(data->mlx, data->textures.exit, y * 64, x * 64);
	else if (pos == 'Z')
		mlx_image_to_window(data->mlx, data->textures.enemy, y * 64, x * 64);
	else
		mlx_image_to_window(data->mlx, data->textures.ground, y * 64, x * 64);
}

void	display_map(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_image(data, i, j);
			j++;
		}
		i++;
	}
	mlx_loop_hook(data->mlx, coin_hook, data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "SO_LONG_BONUS", 1);
	if (!data->mlx)
		print_error("Error initializing mlx window");
	if (!data->textures.textures_done)
		load_textures(data);
	if (!data->textures.images_done)
		load_images(data);
	welcome_page(data);
	mlx_key_hook(data->mlx, call_map, data);
}
