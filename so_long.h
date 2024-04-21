/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:24 by  mboujama         #+#    #+#             */
/*   Updated: 2024/04/21 16:33:20 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>

typedef struct s_data {
	int		map_fd;
	char	*tmp_map;
	char	**map;
}	t_data;

// utils/init_map
void	init_map(t_data *data, char *file_name);

// utils/map_checks
int		check_file_ext(char *file_name);
int		check_len(char **map);
int		check_walls(char **map, int arr_len, int str_len);

// utils/errors
void	print_error(char *str);

#endif
