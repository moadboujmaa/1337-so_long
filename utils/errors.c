/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:55:18 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/25 08:18:23 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
