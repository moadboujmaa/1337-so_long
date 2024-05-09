/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/09 14:14:17 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	check_l(void)
// {
// 	system("leaks so_long_bonus");
// }

int	main(int argc, char **argv)
{
	t_data	data;

	// atexit(check_l);
	if (argc == 2)
	{
		if (!check_file_ext(argv[1]))
			print_error("File extension not supported");
		ft_bzero(&data, sizeof(t_data));
		parse_map(&data, argv[1]);
		init_mlx(&data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
	}
	free_program(&data);
	return (0);
}
