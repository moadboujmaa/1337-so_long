/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/08 11:19:26 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_textures(t_data *dt)
{
	dt->textures.tground = mlx_load_png("./bonus/textures/ground/ground.png");
	dt->textures.tplayer = mlx_load_png("./bonus/textures/player/player.png");
	dt->textures.tenemy = mlx_load_png("./bonus/textures/enemies/enemy.png");
	dt->textures.tcoin = mlx_load_png("./bonus/textures/coins/coin.png");
	dt->textures.texit = mlx_load_png("./bonus/textures/door/door_closed.png");
	dt->textures.ttop = mlx_load_png("./bonus/textures/walls/top.png");
	dt->textures.tinside = mlx_load_png("./bonus/textures/walls/inside.png");
	dt->textures.tdown = mlx_load_png("./bonus/textures/walls/down.png");
	dt->textures.tleft = mlx_load_png("./bonus/textures/walls/left.png");
	dt->textures.tright = mlx_load_png("./bonus/textures/walls/right.png");
	dt->textures.ttl = mlx_load_png("./bonus/textures/walls/top_left.png");
	dt->textures.tdl = mlx_load_png("./bonus/textures/walls/down_left.png");
	dt->textures.ttr = mlx_load_png("./bonus/textures/walls/top_right.png");
	dt->textures.tdr = mlx_load_png("./bonus/textures/walls/down_right.png");
	if (!dt->textures.tground || !dt->textures.tplayer || !dt->textures.ttop
		|| !dt->textures.tcoin || !dt->textures.texit || !dt->textures.tenemy
		|| !dt->textures.tdown || !dt->textures.tleft || !dt->textures.tright
		|| !dt->textures.ttl || !dt->textures.ttr || !dt->textures.tdl
		|| !dt->textures.tdr || !dt->textures.tinside)
		print_error_f(dt, "Loading textures PNG's");
	dt->textures.textures_done = 1;
}

void	load_images(t_data *dt)
{
	dt->textures.ground = mlx_texture_to_image(dt->mlx, dt->textures.tground);
	dt->textures.player = mlx_texture_to_image(dt->mlx, dt->textures.tplayer);
	dt->textures.enemy = mlx_texture_to_image(dt->mlx, dt->textures.tenemy);
	dt->textures.coin = mlx_texture_to_image(dt->mlx, dt->textures.tcoin);
	dt->textures.exit = mlx_texture_to_image(dt->mlx, dt->textures.texit);
	dt->textures.inside = mlx_texture_to_image(dt->mlx, dt->textures.tinside);
	dt->textures.top = mlx_texture_to_image(dt->mlx, dt->textures.ttop);
	dt->textures.down = mlx_texture_to_image(dt->mlx, dt->textures.tdown);
	dt->textures.left = mlx_texture_to_image(dt->mlx, dt->textures.tleft);
	dt->textures.right = mlx_texture_to_image(dt->mlx, dt->textures.tright);
	dt->textures.tl = mlx_texture_to_image(dt->mlx, dt->textures.ttl);
	dt->textures.tr = mlx_texture_to_image(dt->mlx, dt->textures.ttr);
	dt->textures.dl = mlx_texture_to_image(dt->mlx, dt->textures.tdl);
	dt->textures.dr = mlx_texture_to_image(dt->mlx, dt->textures.tdr);
	if (!dt->textures.ground || !dt->textures.player || !dt->textures.enemy
		|| !dt->textures.coin || !dt->textures.exit || !dt->textures.top
		|| !dt->textures.down || !dt->textures.left || !dt->textures.right
		|| !dt->textures.tl || !dt->textures.tr || !dt->textures.dl
		|| !dt->textures.dr)
		print_error_f(dt, "Textures texture to image");
	free_textures(&(dt->textures));
	dt->textures.images_done = 1;
}
