/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:00:33 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/20 16:16:34 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *) malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && i < len_s1)
		ptr[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
