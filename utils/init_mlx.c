/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/27 20:33:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_close(void *param)
{
	(void) param;
	printf("Good bye!!\n");
}

void	ft_scroll(double x, double y, void *param)
{
	(void) param;
	printf("x = %f | y = %f\n", x, y);
}

void	ft_keypress(void *param)
{
	t_data	*data;

	data = param;
	printf("x = %d - y = %d - width = %d\n", data->img->instances->x, data->img->instances->y, data->width);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) && data->img->instances->y > 0)
		data->img->instances->y -= 16;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && data->img->instances->y < data->height - 64)
		data->img->instances->y += 16;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && data->img->instances->x < data->width - 64)
		data->img->instances->x += 16;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && data->img->instances->x > 0)
		data->img->instances->x -= 16;
}

// void	display_image(t_data *data)
// {
// 	data->img = mlx_new_image(data->mlx, 64, 64);
// 	if (!data->img)
// 	{
// 		printf("error initialize data->img\n");
// 		return ;
// 	}
// 	memset(data->img->pixels, 255,
// 		data->img->width * data->img->height * sizeof(int32_t));
// 	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
// 	{
// 		printf("can't add image to window\n");
// 		return ;
// 	}
// }

void	display_image(t_data *data)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./imgs/wall.png");
	if (!texture)
	{
		printf("error texture\n");
		exit(1);
	}
	img = mlx_texture_to_image(data->mlx, texture);
	if (!img)
	{
		printf("error image\n");
		exit(1);
	}
	mlx_image_to_window(data->mlx, img, 0, 0);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "SO_LONG", 0);
	if (!data->mlx)
		print_error("Error initializing mlx window");
	mlx_close_hook(data->mlx, ft_close, data->mlx);
	mlx_scroll_hook(data->mlx, ft_scroll, data->mlx);
	display_image(data);
	printf("here\n");
	// mlx_loop_hook(data->mlx, ft_keypress, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
