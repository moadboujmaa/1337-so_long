/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:21:52 by  mboujama         #+#    #+#             */
/*   Updated: 2024/05/11 11:59:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	free_textures(t_textures *t_imgs)
{
	mlx_delete_texture(t_imgs->tground);
	mlx_delete_texture(t_imgs->tplayer);
	mlx_delete_texture(t_imgs->tenemy);
	mlx_delete_texture(t_imgs->tcoin);
	mlx_delete_texture(t_imgs->texit);
	mlx_delete_texture(t_imgs->ttop);
	mlx_delete_texture(t_imgs->tdown);
	mlx_delete_texture(t_imgs->tinside);
	mlx_delete_texture(t_imgs->tleft);
	mlx_delete_texture(t_imgs->tright);
	mlx_delete_texture(t_imgs->ttl);
	mlx_delete_texture(t_imgs->tdl);
	mlx_delete_texture(t_imgs->ttr);
	mlx_delete_texture(t_imgs->tdr);
	mlx_delete_texture(t_imgs->twin);
	mlx_delete_texture(t_imgs->tlose);
}
