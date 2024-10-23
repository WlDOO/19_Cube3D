/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:53:56 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/21 14:06:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <sys/time.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

//-lmlx -framework OpenGL -framework Appkit

# define PI 3.14159265359
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_E 101
#  define KEY_G 103
#  define KEY_M 109
#  define KEY_Q 97
#  define KEY_R 114
#  define KEY_S 1
#  define KEY_W 13
#  define KEY_ESC 53
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_UP 126
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_SHIFT 65505
#  define KEY_SPACE 32
#define RGB_Red    0xFF0000  // Rouge en hexadécimal
#define RGB_Green  0x00FF00  // Vert
#define RGB_Blue   0x0000FF  // Bleu
#define RGB_White  0xFFFFFF  // Blanc
#define RGB_Yellow 0xFFFF00  // Jaune

typedef	struct s_key
{
	int	key_L;
	int	key_R;
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_esc;
}				t_key;


typedef struct	s_raycasting
{
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		mapY;
	int		mapX;
	int		drawStart;
	int		drawend;
	int		lineHeight;
	int		color;
	double	cameraX;
	double	raydirX;
	double	raydirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistY;
	double	deltaDistX;
	double	perpWallDist;
}			t_raycasting;

typedef	struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	char		**map;
	char		*line;
	int			map_x;
	int			map_y;
	double		new_pl_x;
	double		new_pl_y;
	double		pl_x;
	double		pl_y;
	void		*mlx;
	void		*win;
	double		dirX;
	double		dirY;
	double		newdirY;
	double		newdirX;
	double		planeX;
	double		planeY;
	double		new_planeX;
	double		new_planeY;
	t_img		img;
	t_raycasting	ray;
	t_key			key;
}				t_data;

char	**ft_split(char const *s, char c);
t_data	init_map(int map);

/*----Raycasting----*/
void	raycasting(t_data *data, int x);
void	raycasting_suite(t_data *data);
void	ray_while_hit(t_data *data);
/*------------------*/
#endif
