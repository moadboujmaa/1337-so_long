/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/22 08:52:36 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// todo: free data->map before exit

void	check_l(void)
{
	system("leaks so_long");
}

// atexit(check_l);
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!check_file_ext(argv[1]))
			print_error("File extension not supported\n");
		init_map(&data, argv[1]);
	}
	ft_2d_free(data.map);
	return (0);
}
