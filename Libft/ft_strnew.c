/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:37:03 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/22 12:50:55 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!(tab = ft_memset(tab, 0, size + 1)))
		return (NULL);
	return (tab);
}
