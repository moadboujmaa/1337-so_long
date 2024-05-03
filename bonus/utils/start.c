/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/02 17:10:47 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_close(void *param)
{
	(void) param;
	ft_printf("Good bye!!\n");
}

void	call_map(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	(void) data;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		printf("here\n");
		display_map(data);
		mlx_loop_hook(data->mlx, idle_hook, data);
		mlx_loop_hook(data->mlx, enemy_hook, data);
		mlx_key_hook(data->mlx, handle_keys, data);
		mlx_put_string(data->mlx, "Movements:   0", 10, 10);
	}
}

static void	set_background(t_data *data, mlx_image_t **img)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height)
		{
			mlx_put_pixel(*img, i, j, 0x211F30FF);
			j++;
		}
		i++;
	}
}

void	welcome_page(t_data *data)
{
	mlx_image_t		*img;
	mlx_image_t		*img2;
	mlx_texture_t	*texture;
	int				pos_x;
	int				pos_y;

	img = mlx_new_image(data->mlx, data->width, data->height);
	if (!img)
		print_error_f(data, "new image");
	mlx_close_hook(data->mlx, ft_close, NULL);
	set_background(data, &img);
	mlx_image_to_window(data->mlx, img, 0, 0);
	texture = mlx_load_png("./bonus/textures/additional/welcome.png");
	img2 = mlx_texture_to_image(data->mlx, texture);
	pos_x = (data->width - 241) / 2;
	pos_y = (data->height - 146) / 2;
	mlx_image_to_window(data->mlx, img2, pos_x, pos_y);
}
