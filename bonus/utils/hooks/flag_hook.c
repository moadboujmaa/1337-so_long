/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:36:50 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/01 06:03:16 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	render_flag_frame(t_data *data, int x, int y, int frame)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = NULL;
	if (frame == 0)
		texture = mlx_load_png("./bonus/textures/door/flag-1.png");
	else if (frame == 1)
		texture = mlx_load_png("./bonus/textures/door/flag-2.png");
	else if (frame == 2)
		texture = mlx_load_png("./bonus/textures/door/flag-3.png");
	else if (frame == 3)
		texture = mlx_load_png("./bonus/textures/door/flag-4.png");
	else if (frame == 4)
		texture = mlx_load_png("./bonus/textures/door/flag-5.png");
	else if (frame == 5)
		texture = mlx_load_png("./bonus/textures/door/flag-6.png");
	else if (frame == 6)
		texture = mlx_load_png("./bonus/textures/door/flag-7.png");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
	mlx_delete_texture(texture);
}

void	flag_hook(void *param)
{
	static int	i;
	static int	j;
	t_data		*data;

	data = param;
	if (i == 10)
	{
		render_flag_frame(data, data->door_x, data->door_y, j);
		i = 0;
		j++;
		if (j == 7)
			j = 0;
	}
	i++;
}

void	start_animation(t_data *data)
{
	if (data->coins == 0 && data->flag_started)
	{
		mlx_loop_hook(data->mlx, flag_hook, data);
		data->flag_started = 0;
	}
}
