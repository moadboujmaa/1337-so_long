/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/11 12:00:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	set_background(t_data *data, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height)
		{
			mlx_put_pixel(img, i, j, 0x211F30FF);
			j++;
		}
		i++;
	}
}

void	end_page(t_data *data, int status)
{
	mlx_image_t		*img;
	int				pos_x;
	int				pos_y;

	img = mlx_new_image(data->mlx, data->width, data->height);
	if (!img)
		print_error_f(data, "new image");
	set_background(data, img);
	mlx_image_to_window(data->mlx, img, 0, 0);
	pos_x = (data->width - 316) / 2;
	pos_y = (data->height - 95) / 2;
	if (status == WIN)
		mlx_image_to_window(data->mlx, data->textures.win, pos_x, pos_y);
	else
		mlx_image_to_window(data->mlx, data->textures.lose, pos_x, pos_y);
}
