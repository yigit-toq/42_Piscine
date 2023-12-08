/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:52:52 by ytop              #+#    #+#             */
/*   Updated: 2023/09/14 10:52:52 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power > 0)
	{
		result *= nb * ft_recursive_power(nb, power -1);
	}
	if (power < 0)
	{
		return (0);
	}
	return (result);
}
