/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:53:56 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/28 19:48:53 by najeuneh         ###   ########.fr       */
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
#define test		0xBB00CC
#define TEXWIDTH 128
#define TEXHEIGHT 128
#define WIDTH	1920
#define	HEIGHT	1080
#define E 1
#define W 0
#define S 2
#define N 3

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

typedef struct s_wall
{
	double	wall_cord;
	double	step;
	double	tex_pos;
	int		texX;
	int		texY;
}			t_wall;

typedef	struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	height;
	int 	width;
}				t_img;
typedef struct s_texture
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		height;
	int		width;
}				t_texture;

typedef struct s_recup
{
	char 		*no;
	char		*so;
	char		*wo;
	char		*eo;
	char		**f;
	char		**c;
	int			tex_i;
	int			color_sol;
	int			color_plafon;
	t_texture	texture[4];
}				t_recup;

typedef struct s_data
{
	int				map_x;
	int				map_y;
	char			**map;
	char			**map2;
	char			**map_attr;
	char			*line;
	void			*win;
	void			*mlx;
	double			new_pl_x;
	double			new_pl_y;
	double			pl_x;
	double			pl_y;
	double			dirX;
	double			dirY;
	double			newdirY;
	double			newdirX;
	double			planeX;
	double			planeY;
	double			new_planeX;
	double			new_planeY;
	t_img			img;
	t_raycasting	ray;
	t_key			key;
	t_recup			recup;
	t_wall			wall;
}				t_data;

char	**ft_split(char const *s, char c);
t_data	init_map(int map, int x);
void	draw_wall(t_data *data, int i, int j);
void	draw_all(t_data *data, int x);
void	draw_floor(t_data *data, int x);
void	init_xpm(t_data *data);

/*----Raycasting----*/
void	raycasting(t_data *data, int x);
void	raycasting_suite(t_data *data);
void 	draw_point(t_data *data, int x, int y, long color);
void	ray_while_hit(t_data *data);
void	side(t_data *data);

/*------------------*/

/*----Parsing----*/
char	*ft_strdup(char *s1);
char	*ft_strndup(char *s1, int n);
char	*ft_puthex(int nbr, char *str);
char	*ft_strjoin(char *s1, char *s2);
void	pars_map_text(t_data *game);
int		pars(char **av,int ac, int fd);
int		pars_map(t_data *game);
int		check_border(t_data *game, int i, int j);
int		check_border2(t_data *game, int j, int i, int start);
int		check_border_last(t_data *game);
int		check_border_first(t_data *game);
int		check_border_mid(t_data *game);
int		check_map(t_data *game);
int		ft_strlen(char *str);
int		ft_atoi(const char *str1);
int		hexa_to_deci(char *hex) ;
/*------------------*/

#endif
