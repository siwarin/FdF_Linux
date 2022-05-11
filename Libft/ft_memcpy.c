/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:36:28 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/29 11:33:47 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	unsigned const char	*b;

	i = 0;
	a = dst;
	b = src;
	while (i < n)
	{
		*a = *b;
		a++;
		b++;
		i++;
	}
	return ((char *)dst);
}
