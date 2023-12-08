/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:33:35 by ytop              #+#    #+#             */
/*   Updated: 2023/09/14 15:29:05 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlen(char *dest, char *src, unsigned int *dlen, unsigned int *slen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		j++;
	}
	*dlen = i;
	*slen = j;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = 0;
	ft_strlen(dest, src, &dlen, &slen);
	if (size == 0 || size <= dlen)
	{
		return (slen + size);
	}
	while (j < size - dlen - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dlen + slen);
}
