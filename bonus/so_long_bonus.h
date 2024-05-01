/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:24 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/01 15:01:17 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../shared/libft/libft.h"
# include "../shared/MLX42/include/MLX42/MLX42.h"
# include <time.h>

# define COIN		67
# define PLAYER 	80
# define EXIT 		69
# define WALL		49
# define EMPTY		48
# define CHECKED	88
# define WIDTH		64
# define HEIGHT		64
# define ENEMY		90

typedef struct s_animations
{
	int	flag_i;
	int	flag_j;
}	t_animations;

typedef struct s_data
{
	int			map_fd;
	char		*tmp_map;
	char		**map;
	char		**map_copy;
	int			coins;
	int			player;
	int			exit;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	mlx_t		*mlx;
	void		*mlx_win;
	int			movements;
	int			door_x;
	int			door_y;
	int			flag_started;
	mlx_image_t	*img;
}	t_data;

// utils/parse_map
void	parse_map(t_data *data, char *file_name);

// utils/map_checks
int		check_file_ext(char *file_name);
void	check_len(t_data *data);
void	check_walls(t_data *data, int arr_len, int str_len);
void	check_chars(t_data *data, char *set);

// utils/map_checks_2
void	count_items(t_data *data);
void	check_routes(t_data *data, int x_po, int y_pos);
void	check_accessibility(t_data *data);

// utils/inti_mlx
void	init_mlx(t_data *data);

// utils/errors
void	print_error(char *str);
void	print_error_f(t_data *data, char *str);
void	free_program(t_data *data);

// utils/game_logic
void	handle_keys(mlx_key_data_t keydata, void *param);

// utils/hooks
void	start_animation(t_data *data);
void	flag_hook(void *param);
void	coin_hook(void *param);
void	idle_hook(void *param);
void	enemy_hook(void *param);
void	move_enemies(void *param);

void	lose(t_data *data);

#endif
