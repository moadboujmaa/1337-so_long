/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:36:50 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/07 10:44:30 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	open_flag_textures(t_data *dt)
{
	dt->f_imgs.t_flag_1 = mlx_load_png("./bonus/textures/door/flag-1.png");
	dt->f_imgs.t_flag_2 = mlx_load_png("./bonus/textures/door/flag-2.png");
	dt->f_imgs.t_flag_3 = mlx_load_png("./bonus/textures/door/flag-3.png");
	dt->f_imgs.t_flag_4 = mlx_load_png("./bonus/textures/door/flag-4.png");
	dt->f_imgs.t_flag_5 = mlx_load_png("./bonus/textures/door/flag-5.png");
	dt->f_imgs.t_flag_6 = mlx_load_png("./bonus/textures/door/flag-6.png");
	dt->f_imgs.t_flag_7 = mlx_load_png("./bonus/textures/door/flag-7.png");
	if (!dt->f_imgs.t_flag_1 || !dt->f_imgs.t_flag_2 || !dt->f_imgs.t_flag_3
		|| !dt->f_imgs.t_flag_4 || !dt->f_imgs.t_flag_5
		|| !dt->f_imgs.t_flag_6 || !dt->f_imgs.t_flag_7)
		print_error_f(dt, "Loading flag PNGs");
	dt->f_imgs.flag_textures = 1;
}

static void	open_flag_images(t_data *dt)
{
	dt->f_imgs.flag_1 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_1);
	dt->f_imgs.flag_2 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_2);
	dt->f_imgs.flag_3 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_3);
	dt->f_imgs.flag_4 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_4);
	dt->f_imgs.flag_5 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_5);
	dt->f_imgs.flag_6 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_6);
	dt->f_imgs.flag_7 = mlx_texture_to_image(dt->mlx, dt->f_imgs.t_flag_7);
	if (!dt->f_imgs.flag_1 || !dt->f_imgs.flag_2 || !dt->f_imgs.flag_3
		|| !dt->f_imgs.flag_4 || !dt->f_imgs.flag_5
		|| !dt->f_imgs.flag_6 || !dt->f_imgs.flag_7)
		print_error_f(dt, "flag textures to image");
	dt->f_imgs.flag_images = 1;
}

static void	render_flag_frame(t_data *data, int x, int y, int frame)
{
	if (!data->f_imgs.flag_textures)
		open_flag_textures(data);
	if (!data->f_imgs.flag_images)
		open_flag_images(data);
	if (frame == 0)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_1, y * 64, x * 64);
	else if (frame == 1)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_2, y * 64, x * 64);
	else if (frame == 2)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_3, y * 64, x * 64);
	else if (frame == 3)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_4, y * 64, x * 64);
	else if (frame == 4)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_5, y * 64, x * 64);
	else if (frame == 5)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_6, y * 64, x * 64);
	else if (frame == 6)
		mlx_image_to_window(data->mlx, data->f_imgs.flag_7, y * 64, x * 64);
}

void	flag_hook(void *param)
{
	static int	i;
	static int	j;
	t_data		*data;

	data = param;
	if (i == 8 && !data->is_over)
	{
		render_flag_frame(data, data->door_x, data->door_y, j);
		i = 0;
		j++;
		if (j == 7)
			j = 0;
	}
	i++;
}
