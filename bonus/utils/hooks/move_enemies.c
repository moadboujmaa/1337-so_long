/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/06 10:36:35 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	render_enemy_image(t_data *data, int x, int y, char type)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = NULL;
	if (type == 'e')
		texture = mlx_load_png("./bonus/textures/enemies/enemy-1.png");
	else if (type == 'g')
		texture = mlx_load_png("./bonus/textures/ground/ground.png");
	img = mlx_texture_to_image(data->mlx, texture);
	if (!img)
		print_error_f(data, "Texture to image");
	mlx_image_to_window(data->mlx, img, y * 64, x * 64);
	mlx_delete_texture(texture);
}

static void	move(t_data *data, int x, int y)
{
	data->map[x][y] = 'Z';
	render_enemy_image(data, x, y, 'e');
}

static void	random_direction(t_data *data, int x, int y)
{
	if (data->map[x + 1][y] != WALL && data->map[x + 1][y] != EXIT)
		move(data, x + 1, y);
	else if (data->map[x][y + 1] != WALL && data->map[x][y + 1] != EXIT)
		move(data, x, y + 1);
	else if (data->map[x - 1][y] != WALL && data->map[x - 1][y] != EXIT)
		move(data, x - 1, y);
	else if (data->map[x][y - 1] != WALL && data->map[x][y - 1] != EXIT)
		move(data, x, y - 1);
	data->map[x][y] = '0';
	render_enemy_image(data, x, y, 'g');
	printf("x = %d | y =  %d\n", x, y);
}

void	move_enemies(void *param)
{
	t_data		*data;
	static int	time;
	int			i;
	int			j;

	i = 0;
	data = param;
	if (time == 70 && !data->is_over)
	{
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == ENEMY)
					random_direction(data, i, j);
				j++;
			}
			i++;
		}
		time = 0;
	}
	time++;
}
