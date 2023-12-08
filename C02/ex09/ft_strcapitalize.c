/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:32 by ytop              #+#    #+#             */
/*   Updated: 2023/09/04 11:02:32 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_struppercase(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	return (str[i]);
}

char	ft_strlowercase(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] += 32;
	return (str[i]);
}

int	ft_strboolean(char *str, int i)
{
	if (!(str[i] >= 'a' && str[i] <= 'z'))
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_struppercase(str, i);
	while (str[i] != '\0')
	{
		if (ft_strboolean(str, i - 1) == 1)
			ft_struppercase(str, i);
		else
			ft_strlowercase(str, i);
		i++;
	}
	return (str);
}
