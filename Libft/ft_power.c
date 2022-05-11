/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:41:23 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/27 14:53:57 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int i;
	int j;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	j = nb;
	while (i < power - 1)
	{
		nb = nb * j;
		i++;
	}
	return (nb);
}
