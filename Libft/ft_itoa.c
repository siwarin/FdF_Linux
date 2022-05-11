/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:39:11 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/17 16:06:56 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(int n, int j, unsigned int i, char *str)
{
	i = n;
	if (n < 0)
		i = -i;
	str[j] = '\0';
	while (j > 0)
	{
		j--;
		str[j] = ((i % 10) + 48);
		i = i / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int		i;
	int					j;
	char				*str;

	j = 1;
	i = n;
	if (n < 0)
	{
		i = i * (-1);
		j++;
	}
	while (i / 10 > 0)
	{
		i = i / 10;
		j++;
	}
	if (!(str = malloc(sizeof(char) * j + 1)))
		return (NULL);
	ft_itoa2(n, j, i, str);
	return (str);
}
