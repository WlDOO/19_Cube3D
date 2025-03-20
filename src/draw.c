/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:27:49 by najeuneh          #+#    #+#             */
/*   Updated: 2024/12/09 19:31:37 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	draw_wall(t_data *data, int i, int j)
{
	int				pixel_i;
	uint32_t		color;
	unsigned char	*pixel;

	data->wall.tex_y = (int)data->wall.tex_pos & (TEXHEIGHT - 1);
	data->wall.tex_pos += data->wall.step;
	pixel_i = (data->wall.tex_y * TEXWIDTH + data->wall.tex_x)
		* (data->recup.texture[data->recup.tex_i].bits_per_pixel / 8);
	pixel = (unsigned char *)
		&data->recup.texture[data->recup.tex_i].img_pixels_ptr[pixel_i];
	color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
	draw_point(data, i, j, color);
}

void	draw_all(t_data *data, int x)
{
	int	y;

	if (data->ray.side == 0 || data->ray.side == 1)
		data->wall.wall_cord = data->pl_y + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->wall.wall_cord = data->pl_x + data->ray.perpwalldist
			* data->ray.raydirx;
	data->wall.wall_cord -= floor(data->wall.wall_cord);
	data->wall.tex_x = (int)(data->wall.wall_cord * TEXWIDTH);
	if (data->ray.side == E || data->ray.side == S)
		data->wall.tex_x = TEXWIDTH - data->wall.tex_x - 1;
	data->wall.step = 1.0 * TEXHEIGHT / data->ray.lineheight;
	data->wall.tex_pos = (data->ray.drawstart - HEIGHT / 2
			+ data->ray.lineheight / 2) * data->wall.step;
	side(data);
	y = data->ray.drawstart - 1;
	while (++y < data->ray.drawend)
		draw_wall(data, x, y);
}

void	side(t_data *data)
{
	if (data->ray.side == 3)
		data->recup.tex_i = N;
	else if (data->ray.side == 2)
		data->recup.tex_i = S;
	else if (data->ray.side == 1)
		data->recup.tex_i = W;
	else if (data->ray.side == 0)
		data->recup.tex_i = E;
}

void	draw_floor(t_data *data, int x)
{
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		if (y > HEIGHT / 2)
			draw_point(data, x, y, data->recup.color_plafon);
		else
		{
			color = data->recup.color_sol;
			draw_point(data, x, y, color);
		}
		y++;
	}
}

void	draw_point(t_data *data, int x, int y, long color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * data->img.line_length) + (x * (data->img.bits_per_pixel
					/ 8));
		if (data->img.endian == 0)
		{
			data->img.addr[pixel + 0] = (color & 0xFF);
			data->img.addr[pixel + 1] = (color >> 8) & 0xFF;
			data->img.addr[pixel + 2] = (color >> 16) & 0xFF;
			data->img.addr[pixel + 3] = (color >> 24) & 0xFF;
		}
		else
		{
			data->img.addr[pixel + 0] = (color >> 24) & 0xFF;
			data->img.addr[pixel + 1] = (color >> 16) & 0xFF;
			data->img.addr[pixel + 2] = (color >> 8) & 0xFF;
			data->img.addr[pixel + 3] = (color & 0xFF);
		}
	}
}
