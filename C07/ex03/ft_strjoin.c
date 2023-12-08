/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:24:11 by ytop              #+#    #+#             */
/*   Updated: 2023/09/21 19:32:05 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_compute_final_length(char **strs, int size, int seplen)
{
	int	totalsize;
	int	i;

	totalsize = 0;
	i = 0;
	while (i < size)
	{
		totalsize += ft_strlen(strs[i]);
		totalsize += seplen;
		i++;
	}
	totalsize -= seplen;
	return (totalsize);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		totalsize;
	int		index;
	char	*string;
	char	*mstr;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	totalsize = ft_compute_final_length(strs, size, ft_strlen(sep));
	string = (char *)malloc((totalsize + 1) * sizeof(char));
	mstr = string;
	if (!mstr)
		return (0);
	index = -1;
	while (++index < size)
	{
		ft_strcpy(mstr, strs[index]);
		mstr += ft_strlen(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(mstr, sep);
			mstr += ft_strlen(sep);
		}
	}
	*mstr = '\0';
	return (string);
}
