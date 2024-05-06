/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:21:52 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/06 11:16:11 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	render_enemy_frame(t_data *data, int x, int y, int frame)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = NULL;
	if (frame == 0)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-1.png");
	else if (frame == 1)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-2.png");
	else if (frame == 2)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-3.png");
	else if (frame == 3)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-4.png");
	else if (frame == 4)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-5.png");
	else if (frame == 5)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-6.png");
	else if (frame == 6)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-4.png");
	else if (frame == 7)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-5.png");
	else if (frame == 8)
		texture = mlx_load_png("./bonus/textures/enemies/enemy-7.png");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
	mlx_delete_texture(texture);
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
