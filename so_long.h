/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:24 by  mboujama         #+#    #+#             */
/*   Updated: 2024/04/22 14:09:12 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>

# define COIN		67
# define PLAYER 	80
# define EXIT 		69
# define WALL		49
# define EMPTY		48
# define CHECKED	88

typedef struct s_data
{
	int		map_fd;
	char	*tmp_map;
	char	**map;
	char	**map_copy;
	int		coins;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		cols;
	int		rows;
}	t_data;

// utils/init_map
void	init_map(t_data *data, char *file_name);

// utils/map_checks
int		check_file_ext(char *file_name);
void	check_len(char **map);
void	check_walls(char **map, int arr_len, int str_len);
void	check_chars(char **map, char *set);

// utils/map_checks_2
void	count_items(t_data *data);
void	check_routes(t_data *data, int x_po, int y_pos);
void	print_map(char **map);
void	check_accessibility(t_data *data);

// utils/errors
void	print_error(char *str);

#endif
