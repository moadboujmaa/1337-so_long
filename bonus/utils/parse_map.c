/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/09 10:52:02 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	open_file(t_data *data, char *file_name)
{
	data->map_fd = open(file_name, O_RDONLY);
	if (data->map_fd == -1)
		print_error("Map file doesn't exist");
	data->tmp_map = ft_strdup("");
}

void	parse_map(t_data *data, char *file_name)
{
	char	*str;

	open_file(data, file_name);
	str = get_next_line(data->map_fd);
	while (str)
	{
		if (str[0] == '\n')
			print_error("empty line in map");
		data->tmp_map = ft_strjoin(data->tmp_map, str);
		free(str);
		str = get_next_line(data->map_fd);
	}
	data->map = ft_split(data->tmp_map, '\n');
	data->map_copy = ft_split(data->tmp_map, '\n');
	free(data->tmp_map);
	check_len(data);
	check_chars(data, "01PCEZ");
	check_walls(data, ft_arrsize(data->map), ft_strlen(data->map[0]));
	count_items(data);
	check_routes(data, data->player_x, data->player_y);
	check_accessibility(data);
	data->width = ft_strlen(data->map[0]) * 64;
	data->height = ft_arrsize(data->map) * 64;
}
