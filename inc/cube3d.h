/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:53:56 by najeuneh          #+#    #+#             */
/*   Updated: 2024/12/10 18:25:25 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.14159265359
# define KEY_A 0
# define KEY_D 2
# define KEY_E 101
# define KEY_G 103
# define KEY_M 109
# define KEY_Q 97
# define KEY_R 114
# define KEY_S 1
# define KEY_W 13
# define KEY_ESC 53
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_SHIFT 65505
# define KEY_SPACE 32
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 1920
# define HEIGHT 1080
# define E 1
# define W 0
# define S 2
# define N 3

typedef struct s_key
{
	int				key_le;
	int				key_ri;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_esc;
}					t_key;

typedef struct s_raycasting
{
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				mapy;
	int				mapx;
	int				drawstart;
	int				drawend;
	int				lineheight;
	int				color;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadisty;
	double			deltadistx;
	double			perpwalldist;
}					t_raycasting;

typedef struct s_wall
{
	double			wall_cord;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
}					t_wall;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_img;
typedef struct s_texture
{
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	int				height;
	int				width;
}					t_texture;

typedef struct s_recup
{
	char			*no;
	char			*so;
	char			*wo;
	char			*eo;
	char			**f;
	char			**c;
	int				tex_i;
	int				color_sol;
	int				color_plafon;
	t_texture		texture[4];
}					t_recup;

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
	double			dirx;
	double			diry;
	double			newdiry;
	double			newdirx;
	double			planex;
	double			planey;
	double			new_planex;
	double			new_planey;
	int				k;
	t_img			img;
	t_raycasting	ray;
	t_key			key;
	t_recup			recup;
	t_wall			wall;
}					t_data;

void				clean_all(t_data *data);
void				initvalue(t_data *data);
void				look_dir(t_data *data);
void				look_plane(t_data *data);
void				cube3d(t_data *data);
int					close_window(t_data *data);
void				key_move(t_data *data);
char				**ft_split(char const *s, char c);
t_data				init_map(int map, int x);
void				draw_wall(t_data *data, int i, int j);
void				draw_all(t_data *data, int x);
void				draw_floor(t_data *data, int x);
void				init_xpm(t_data *data);

/*----Raycasting----*/
void				raycasting(t_data *data, int x);
void				raycasting_suite(t_data *data);
void				draw_point(t_data *data, int x, int y, long color);
void				ray_while_hit(t_data *data);
void				side(t_data *data);

/*------------------*/

/*----Parsing----*/
char				*ft_strdup(char *s1);
char				*ft_strndup(char *s1, int n);
char				*ft_strjoin(char *s1, char *s2);
void				pars_map_text(t_data *game, int i, int j, int k);
int					pars(char **av, int ac, int fd);
int					pars_map(t_data *game);
int					check_border(t_data *game, int i, int j);
int					check_border2(t_data *game, int j, int i, int start);
// int					check_border_last(t_data *game);
// int					check_border_first(t_data *game);
// int					check_border_mid(t_data *game);
int					check_map(t_data *game);
int					ft_strlen(char *str);
long long			hexa_to_deci(char *hex);

int					f_f(char *str, char c, int t);
char				*ft_strndup(char *s1, int n);
char				*ft_strdup(char *s1);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strchr2(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
;
long long			ft_atoi(const char *str1);
int					ft_strlen(char *str);
char				*ft_putchar(char c, char *str, int i);
char				*ft_puthex(long long nbr, char *str);
void				skip_space(t_data *game, int i, int *j);
void				free_map2(t_data *game);
void				skip_virgule_space(t_data *game, int i, int *j, int *start);

void				pars_map_text(t_data *game, int i, int j, int k);
void				pars_map_other_attr(t_data *game, int *i, int *k);
void				pars_map_attr(t_data *game, int *i, int *k);
void				recup_texture(t_data *game, int i, int j, int start);
void				recup_texture_wall_floor(t_data *game, int i, int j,
						int start);

void				recup_texture_compass(t_data *game, int i, int *j);
void				temp_texture(t_data *game, int i, int j, int start);
void				temp_texture_wall(t_data *game, int i, int j, int start);
void				texture_wall(t_data *game, int i, int j, int start);
void				texture_floor(t_data *game, int i, int j, int start);
/*------------------*/

#endif
