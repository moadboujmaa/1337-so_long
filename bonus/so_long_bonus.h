/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:24 by  mboujama         #+#    #+#             */
/*   Updated: 2024/11/24 11:57:11 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../shared/libft/libft.h"
# include "../shared/include/MLX42.h"
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

typedef struct s_old_pos
{
	int	x;
	int	y;
}	t_old_pos;

typedef struct s_enemy_frames
{
	mlx_texture_t	*t_enemy_1;
	mlx_texture_t	*t_enemy_2;
	mlx_texture_t	*t_enemy_3;
	mlx_texture_t	*t_enemy_4;
	mlx_texture_t	*t_enemy_5;
	mlx_texture_t	*t_enemy_6;
	int				enemy_textures;
	mlx_image_t		*enemy_1;
	mlx_image_t		*enemy_2;
	mlx_image_t		*enemy_3;
	mlx_image_t		*enemy_4;
	mlx_image_t		*enemy_5;
	mlx_image_t		*enemy_6;
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

typedef struct s_flag_frames
{
	mlx_texture_t	*t_flag_1;
	mlx_texture_t	*t_flag_2;
	mlx_texture_t	*t_flag_3;
	mlx_texture_t	*t_flag_4;
	mlx_texture_t	*t_flag_5;
	mlx_texture_t	*t_flag_6;
	mlx_texture_t	*t_flag_7;
	int				flag_textures;
	mlx_image_t		*flag_1;
	mlx_image_t		*flag_2;
	mlx_image_t		*flag_3;
	mlx_image_t		*flag_4;
	mlx_image_t		*flag_5;
	mlx_image_t		*flag_6;
	mlx_image_t		*flag_7;
	int				flag_images;
}	t_flag_frames;

typedef struct s_rise_frames
{
	mlx_texture_t	*t_rise_1;
	mlx_texture_t	*t_rise_2;
	mlx_texture_t	*t_rise_3;
	mlx_texture_t	*t_rise_4;
	mlx_texture_t	*t_rise_5;
	mlx_texture_t	*t_rise_6;
	int				rise_textures;
	mlx_image_t		*rise_1;
	mlx_image_t		*rise_2;
	mlx_image_t		*rise_3;
	mlx_image_t		*rise_4;
	mlx_image_t		*rise_5;
	mlx_image_t		*rise_6;
	int				rise_images;
}	t_rise_frames;

typedef struct s_idle_frames
{
	mlx_texture_t	*t_idle_1;
	mlx_texture_t	*t_idle_2;
	mlx_texture_t	*t_idle_3;
	mlx_texture_t	*t_idle_4;
	mlx_texture_t	*t_idle_5;
	mlx_texture_t	*t_idle_6;
	mlx_texture_t	*t_idle_7;
	mlx_texture_t	*t_idle_8;
	mlx_texture_t	*t_idle_9;
	mlx_texture_t	*t_idle_10;
	int				idle_textures;
	mlx_image_t		*idle_1;
	mlx_image_t		*idle_2;
	mlx_image_t		*idle_3;
	mlx_image_t		*idle_4;
	mlx_image_t		*idle_5;
	mlx_image_t		*idle_6;
	mlx_image_t		*idle_7;
	mlx_image_t		*idle_8;
	mlx_image_t		*idle_9;
	mlx_image_t		*idle_10;
	int				idle_images;
}	t_idle_frames;

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
	mlx_texture_t	*twin;
	mlx_texture_t	*tlose;
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
	mlx_image_t		*win;
	mlx_image_t		*lose;
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
	char			*str;
	t_coin_frames	c_imgs;
	t_enemy_frames	e_imgs;
	t_flag_frames	f_imgs;
	t_idle_frames	i_imgs;
	t_rise_frames	r_imgs;
	t_textures		textures;
}	t_data;

// utils/parse_map
void	parse_map(t_data *data, char *file_name);

// utils/map_checks
int		check_file_ext(char *file_name);
void	check_len(t_data *data);
void	check_walls(t_data *data, int arr_len, int str_len);
void	check_chars(t_data *data, char *set);
void	check_display(t_data *data);

// utils/map_checks_2
void	count_items(t_data *data);
void	check_routes(t_data *data, int x_po, int y_pos);
void	check_accessibility(t_data *data);

// utils/init_mlx
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

// utils/hooks/free_textures
void	free_coins(t_coin_frames *c_imgs);
void	free_enemy(t_enemy_frames *e_imgs);
void	free_flag(t_flag_frames *f_imgs);
void	free_rise(t_rise_frames *r_imgs);
void	free_idle(t_idle_frames *i_imgs);
void	free_textures(t_textures *t_imgs);

// end
void	end_page(t_data *data, int status);
void	end_game(t_data *data, int status);

#endif
