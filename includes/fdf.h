/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <siwarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:51:39 by siwarin           #+#    #+#             */
/*   Updated: 2022/05/11 17:22:31 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct				s_mlx
{
	void					*mlx_win;
	void					*mlx_ptr;
	void					*mlx_img;
	int						*mlx_adr;
	char					*name;
	int						fd;
	int						**map;
	int						lines;
	int						chars;
	int						color;
	int						bpp;
	int						s_l;
	int						endian;
	int						x;
	int						y;
	int						z;
	int						c;
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						xytab[3];
	int						stock[2];
	int						tabx[2];
	int						taby[2];
	int						e[2];
	int						v;
	int						w;
	int						b;
	int						i;
	int						j;
	int						l;
	int						k;
}							t_mlx;

int							create_color(t_mlx *mlx, int x, int y);
int							create_color2(t_mlx *mlx, int x, int y);
void						rotation(int key, t_mlx *mlx);
void						option(t_mlx *mlx);
int							hook_keydown(t_mlx *mlx);
void						fdf(t_mlx *mlx);
int							help_tab(t_mlx *mlx, char *line);
int							tabloc(t_mlx *mlx);
int							parser(t_mlx *mlx);
void						ft_mlx(t_mlx *mlx);
void						d_l(t_mlx *mlx, int x, int y);
void						ft_dls(t_mlx *mlx);
void						check_point(t_mlx *mlx);
void						del_image(t_mlx *mlx);
void						clear_image(t_mlx *mlx);
void						pixel(t_mlx *mlx);
int							keyboard(int key, t_mlx *mlx);
void						ft_bresenham(t_mlx *mlx, int x, int y);

# define WIDTH 2200
# define HEIGTH 1300

# define KEY_ESC 0xff1b

# define KEY_UP 0xff52
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_DOWN 0xff54
# define KEY_W 0x0077
# define KEY_R 0x0072
# define KEY_P 0x0070
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_C 0x0063
# define KEY_P_UP 0xff55
# define KEY_P_DOWN 0xff56

/*
** colors
*/

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ORANGE 0xFFA500
# define LIME 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define OLIVE 0x808000
# define GREEN 0x008000
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080

/*
** More awesome colors!
*/

# define CRIMSON 0xDC143C
# define CORAL 0xFF7F50
# define INDIAN_RED 0xCD5C5C
# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500

# define GOLD 0xFFD700
# define GOLDEN_ROD 0xDAA520
# define SADDLEBROWN 0x8B4513

# define LAWN_GREEN 0x7CFC00
# define DARK_GREEN 0x006400
# define FOREST_GREEN 0x228B22
# define PALE_GREEN 0x98FB98
# define SPRING_GREEN 0x00FF7F
# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA

# define DARK_SLATE_GRAY 0x2F4F4F
# define POWDER_BLUE 0xB0E0E6

# define AQUA_MARINE 0x7FFFD4
# define STEEL_BLUE 0x4682B4
# define SKY_BLUE 0x87CEEB
# define MIDNIGHT_BLUE 0x191970

# define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B
# define DEEP_PINK 0xFF1493
# define HOT_PINK 0xFF69B4
# define ORCHID 0xFF83FA

# define BEIGE 0xF5F5DC
# define ANTIQUE_WHITE 0xFAEBD7
# define WHEAT 0xF5DEB3
# define CORN_SILK 0xFFF8DC

# define LAVENDER 0xE6E6FA
# define FLORAL_WHITE 0xFFFAF0
# define ALICE_BLUE 0xF0F8FF
# define GHOST_WHITE 0xF8F8FF
# define HONEYDEW 0xF0FFF0
# define IVORY 0xFFFFF0
# define AZURE 0xF0FFFF
# define SNOW 0xFFFAFA
# define MISTY_ROSE 0xFFE4E1

# define DARK_GRAY 0x696969
# define GAINSBORO 0xDCDCDC
# define WHITE_SMOKE 0xF5F5F5
#endif
