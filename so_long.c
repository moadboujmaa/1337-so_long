/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/28 12:31:28 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// todo: free data->map data->map_copy before exit
// void	handle_keys(mlx_key_data_t keydata, void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	if (keydata.key == MLX_KEY_W && keydata.action)
// 		printf("UP\n");
// 	else if (keydata.key == MLX_KEY_S && keydata.action)
// 		printf("DOWN\n");
// 	else if (keydata.key == MLX_KEY_A && keydata.action)
// 		printf("LEFT\n");
// 	else if (keydata.key == MLX_KEY_D && keydata.action)
// 		printf("RIGHT\n");
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!check_file_ext(argv[1]))
			print_error("File extension not supported");
		parse_map(&data, argv[1]);
		init_mlx(&data);
		mlx_key_hook(data.mlx, handle_keys, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
	}
	ft_2d_free(data.map);
	return (0);
}
