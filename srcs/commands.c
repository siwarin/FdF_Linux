/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:09:41 by siwarin           #+#    #+#             */
/*   Updated: 2022/05/11 17:26:21 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** 69 = + num pad ; 78 = - num pad ;
** 123/124/125/126 = les fleches directionnelles
** 15 = R ; 53 = echap ; 75 = / num pad ; 67 = * num pad
** 116 = pgup ; 121 = pgdwn ; end = 119 ; 89 = 7 num pad
*/

void		option(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 20, WHITE, "Zoom : +");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 40, WHITE, "Dezoom : -");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 60, WHITE,
			"Move : Arrows");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 80, WHITE,
			"Altitude : / or *");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 100, WHITE, "Reset : R");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 120, WHITE, "Leave : Esc");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, WIDTH / 2, 20, WHITE,
			"Map :");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, WIDTH / 2, 40, WHITE,
		mlx->name);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 140, WHITE,
		"Rotation : /\\PgUp \\/PgDwn | <- End 7NumPad -> ");
	if (mlx->b == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 5, 1280, WHITE,
	"The map has been resized because one or more point exceed 1000 or -1000");
}

void		zoom(int key, t_mlx *mlx)
{
	if (key == KEY_W && mlx->sx * 2 <= 1000 && mlx->sy * 2 <= 1000)
	{
		mlx->sx *= 2;
		mlx->sy *= 2;
		mlx->z *= 2;
		mlx->l *= 2;
		mlx->k *= 2;
	}
	else if (key == KEY_S && mlx->sx * 0.5 >= 1 && mlx->sy * 0.5 >= 1 &&
		(-mlx->z * 0.5 >= 1 || mlx->z * 0.5 >= 1))
	{
		mlx->sx *= 0.5;
		mlx->sy *= 0.5;
		mlx->z *= 0.5;
		mlx->l *= 0.5;
		mlx->k *= 0.5;
	}
}

void		decal(int key, t_mlx *mlx)
{
	if (key >= KEY_LEFT && key <= KEY_UP)
	{
		if (key == KEY_LEFT)
			mlx->dx -= 20;
		if (key == KEY_UP)
			mlx->dy -= 20;
		if (key == KEY_RIGHT)
			mlx->dx += 20;
		if (key == KEY_DOWN)
			mlx->dy += 20;
	}
}

void		proj(int key, t_mlx *mlx)
{
	if (key == KEY_P_UP)
		mlx->l += 1;
	if (key == KEY_P_DOWN)
		mlx->l -= 1;
	/*if (key == KEY_C)
		mlx->k -= 1;
	if (key == KEY_HOME)
		mlx->k += 1;*/
}

int			keyboard(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		hook_keydown(mlx);
	clear_image(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	if (key == KEY_A)
		mlx->z += 1;
	if (key == KEY_D)
		mlx->z -= 1;
	if (key == KEY_R)
		mlx->c = 0;
	proj(key, mlx);
	zoom(key, mlx);
	decal(key, mlx);
	ft_mlx(mlx);
	return (0);
}
