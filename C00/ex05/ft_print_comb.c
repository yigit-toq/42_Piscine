/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:10:30 by ytop              #+#    #+#             */
/*   Updated: 2023/09/01 11:10:35 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	b;
	char	o;
	char	y;

	b = '0';
	while (b <= '7')
	{
		o = b + 1;
		while (o <= '8')
		{
			y = o + 1;
			while (y <= '9')
			{
				ft_print(b, o, y);
				y++;
			}
			o++;
		}
		b++;
	}
}
