/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:16:19 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/01 13:20:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long_bonus.h"

void	lose(t_data *data)
{
	ft_printf("You Lose !!\n");
	mlx_terminate(data->mlx);
	exit(1);
}
