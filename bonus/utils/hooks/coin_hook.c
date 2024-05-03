/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:00:39 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/03 13:11:20 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	render_coin_frame(t_data *data, int x, int y, int frame)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = NULL;
	if (frame == 0)
		texture = mlx_load_png("./bonus/textures/coins/coin-1.png");
	else if (frame == 1)
		texture = mlx_load_png("./bonus/textures/coins/coin-2.png");
	else if (frame == 2)
		texture = mlx_load_png("./bonus/textures/coins/coin-3.png");
	else if (frame == 3)
		texture = mlx_load_png("./bonus/textures/coins/coin-4.png");
	else if (frame == 4)
		texture = mlx_load_png("./bonus/textures/coins/coin-5.png");
	else if (frame == 5)
		texture = mlx_load_png("./bonus/textures/coins/coin-6.png");
	else if (frame == 6)
		texture = mlx_load_png("./bonus/textures/coins/coin-7.png");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
	mlx_delete_texture(texture);
}

static void	get_coin_position(t_data *data, int frame)
{
	int	i;
	int	j;

	i = 0;
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
