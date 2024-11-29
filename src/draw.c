/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:27:49 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/28 19:41:39 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	draw_wall(t_data *data, int i, int j)
{
	int				pixel_i;
	uint32_t		color;
	unsigned char	*pixel;

	data->wall.texY = (int)data->wall.tex_pos & (TEXHEIGHT - 1);
	data->wall.tex_pos += data->wall.step;
	pixel_i = (data->wall.texY * TEXWIDTH + data->wall.texX) * (data->recup.texture[data->recup.tex_i].bits_per_pixel / 8);
	pixel = (unsigned char *)&data->recup.texture[data->recup.tex_i].img_pixels_ptr[pixel_i];
	color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
	draw_point(data, i, j, color);
}

void	draw_all(t_data *data, int x)
{
	int y;

	if (data->ray.side == 0)
		data->wall.wall_cord = data->pl_y + data->ray.perpWallDist * data->ray.raydirY;
	else
		data->wall.wall_cord = data->pl_x + data->ray.perpWallDist * data->ray.raydirX;
	data->wall.wall_cord -= floor(data->wall.wall_cord);
	data->wall.texX = (int)(data->wall.wall_cord * TEXWIDTH);
	if (data->ray.side == E || data->ray.side == S)
		data->wall.texX = TEXWIDTH - data->wall.texX - 1;
	data->wall.step = 1.0 * TEXHEIGHT / data->ray.lineHeight;
	data->wall.tex_pos = (data->ray.drawStart - HEIGHT / 2 + data->ray.lineHeight / 2) * data->wall.step;
	side(data);
	y = data->ray.drawStart - 1;
	while (++y < data->ray.drawend)
		draw_wall(data, x , y);
}

void	side(t_data *data)
{
	if (data->ray.side == 0)
		data->recup.tex_i = N;
	else if (data->ray.side == 1)
		data->recup.tex_i = S;
	else if (data->ray.side == 2)
		data->recup.tex_i = W;
	else if (data->ray.side == 3)
		data->recup.tex_i = E;
}

void	draw_floor(t_data *data, int x)
{
	int y;

	y = 0;
	while (y < 1080)
	{
		if (y > 540)
			draw_point(data, x, y, data->ray.color);
		else
		{
			int color = test;
			draw_point(data, x, y, color);
		}
		y++;
	}
}
