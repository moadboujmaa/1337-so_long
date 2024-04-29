/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/28 21:20:13 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_map(t_data *data, char *file_name)
{
	char	*str;

	data->map_fd = open(file_name, O_RDONLY);
	if (data->map_fd == -1)
		print_error("Map file doesn't exist");
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
	free(data->tmp_map);
	check_len(data->map);
	check_chars(data->map, "01PCE");
	check_walls(data->map, ft_arrsize(data->map), ft_strlen(data->map[0]));
	count_items(data);
	check_routes(data, data->player_x, data->player_y);
	check_accessibility(data);
	data->width = ft_strlen(data->map[0]) * 64;
	data->height = ft_arrsize(data->map) * 64;
}