/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 10:19:00 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_map(t_data *data, char *file_name)
{
	char	*str;

	data->map_fd = open(file_name, O_RDONLY);
	if (data->map_fd == -1)
		print_error(NULL, "Map file doesn't exist");
	str = get_next_line(data->map_fd);
	data->tmp_map = ft_strdup("");
	while (str)
	{
		data->tmp_map = ft_strjoin(data->tmp_map, str);
		free(str);
		str = get_next_line(data->map_fd);
	}
	data->map = ft_split(data->tmp_map, '\n');
	data->map_copy = ft_split(data->tmp_map, '\n');
	// while (1);
	// ft_2d_free(data->map);
	// ft_2d_free(data->map_copy);
	free(data->tmp_map);
	check_len(data);
	check_chars(data, "01PCE");
	check_walls(data, ft_arrsize(data->map), ft_strlen(data->map[0]));
	count_items(data);
	check_routes(data, data->player_x, data->player_y);
	check_accessibility(data);
	data->width = ft_strlen(data->map[0]) * 64;
	data->height = ft_arrsize(data->map) * 64;
}
