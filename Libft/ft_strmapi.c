/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:19:58 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/21 11:29:26 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	if (!s)
		return (NULL);
	if (!(tab = ft_strdup((char *)s)))
		return (NULL);
	i = 0;
	while (tab[i] != '\0')
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	return (tab);
}
