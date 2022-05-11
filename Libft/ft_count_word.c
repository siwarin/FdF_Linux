/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:12:31 by siwarin           #+#    #+#             */
/*   Updated: 2019/01/21 15:27:38 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function have multiple operation, depending of x
** 1 is for alphabet only
** 2 is for numbers only
** 3 is for special only (33-47 / 58-64 / 91-96 for ASCII)
** 4 is for alpha + number X
** 5 is for alpha + special X
** 6 is for number + special X
** 7 is for all
** -------------------------------------------------------------------------
** all non-displayable character are considered like space and being ignored
** \0 have his classic feature
**
** if something weird is happening, check is the index for x is good
*/

#include "libft.h"

/*
** ici, tout ce qui n'est pas une lettre minuscule ou majuscule est
** considerer comme un separateur
*/

int		ft_count_word1(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] <= '@' || (s[i] >= 91 && s[i] <= 96) || s[i] >= 123)
			i++;
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			j++;
			while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				i++;
		}
	}
	return (j);
}

/*
** ici, tout ce qui n'est pas un chiffre est considerer comme un separateur
*/

int		ft_count_word2(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] < '0' || s[i] > '9')
			i++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			j++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
	}
	return (j);
}

int		ft_count_word3(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] <= ' ' || (s[i] >= '0' && s[i] <= '9') ||
				(s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
				s[i] == 127)
			i++;
		if ((s[i] >= '!' && s[i] <= '/') || (s[i] >= ':' && s[i] <= '@') ||
				(s[i] >= '[' && s[i] <= '`') || (s[i] >= '{' && s[i] <= '~'))
		{
			j++;
			while ((s[i] >= '!' && s[i] <= '/') ||
					(s[i] >= ':' && s[i] <= '@') ||
					(s[i] >= '[' && s[i] <= '`') ||
					(s[i] >= '{' && s[i] <= '~'))
				i++;
		}
	}
	return (j);
}

/*
** les autres parametres sont en cours de developpement
*/

int		ft_count_word(char *s, int x)
{
	int i;

	if (!x)
		return (-1);
	if (x < 1 || x > 7)
		return (-1);
	if (x == 1)
		i = ft_count_word1(s);
	if (x == 2)
		i = ft_count_word2(s);
	if (x == 3)
		i = ft_count_word3(s);
	return (i);
}
