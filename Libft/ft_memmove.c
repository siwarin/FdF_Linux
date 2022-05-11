/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:00:36 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/16 14:57:34 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*a;
	unsigned char		*b;

	a = src;
	b = dst;
	while (len--)
	{
		if (a < b)
			b[len] = a[len];
		else
			*b++ = *a++;
	}
	return ((char *)dst);
}
