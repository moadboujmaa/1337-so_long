/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:51 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/20 16:26:16 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_data *data, char *file_name)
{
	int		fd;
	char	*str;

	(void) data;
	fd = open(ft_strjoin("./maps/", file_name), O_RDONLY);
	if (fd == -1)
		return ;
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
	}
}
