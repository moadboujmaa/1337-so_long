/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:55:18 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 09:40:34 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_program(t_data *data)
{
	ft_2d_free(data->map);
	ft_2d_free(data->map_copy);
}

void	print_error(t_data *data, char *str)
{
	free_program(data);
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
