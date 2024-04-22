/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/22 05:46:57 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_data *data, char *file_name)
{
	char	*str;

	data->map_fd = open(file_name, O_RDONLY);
	if (data->map_fd == -1)
		print_error("Map file doesn't exist\n");
	str = get_next_line(data->map_fd);
	data->tmp_map = ft_strdup("");
	while (str)
	{
		data->tmp_map = ft_strjoin(data->tmp_map, str);
		free(str);
		str = get_next_line(data->map_fd);
	}
	data->map = ft_split(data->tmp_map, '\n');
	free(data->tmp_map);
	if (!check_len(data->map))
		print_error("Not equal length\n");
	if (!check_chars(data->map, "01PCE"))
		print_error("Map contain undefined chars\n");
	if (!check_walls(data->map, ft_arrsize(data->map), ft_strlen(data->map[0])))
		print_error("Map not surrounded by walls\n");
	if (!count_items(data))
		print_error("Invalid number of items\n");
}
