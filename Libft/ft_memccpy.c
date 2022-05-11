/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:08:57 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/17 13:05:29 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*a;
	unsigned char		*b;
	int					i;

	a = src;
	b = dst;
	i = 0;
	while (n--)
	{
		if (*a == (unsigned char)c)
		{
			*b = *a;
			return ((char *)&dst[i + 1]);
		}
		*b++ = *a++;
		i++;
	}
	return (NULL);
}
