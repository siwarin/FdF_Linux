/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:17:07 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/20 18:09:12 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*tab;

	if (!s)
		return (NULL);
	if (!(tab = ft_strdup((char *)s)))
		return (NULL);
	i = 0;
	while (tab[i] != '\0')
	{
		tab[i] = f(s[i]);
		i++;
	}
	return (tab);
}
