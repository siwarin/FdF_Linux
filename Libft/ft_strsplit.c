/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:16:47 by siwarin           #+#    #+#             */
/*   Updated: 2019/01/11 20:08:40 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_wordi(char const *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j++;
			while ((str[i] != c) && (str[i] != '\0'))
			{
				if (str[i] == '\0')
					break ;
				i++;
			}
		}
	}
	return (j);
}

static int	ft_count_char(char const *str, char c)
{
	int	i;

	i = 0;
	while ((*str != c) && (*str != '\0'))
	{
		str++;
		i++;
	}
	return (i);
}

static char	*ft_fill_tab(char const **str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * ft_count_char(*str, c) + 1)))
		return (NULL);
	while (**str != c && **str != '\0')
	{
		new[i] = **str;
		(*str)++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char		**ft_strsplit(char const *str, char c)
{
	int		w;
	char	**tab;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	tab = NULL;
	w = ft_count_wordi(str, c);
	if (!(tab = (char **)malloc(sizeof(char *) * w + 1)))
		return (NULL);
	while (*str && i < w)
	{
		while (*str == c)
			str++;
		if (!(*str != c && *str))
		{
			free(tab);
			return (NULL);
		}
		tab[i++] = ft_fill_tab(&str, c);
	}
	tab[i] = NULL;
	return (tab);
}
