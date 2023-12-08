/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:25:08 by ytop              #+#    #+#             */
/*   Updated: 2023/09/21 14:09:41 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*msrc;
	int		i;

	i = 0;
	msrc = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!msrc)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		msrc[i] = src[i];
		i++;
	}
	msrc[i] = '\0';
	return (msrc);
}
