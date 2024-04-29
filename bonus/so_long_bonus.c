/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 15:37:31 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		mlx_put_string(data.mlx, "Movements:    0", 10, 10);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
	}
	free_program(&data);
	return (0);
}
