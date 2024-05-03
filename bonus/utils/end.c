/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/03 15:49:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	end_page(t_data *data, int status)
{
	mlx_image_t		*img;
	mlx_image_t		*img2;
	mlx_texture_t	*texture;
	int				pos_x;
	int				pos_y;

	img = mlx_new_image(data->mlx, data->width, data->height);
	if (!img)
		print_error_f(data, "new image");
	set_background(data, &img);
	mlx_image_to_window(data->mlx, img, 0, 0);
	if (status == WIN)
		texture = mlx_load_png("./bonus/textures/additional/you_win.png");
	else
		texture = mlx_load_png("./bonus/textures/additional/you_lose.png");
	if (!texture)
		print_error_f(data, "Image not found");
	img2 = mlx_texture_to_image(data->mlx, texture);
	pos_x = (data->width - 241) / 2;
	pos_y = (data->height - 146) / 2;
	mlx_image_to_window(data->mlx, img2, pos_x, pos_y);
}
