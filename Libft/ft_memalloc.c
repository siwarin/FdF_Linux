/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:11:20 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/19 17:00:11 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tab;

	if (!(tab = malloc(sizeof(char) * size)))
		return (NULL);
	if (!(tab = ft_memset(tab, 0, size)))
		return (NULL);
	return (tab);
}
