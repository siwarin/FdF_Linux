/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:45:06 by siwarin           #+#    #+#             */
/*   Updated: 2019/02/27 20:14:17 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		create_color(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] <= -10)
		return (MIDNIGHT_BLUE);
	if (mlx->map[y][x] < 0 && mlx->map[y][x] > -10)
		return (AQUA_MARINE);
	if (mlx->map[y][x] == 0)
		return (SPRING_GREEN);
	if (mlx->map[y][x] > 0 && mlx->map[y][x] <= 10)
		return (DARK_GREEN);
	if (mlx->map[y][x] >= 10 && mlx->map[y][x] < 20)
		return (SADDLEBROWN);
	if (mlx->map[y][x] >= 20 && mlx->map[y][x] < 30)
		return (CORAL);
	if (mlx->map[y][x] >= 30)
		return (create_color2(mlx, x, y));
	return (WHITE);
}

int		create_color2(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] >= 30 && mlx->map[y][x] < 40)
		return (GOLDEN_ROD);
	if (mlx->map[y][x] >= 40 && mlx->map[y][x] < 50)
		return (BEIGE);
	if (mlx->map[y][x] > 50 && mlx->map[y][x] < 100)
		return (WHITE_SMOKE);
	if (mlx->map[y][x] > 100)
		return (WHITE);
	return (WHITE);
}

void	pixel(t_mlx *mlx)
{
	if (mlx->v + (mlx->j * mlx->k) + (mlx->i * mlx->k) < 0 ||
		mlx->v + (mlx->j * mlx->k) + (mlx->i * mlx->k) >= WIDTH ||
		mlx->w - (mlx->j * mlx->l) - (mlx->i * mlx->l) < 0 ||
		mlx->w - (mlx->j * mlx->l) - (mlx->i * mlx->l) >= HEIGTH)
		return ;
	mlx->mlx_adr[(mlx->w - (mlx->j * mlx->l) - (mlx->i * mlx->l)) * WIDTH +
		(mlx->v + (mlx->j * mlx->k) + (mlx->i * mlx->k))] = mlx->color;
}

void	clear_image(t_mlx *mlx)
{
	ft_bzero(mlx->mlx_adr, WIDTH * HEIGTH * 4);
}

void	del_image(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->mlx_img != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img);
		ft_memdel((void **)&mlx->mlx_img);
	}
	return ;
}
