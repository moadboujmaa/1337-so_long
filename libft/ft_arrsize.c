/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:41:50 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/21 16:02:56 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_arrsize(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
