/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:36:50 by  mboujama         #+#    #+#             */
/*   Updated: 2024/04/30 16:42:37 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	flag_hook(void *param)
{
	static int	i;
	static int	j;

	(void) param;
	if (!i)
		i = 0;
	j = 0;
	while (i)
	{
		if (j == 7)
			j = 0;
		i++;
	}
}

void	start_animation(t_data *data)
{
	if (data->coins == 0 && data->flag_started)
	{
		mlx_loop_hook(data->mlx, flag_hook, data);
		data->flag_started = 0;
	}
}