/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:19 by jvan-hal          #+#    #+#             */
/*   Updated: 2024/04/29 13:28:12 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

bool	mlx_equal_image(void *lstcontent, void *value)
{
	const mlx_image_t	*lcontent = lstcontent;
	const mlx_image_t	*lvalue = value;

	return (lcontent == lvalue);
}

bool	mlx_equal_inst(void *lstcontent, void *value)
{
	const draw_queue_t	*lcontent = lstcontent;
	const mlx_image_t	*lvalue = value;

	return (lcontent->image == lvalue);
}