/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:21:52 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/08 12:08:14 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	free_coins(t_coin_frames *c_imgs)
{
	mlx_delete_texture(c_imgs->t_coin_1);
	mlx_delete_texture(c_imgs->t_coin_2);
	mlx_delete_texture(c_imgs->t_coin_3);
	mlx_delete_texture(c_imgs->t_coin_4);
	mlx_delete_texture(c_imgs->t_coin_5);
	mlx_delete_texture(c_imgs->t_coin_6);
	mlx_delete_texture(c_imgs->t_coin_7);
}

void	free_enemy(t_enemy_frames *e_imgs)
{
	mlx_delete_texture(e_imgs->t_enemy_1);
	mlx_delete_texture(e_imgs->t_enemy_2);
	mlx_delete_texture(e_imgs->t_enemy_3);
	mlx_delete_texture(e_imgs->t_enemy_4);
	mlx_delete_texture(e_imgs->t_enemy_5);
	mlx_delete_texture(e_imgs->t_enemy_6);
}

void	free_flag(t_flag_frames *f_imgs)
{
	mlx_delete_texture(f_imgs->t_flag_1);
	mlx_delete_texture(f_imgs->t_flag_2);
	mlx_delete_texture(f_imgs->t_flag_3);
	mlx_delete_texture(f_imgs->t_flag_4);
	mlx_delete_texture(f_imgs->t_flag_5);
	mlx_delete_texture(f_imgs->t_flag_6);
}

void	free_rise(t_rise_frames *r_imgs)
{
	mlx_delete_texture(r_imgs->t_rise_1);
	mlx_delete_texture(r_imgs->t_rise_2);
	mlx_delete_texture(r_imgs->t_rise_3);
	mlx_delete_texture(r_imgs->t_rise_4);
	mlx_delete_texture(r_imgs->t_rise_5);
	mlx_delete_texture(r_imgs->t_rise_6);
}

void	free_idle(t_idle_frames *i_imgs)
{
	mlx_delete_texture(i_imgs->t_idle_1);
	mlx_delete_texture(i_imgs->t_idle_2);
	mlx_delete_texture(i_imgs->t_idle_3);
	mlx_delete_texture(i_imgs->t_idle_4);
	mlx_delete_texture(i_imgs->t_idle_5);
	mlx_delete_texture(i_imgs->t_idle_6);
	mlx_delete_texture(i_imgs->t_idle_7);
	mlx_delete_texture(i_imgs->t_idle_8);
	mlx_delete_texture(i_imgs->t_idle_9);
	mlx_delete_texture(i_imgs->t_idle_10);
}
