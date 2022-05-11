/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:28:06 by siwarin           #+#    #+#             */
/*   Updated: 2019/03/04 14:33:09 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		hook_keydown(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_init(t_mlx *mlx)
{
	if ((mlx->mlx_ptr = mlx_init()) == NULL ||
			(mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGTH,
			mlx->name)) == NULL || (mlx->mlx_img = mlx_new_image(mlx->mlx_ptr,
			WIDTH, HEIGTH)) == NULL || (mlx->mlx_adr =
			(int *)mlx_get_data_addr(mlx->mlx_img,
			&mlx->bpp, &mlx->s_l, &mlx->endian)) == NULL)
	{
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		if (mlx->mlx_img != NULL)
			del_image(mlx);
		ft_memdel((void **)&mlx);
	}
	return ;
}

void	fdf(t_mlx *mlx)
{
	if (parser(mlx) == -1)
	{
		ft_putendl("Parsing error");
		return ;
	}
	mlx->c = 0;
	ft_init(mlx);
	ft_mlx(mlx);
	mlx_hook(mlx->mlx_win, 2, (1L << 0), keyboard, mlx);
	mlx_hook(mlx->mlx_win, 17, (1L << 17), hook_keydown, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		mlx.name = argv[1];
		if ((mlx.fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("File doesn't exist");
			return (0);
		}
		if (ft_strendcmp(mlx.name, ".fdf", 4) != 0)
		{
			ft_putstr("Bad file format, need a '.fdf' file");
			return (0);
		}
		fdf(&mlx);
	}
	else
		ft_putendl("usage ./fdf [File.fdf]");
	return (0);
}
