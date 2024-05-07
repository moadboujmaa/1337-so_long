/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:24 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/07 09:42:36 by mboujama         ###   ########.fr       */
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

# define WIN		1
# define LOSE		0

typedef struct s_enemy_frames
{
	mlx_texture_t	*t_enemy_1;
	mlx_texture_t	*t_enemy_2;
	mlx_texture_t	*t_enemy_3;
	mlx_texture_t	*t_enemy_4;
	mlx_texture_t	*t_enemy_5;
	mlx_texture_t	*t_enemy_6;
	mlx_texture_t	*t_enemy_7;
	int				enemy_textures;
	mlx_image_t		*enemy_1;
	mlx_image_t		*enemy_2;
	mlx_image_t		*enemy_3;
	mlx_image_t		*enemy_4;
	mlx_image_t		*enemy_5;
	mlx_image_t		*enemy_6;
	mlx_image_t		*enemy_7;
	int				enemy_images;
}	t_enemy_frames;

typedef struct s_coin_frames
{
	mlx_texture_t	*t_coin_1;
	mlx_texture_t	*t_coin_2;
	mlx_texture_t	*t_coin_3;
	mlx_texture_t	*t_coin_4;
	mlx_texture_t	*t_coin_5;
	mlx_texture_t	*t_coin_6;
	mlx_texture_t	*t_coin_7;
	int				coin_textures;
	mlx_image_t		*coin_1;
	mlx_image_t		*coin_2;
	mlx_image_t		*coin_3;
	mlx_image_t		*coin_4;
	mlx_image_t		*coin_5;
	mlx_image_t		*coin_6;
	mlx_image_t		*coin_7;
	int				coin_images;
}	t_coin_frames;

typedef struct s_textures
{
	mlx_texture_t	*tground;
	mlx_texture_t	*tplayer;
	mlx_texture_t	*tenemy;
	mlx_texture_t	*tcoin;
	mlx_texture_t	*texit;
	mlx_texture_t	*ttop;
	mlx_texture_t	*tdown;
	mlx_texture_t	*tinside;
	mlx_texture_t	*tleft;
	mlx_texture_t	*tright;
	mlx_texture_t	*ttl;
	mlx_texture_t	*tdl;
	mlx_texture_t	*ttr;
	mlx_texture_t	*tdr;
	int				textures_done;
	mlx_image_t		*ground;
	mlx_image_t		*player;
	mlx_image_t		*enemy;
	mlx_image_t		*coin;
	mlx_image_t		*exit;
	mlx_image_t		*top;
	mlx_image_t		*down;
	mlx_image_t		*inside;
	mlx_image_t		*left;
	mlx_image_t		*right;
	mlx_image_t		*tl;
	mlx_image_t		*dl;
	mlx_image_t		*tr;
	mlx_image_t		*dr;
	int				images_done;
}	t_textures;


// c_imgs = coin_images
typedef struct s_data
{
	mlx_t			*mlx;
	int				map_fd;
	char			*tmp_map;
	char			**map;
	char			**map_copy;
	int				coins;
	int				player;
	int				exit;
	int				player_x;
	int				player_y;
	int				width;
	int				height;
	void			*mlx_win;
	int				movements;
	int				door_x;
	int				door_y;
	int				flag_started;
	int				is_over;
	t_coin_frames	c_imgs;
	t_enemy_frames	e_imgs;
	t_textures		textures;
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
void	display_map(t_data *data);

// utils/hooks
void	start_animation(t_data *data);
void	flag_hook(void *param);
void	coin_hook(void *param);
void	idle_hook(void *param);
void	enemy_hook(void *param);
void	move_enemies(void *param);

// utils/load_images
void	load_textures(t_data *dt);
void	load_images(t_data *dt);

void	lose(t_data *data);

// utils/start
void	call_map(mlx_key_data_t keydata, void *param);
void	welcome_page(t_data *data);

// end
void	end_page(t_data *data, int status);

// end_game
void	end_game(t_data *data, int status);

#endif
