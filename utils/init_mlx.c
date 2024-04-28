/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/28 11:04:30 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_close(void *param)
{
	(void) param;
	printf("Good bye!!\n");
}

static mlx_texture_t	*choose_wall(t_data *data, int x, int y)
{
	mlx_texture_t	*texture;

	if (x == 0 && y == 0)
		texture = mlx_load_png("./imgs/walls/top_left.png");
	else if (x == 0 && y == data->width / 64 - 1)
		texture = mlx_load_png("./imgs/walls/top_right.png");
	else if (x == data->height / 64 - 1 && y == 0)
		texture = mlx_load_png("./imgs/walls/down_left.png");
	else if (x == data->height / 64 - 1 && y == data->width / 64 - 1)
		texture = mlx_load_png("./imgs/walls/down_right.png");
	else if (x == 0)
		texture = mlx_load_png("./imgs/walls/top.png");
	else if (y == 0)
		texture = mlx_load_png("./imgs/walls/left.png");
	else if (y == data->width / 64 - 1)
		texture = mlx_load_png("./imgs/walls/right.png");
	else if (x == data->height / 64 - 1)
		texture = mlx_load_png("./imgs/walls/down.png");
	else
		texture = mlx_load_png("./imgs/walls/inside.png");
	return (texture);
}

static mlx_texture_t	*create_texture(t_data *data, int x, int y)
{
	mlx_texture_t	*texture;
	char			pos;

	pos = data->map[x][y];
	if (pos == '1')
		texture = choose_wall(data, x, y);
	else if (pos == 'C')
		texture = mlx_load_png("./imgs/coins/coin-1.png");
	else if (pos == 'P')
		texture = mlx_load_png("./imgs/player/player.png");
	else if (pos == 'E')
		texture = mlx_load_png("./imgs/door/door_closed.png");
	else
		texture = mlx_load_png("./imgs/ground/ground.png");
	return (texture);
}

void	display_map(t_data *data)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				i;
	int				j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			texture = create_texture(data, i, j);
			if (!texture)
				print_error("loading PNG");
			img = mlx_texture_to_image(data->mlx, texture);
			if (!img)
				print_error("converting texture to image");
			mlx_image_to_window(data->mlx, img, j * WIDTH, i * HEIGHT);
			mlx_delete_image(data->mlx, data->img);
			j++;
		}
		i++;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "SO_LONG", 0);
	if (!data->mlx)
		print_error("Error initializing mlx window");
	mlx_close_hook(data->mlx, ft_close, NULL);
	display_map(data);
}
