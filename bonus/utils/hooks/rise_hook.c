/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rise_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:36:50 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/09 11:13:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	open_rise_textures(t_data *dt)
{
	dt->r_imgs.t_rise_1 = mlx_load_png("./bonus/textures/door/rise-1.png");
	dt->r_imgs.t_rise_2 = mlx_load_png("./bonus/textures/door/rise-2.png");
	dt->r_imgs.t_rise_3 = mlx_load_png("./bonus/textures/door/rise-3.png");
	dt->r_imgs.t_rise_4 = mlx_load_png("./bonus/textures/door/rise-4.png");
	dt->r_imgs.t_rise_5 = mlx_load_png("./bonus/textures/door/rise-5.png");
	dt->r_imgs.t_rise_6 = mlx_load_png("./bonus/textures/door/rise-6.png");
	if (!dt->r_imgs.t_rise_1 || !dt->r_imgs.t_rise_2 || !dt->r_imgs.t_rise_3
		|| !dt->r_imgs.t_rise_4 || !dt->r_imgs.t_rise_5
		|| !dt->r_imgs.t_rise_6)
		print_error_f(dt, "Loading rise PNGs");
	dt->r_imgs.rise_textures = 1;
}

static void	open_rise_images(t_data *dt)
{
	dt->r_imgs.rise_1 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_1);
	dt->r_imgs.rise_2 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_2);
	dt->r_imgs.rise_3 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_3);
	dt->r_imgs.rise_4 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_4);
	dt->r_imgs.rise_5 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_5);
	dt->r_imgs.rise_6 = mlx_texture_to_image(dt->mlx, dt->r_imgs.t_rise_6);
	if (!dt->r_imgs.rise_1 || !dt->r_imgs.rise_2 || !dt->r_imgs.rise_3
		|| !dt->r_imgs.rise_4 || !dt->r_imgs.rise_5
		|| !dt->r_imgs.rise_6)
		print_error_f(dt, "rise textures to image");
	dt->r_imgs.rise_images = 1;
	free_rise(&(dt->r_imgs));
}

static void	render_rise_frame(t_data *data, int x, int y, int frame)
{
	if (!data->r_imgs.rise_textures)
		open_rise_textures(data);
	if (!data->r_imgs.rise_images)
		open_rise_images(data);
	if (frame == 0)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_1, y * 64, x * 64);
	else if (frame == 1)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_2, y * 64, x * 64);
	else if (frame == 2)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_3, y * 64, x * 64);
	else if (frame == 3)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_4, y * 64, x * 64);
	else if (frame == 4)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_5, y * 64, x * 64);
	else if (frame == 5)
		mlx_image_to_window(data->mlx, data->r_imgs.rise_6, y * 64, x * 64);
}

static void	rise_hook(void *param)
{
	static int	i;
	static int	j;
	static int	is_out;
	t_data		*data;

	data = param;
	if (i == 8 && !is_out && !data->is_over)
	{
		render_rise_frame(data, data->door_x, data->door_y, j);
		i = 0;
		j++;
		if (j == 7)
		{
			mlx_loop_hook(data->mlx, flag_hook, data);
			is_out = 1;
			j = 0;
		}
	}
	i++;
}

void	start_animation(t_data *data)
{
	if (data->coins == 0 && !data->flag_started)
	{
		mlx_loop_hook(data->mlx, rise_hook, data);
		data->flag_started = 1;
	}
}
