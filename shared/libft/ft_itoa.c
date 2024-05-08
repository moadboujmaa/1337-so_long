/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:05:41 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/08 12:19:53 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = number_length(n);
	ptr = (char *) malloc(sizeof(char) * length + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	n = ft_abs(n);
	ptr[length] = '\0';
	while (length > 0)
	{
		ptr[--length] = n % 10 + '0';
		n /= 10;
		if (!n)
			break ;
	}
	return (ptr);
}
