/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:10:51 by siwarin           #+#    #+#             */
/*   Updated: 2019/06/20 15:42:32 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_mlx *mlx, int x, int y)
{
	while (mlx->v != x || mlx->w != y)
	{
		if (mlx->x / mlx->sx < mlx->chars && mlx->y / mlx->sy < mlx->lines)
			mlx->color = create_color(mlx, mlx->x / mlx->sx, mlx->y / mlx->sy);
		pixel(mlx);
		mlx->e[1] = mlx->e[0];
		if (mlx->e[1] > -mlx->tabx[0])
		{
			mlx->e[0] -= mlx->taby[0];
			mlx->v += mlx->tabx[1];
		}
		if (mlx->e[1] < mlx->taby[0])
		{
			mlx->e[0] += mlx->tabx[0];
			mlx->w += mlx->taby[1];
		}
	}
}

void	d_l(t_mlx *mlx, int x, int y)
{
	mlx->v = mlx->dx + (mlx->x - mlx->y);
	mlx->w = mlx->dy + mlx->map[(int)mlx->y / (int)mlx->sy]
		[(int)mlx->x / (int)mlx->sx] * mlx->z + ((mlx->x) + (mlx->y));
	mlx->tabx[0] = abs(mlx->v - x);
	mlx->tabx[1] = mlx->v < x ? 1 : -1;
	mlx->taby[0] = abs(mlx->w - y);
	mlx->taby[1] = mlx->w < y ? 1 : -1;
	mlx->e[0] = (mlx->tabx[0] > mlx->taby[0] ? mlx->tabx[0] :
		-mlx->taby[0]) / 2;
	ft_bresenham(mlx, x, y);
}

void	ft_dls(t_mlx *mlx)
{
	if (mlx->x / mlx->sx < mlx->chars - 1 && mlx->y / mlx->sy < mlx->lines)
	{
		d_l(mlx, mlx->dx + ((mlx->x + mlx->sx) - mlx->y) + mlx->k, mlx->dy +
		mlx->map[mlx->y / mlx->sy][mlx->x / mlx->sx + 1] *
		mlx->z + (mlx->x + mlx->sx) + mlx->y - mlx->l);
	}
	if (mlx->y / mlx->sy < mlx->lines - 1 && mlx->x / mlx->sx < mlx->chars)
	{
		d_l(mlx, mlx->dx + (mlx->x - (mlx->y + mlx->sy)) + mlx->k,
			mlx->dy + mlx->map[mlx->y / mlx->sy + 1]
			[mlx->x / mlx->sx] * mlx->z + mlx->x +
			(mlx->y + mlx->sy) - mlx->l);
	}
}

void	check_point(t_mlx *mlx)
{
	if (mlx->c == 0)
	{
		mlx->z = -1;
		mlx->dx = WIDTH * 0.5;
		mlx->dy = HEIGTH / (mlx->lines * 0.75);
		mlx->sx = (WIDTH * 0.25) / mlx->chars;
		mlx->sx++;
		mlx->sy = (HEIGTH * 0.25) / mlx->lines;
		mlx->sy++;
		mlx->color = WHITE;
		mlx->l = 0;
		mlx->k = 0;
	}
	mlx->c++;
}

void	ft_mlx(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->i = 0;
	mlx->j = 0;
	check_point(mlx);
	while (mlx->x / mlx->sx < mlx->chars || mlx->y / mlx->sy < mlx->lines - 1)
	{
		if (mlx->x / mlx->sx == mlx->chars)
		{
			mlx->x = 0;
			mlx->i = 0;
			mlx->y += mlx->sy;
			mlx->j++;
		}
		ft_dls(mlx);
		mlx->x += mlx->sx;
		mlx->i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->mlx_img, 0, 0);
	option(mlx);
}
