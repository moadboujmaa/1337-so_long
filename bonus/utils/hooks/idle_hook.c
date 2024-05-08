/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:07:35 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/07 16:33:41 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	open_idle_textures(t_data *dt)
{
	dt->i_imgs.t_idle_1 = mlx_load_png("./bonus/textures/player/idle-1.png");
	dt->i_imgs.t_idle_2 = mlx_load_png("./bonus/textures/player/idle-2.png");
	dt->i_imgs.t_idle_3 = mlx_load_png("./bonus/textures/player/idle-3.png");
	dt->i_imgs.t_idle_4 = mlx_load_png("./bonus/textures/player/idle-4.png");
	dt->i_imgs.t_idle_5 = mlx_load_png("./bonus/textures/player/idle-5.png");
	dt->i_imgs.t_idle_6 = mlx_load_png("./bonus/textures/player/idle-6.png");
	dt->i_imgs.t_idle_7 = mlx_load_png("./bonus/textures/player/idle-7.png");
	dt->i_imgs.t_idle_8 = mlx_load_png("./bonus/textures/player/idle-8.png");
	dt->i_imgs.t_idle_9 = mlx_load_png("./bonus/textures/player/idle-9.png");
	dt->i_imgs.t_idle_10 = mlx_load_png("./bonus/textures/player/idle-10.png");
	if (!dt->i_imgs.t_idle_1 || !dt->i_imgs.t_idle_2 || !dt->i_imgs.t_idle_3
		|| !dt->i_imgs.t_idle_4 || !dt->i_imgs.t_idle_5
		|| !dt->i_imgs.t_idle_6 || !dt->i_imgs.t_idle_7
		|| !dt->i_imgs.t_idle_8 || !dt->i_imgs.t_idle_9
		|| !dt->i_imgs.t_idle_10)
		print_error_f(dt, "Loading idle PNGs");
	dt->i_imgs.idle_textures = 1;
}

static void	open_idle_images(t_data *dt)
{
	dt->i_imgs.idle_1 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_1);
	dt->i_imgs.idle_2 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_2);
	dt->i_imgs.idle_3 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_3);
	dt->i_imgs.idle_4 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_4);
	dt->i_imgs.idle_5 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_5);
	dt->i_imgs.idle_6 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_6);
	dt->i_imgs.idle_7 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_7);
	dt->i_imgs.idle_8 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_8);
	dt->i_imgs.idle_9 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_9);
	dt->i_imgs.idle_10 = mlx_texture_to_image(dt->mlx, dt->i_imgs.t_idle_10);
	if (!dt->i_imgs.idle_1 || !dt->i_imgs.idle_2 || !dt->i_imgs.idle_3
		|| !dt->i_imgs.idle_4 || !dt->i_imgs.idle_5
		|| !dt->i_imgs.idle_6 || !dt->i_imgs.idle_7
		|| !dt->i_imgs.idle_8 || !dt->i_imgs.idle_9
		|| !dt->i_imgs.idle_10)
		print_error_f(dt, "idle textures to image");
	dt->i_imgs.idle_images = 1;
	free_idle(&(dt->i_imgs));
}

static void	render_idle_frame(t_data *data, int x, int y, int frame)
{
	if (!data->i_imgs.idle_textures)
		open_idle_textures(data);
	if (!data->i_imgs.idle_images)
		open_idle_images(data);
	if (frame == 0)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_1, y * 64, x * 64);
	else if (frame == 1)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_2, y * 64, x * 64);
	else if (frame == 2)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_3, y * 64, x * 64);
	else if (frame == 3)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_4, y * 64, x * 64);
	else if (frame == 4)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_5, y * 64, x * 64);
	else if (frame == 5)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_6, y * 64, x * 64);
	else if (frame == 6)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_7, y * 64, x * 64);
	else if (frame == 7)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_8, y * 64, x * 64);
	else if (frame == 8)
		mlx_image_to_window(data->mlx, data->i_imgs.idle_9, y * 64, x * 64);
}

static void	get_character_position(t_data *data, int frame)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == PLAYER)
				render_idle_frame(data, i, j, frame);
			j++;
		}
		i++;
	}
}

void	idle_hook(void *param)
{
	static int	i;
	static int	j;
	t_data		*data;

	data = param;
	if (i == 7 && !data->is_over)
	{
		get_character_position(data, j);
		i = 0;
		j++;
		if (j == 9)
			j = 0;
	}
	i++;
}
