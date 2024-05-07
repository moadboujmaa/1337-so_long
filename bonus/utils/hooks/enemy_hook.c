/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:21:52 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/07 09:45:52 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	open_enemy_textures(t_data *dt)
{
	dt->e_imgs.t_enemy_1 = mlx_load_png("./bonus/textures/enemies/enemy-1.png");
	dt->e_imgs.t_enemy_2 = mlx_load_png("./bonus/textures/enemies/enemy-2.png");
	dt->e_imgs.t_enemy_3 = mlx_load_png("./bonus/textures/enemies/enemy-3.png");
	dt->e_imgs.t_enemy_4 = mlx_load_png("./bonus/textures/enemies/enemy-4.png");
	dt->e_imgs.t_enemy_5 = mlx_load_png("./bonus/textures/enemies/enemy-5.png");
	dt->e_imgs.t_enemy_6 = mlx_load_png("./bonus/textures/enemies/enemy-6.png");
	dt->e_imgs.t_enemy_7 = mlx_load_png("./bonus/textures/enemies/enemy-7.png");
	if (!dt->e_imgs.t_enemy_1 || !dt->e_imgs.t_enemy_2 || !dt->e_imgs.t_enemy_3
		|| !dt->e_imgs.t_enemy_4 || !dt->e_imgs.t_enemy_5
		|| !dt->e_imgs.t_enemy_6 || !dt->e_imgs.t_enemy_7)
		print_error_f(dt, "Loading enemy PNGs");
	dt->e_imgs.enemy_textures = 1;
}

static void	open_enemy_images(t_data *dt)
{
	dt->e_imgs.enemy_1 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_1);
	dt->e_imgs.enemy_2 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_2);
	dt->e_imgs.enemy_3 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_3);
	dt->e_imgs.enemy_4 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_4);
	dt->e_imgs.enemy_5 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_5);
	dt->e_imgs.enemy_6 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_6);
	dt->e_imgs.enemy_7 = mlx_texture_to_image(dt->mlx, dt->e_imgs.t_enemy_7);
	if (!dt->e_imgs.enemy_1 || !dt->e_imgs.enemy_2 || !dt->e_imgs.enemy_3
		|| !dt->e_imgs.enemy_4 || !dt->e_imgs.enemy_5
		|| !dt->e_imgs.enemy_6 || !dt->e_imgs.enemy_7)
		print_error_f(dt, "Enemy textures to image");
	dt->e_imgs.enemy_images = 1;
}


static void	render_enemy_frame(t_data *data, int x, int y, int frame)
{
	if (!data->e_imgs.enemy_textures)
		open_enemy_textures(data);
	if (!data->e_imgs.enemy_images)
		open_enemy_images(data);
	if (frame == 0)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_1, y * 64, x * 64);
	else if (frame == 1)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_2, y * 64, x * 64);
	else if (frame == 2)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_3, y * 64, x * 64);
	else if (frame == 3)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_4, y * 64, x * 64);
	else if (frame == 4)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_5, y * 64, x * 64);
	else if (frame == 5)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_6, y * 64, x * 64);
	else if (frame == 6)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_4, y * 64, x * 64);
	else if (frame == 7)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_5, y * 64, x * 64);
	else if (frame == 8)
		mlx_image_to_window(data->mlx, data->e_imgs.enemy_7, y * 64, x * 64);
}

static void	get_enemy_position(t_data *data, int frame)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ENEMY)
				render_enemy_frame(data, i, j, frame);
			j++;
		}
		i++;
	}
}

void	enemy_hook(void *param)
{
	static int	i;
	static int	j;
	t_data		*data;

	data = param;
	if (i == 9)
	{
		get_enemy_position(data, j);
		i = 0;
		j++;
		if (j == 9)
			j = 0;
	}
	i++;
}
