/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/27 16:18:09 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// todo: free data->map data->map_copy before exit

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!check_file_ext(argv[1]))
			print_error("File extension not supported");
		parse_map(&data, argv[1]);
		init_mlx(&data);
	}
	ft_2d_free(data.map);
	return (0);
}
