/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:01:44 by ytop              #+#    #+#             */
/*   Updated: 2023/09/21 18:16:21 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	index;
	int	*mrange;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	mrange = (int *)malloc(size * sizeof(int));
	if (!(mrange))
	{
		*range = 0;
		return (-1);
	}
	*range = mrange;
	index = 0;
	while (index < size)
	{
		mrange[index] = min + index;
		index++;
	}
	return (size);
}
