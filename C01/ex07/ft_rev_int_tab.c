/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:36:02 by ytop              #+#    #+#             */
/*   Updated: 2023/09/05 14:27:53 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	bas;
	int	son;
	int	tmp;

	bas = 0;
	son = size - 1;
	while (bas < son)
	{
		tmp = tab[bas];
		tab[bas] = tab[son];
		tab[son] = tmp;
		bas++;
		son--;
	}
}
