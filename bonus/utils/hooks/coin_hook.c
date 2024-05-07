/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:00:39 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/07 13:33:19 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	open_coin_textures(t_data *dt)
{
	dt->c_imgs.t_coin_1 = mlx_load_png("./bonus/textures/coins/coin-1.png");
	dt->c_imgs.t_coin_2 = mlx_load_png("./bonus/textures/coins/coin-2.png");
	dt->c_imgs.t_coin_3 = mlx_load_png("./bonus/textures/coins/coin-3.png");
	dt->c_imgs.t_coin_4 = mlx_load_png("./bonus/textures/coins/coin-4.png");
	dt->c_imgs.t_coin_5 = mlx_load_png("./bonus/textures/coins/coin-5.png");
	dt->c_imgs.t_coin_6 = mlx_load_png("./bonus/textures/coins/coin-6.png");
	dt->c_imgs.t_coin_7 = mlx_load_png("./bonus/textures/coins/coin-7.png");
	if (!dt->c_imgs.t_coin_1 || !dt->c_imgs.t_coin_2 || !dt->c_imgs.t_coin_3
		|| !dt->c_imgs.t_coin_4 || !dt->c_imgs.t_coin_5
		|| !dt->c_imgs.t_coin_6 || !dt->c_imgs.t_coin_7)
		print_error_f(dt, "Loading coin PNG's");
	dt->c_imgs.coin_textures = 1;
}

static void	open_coin_images(t_data *dt)
{
	dt->c_imgs.coin_1 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_1);
	dt->c_imgs.coin_2 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_2);
	dt->c_imgs.coin_3 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_3);
	dt->c_imgs.coin_4 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_4);
	dt->c_imgs.coin_5 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_5);
	dt->c_imgs.coin_6 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_6);
	dt->c_imgs.coin_7 = mlx_texture_to_image(dt->mlx, dt->c_imgs.t_coin_7);
	if (!dt->c_imgs.coin_1 || !dt->c_imgs.coin_2 || !dt->c_imgs.coin_3
		|| !dt->c_imgs.coin_4 || !dt->c_imgs.coin_5
		|| !dt->c_imgs.coin_6 || !dt->c_imgs.coin_7)
		print_error_f(dt, "Coin texture to image");
	dt->c_imgs.coin_images = 1;
}

static void	render_coin_frame(t_data *data, int x, int y, int frame)
{
	if (!data->c_imgs.coin_textures)
		open_coin_textures(data);
	if (!data->c_imgs.coin_images)
		open_coin_images(data);
	if (frame == 0)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_1, y * 64, x * 64);
	else if (frame == 1)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_2, y * 64, x * 64);
	else if (frame == 2)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_3, y * 64, x * 64);
	else if (frame == 3)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_4, y * 64, x * 64);
	else if (frame == 4)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_5, y * 64, x * 64);
	else if (frame == 5)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_6, y * 64, x * 64);
	else if (frame == 6)
		mlx_image_to_window(data->mlx, data->c_imgs.coin_7, y * 64, x * 64);
}

static void	get_coin_position(t_data *data, int frame)
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
			if (data->map[i][j] == COIN)
				render_coin_frame(data, i, j, frame);
			j++;
		}
		i++;
	}
}

void	coin_hook(void *param)
{
	static int	i;
	static int	j;
	t_data		*data;

	data = param;
	if (i == 9)
	{
		get_coin_position(data, j);
		i = 0;
		j++;
		if (j == 7)
			j = 0;
	}
	i++;
}
