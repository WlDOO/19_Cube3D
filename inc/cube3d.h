/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:53:56 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/14 16:27:20 by najeuneh         ###   ########.fr       */
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

#define RGB_Red    0xFF0000  // Rouge en hexadécimal
#define RGB_Green  0x00FF00  // Vert
#define RGB_Blue   0x0000FF  // Bleu
#define RGB_White  0xFFFFFF  // Blanc
#define RGB_Yellow 0xFFFF00  // Jaune

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
	double		pl_x;
	double		pl_y;
	void		*mlx;
	void		*win;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	t_img		img;
}				t_data;

char	**ft_split(char const *s, char c);
t_data	init_map(int map);

#endif
