/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:32:00 by siwarin           #+#    #+#             */
/*   Updated: 2019/03/01 17:32:57 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		help_tab(t_mlx *mlx, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (mlx->lines == 0)
		mlx->chars = i;
	else if (i != mlx->chars)
		return (-1);
	free(tab);
	mlx->lines++;
	return (0);
}

int		tabloc(t_mlx *mlx)
{
	char	*line;
	int		ret;

	line = NULL;
	mlx->lines = 0;
	mlx->chars = 0;
	while ((ret = get_next_line(mlx->fd, &line)))
	{
		if (help_tab(mlx, line) == -1)
			return (-1);
		free(line);
	}
	mlx->map = ft_memalloc(sizeof(int *) * mlx->lines);
	close(mlx->fd);
	mlx->fd = open(mlx->name, O_RDONLY);
	free(line);
	return (0);
}

void	untruc(t_mlx *mlx, char **tab)
{
	while (tab[mlx->xytab[0]] != NULL)
	{
		if (ft_atoi(tab[mlx->xytab[0]]) > 1000)
		{
			mlx->map[mlx->xytab[1]][mlx->xytab[0]] = 1000;
			mlx->b = 1;
		}
		else if (ft_atoi(tab[mlx->xytab[0]]) < -1000)
		{
			mlx->map[mlx->xytab[1]][mlx->xytab[0]] = -1000;
			mlx->b = 1;
		}
		else
			mlx->map[mlx->xytab[1]]
			[mlx->xytab[0]] = ft_atoi(tab[mlx->xytab[0]]);
		free(tab[mlx->xytab[0]]);
		mlx->xytab[0]++;
	}
}

int		parser(t_mlx *mlx)
{
	char	**tab;
	char	*line;

	mlx->xytab[1] = 0;
	if (tabloc(mlx) == -1)
		return (-1);
	while ((mlx->xytab[2] = get_next_line(mlx->fd, &line)) > 0)
	{
		if (strcmp(line, "\0") == 0)
			return (-1);
		mlx->xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		mlx->map[mlx->xytab[1]] = ft_memalloc(sizeof(int) * mlx->chars);
		untruc(mlx, tab);
		free(tab);
		free(line);
		mlx->xytab[1]++;
	}
	free(line);
	close(mlx->fd);
	return ((mlx->xytab[2] == -1) ? -1 : 0);
}
