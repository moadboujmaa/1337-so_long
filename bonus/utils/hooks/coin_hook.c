/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:00:39 by  mboujama         #+#    #+#             */
/*   Updated: 2024/04/30 22:01:50 by mboujama         ###   ########.fr       */
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
	printf("here\n");
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
	mlx_delete_texture(texture);
}

