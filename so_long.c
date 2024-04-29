/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 12:23:10 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free_program(&data);
	return (0);
}
