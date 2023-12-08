/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:38:02 by ytop              #+#    #+#             */
/*   Updated: 2023/09/21 14:14:44 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*msize;
	int	i;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	msize = (int *)malloc((max - min) * sizeof(int));
	if (!msize)
		return (0);
	while (i < max - min)
	{
		msize[i] = min + i;
		i++;
	}
	return (msize);
}
