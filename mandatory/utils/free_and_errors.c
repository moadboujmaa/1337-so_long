/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:55:18 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/29 13:53:41 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_program(t_data *data)
{
	ft_2d_free(data->map);
	ft_2d_free(data->map_copy);
}

void	print_error(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	print_error_f(t_data *data, char *str)
{
	free_program(data);
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
