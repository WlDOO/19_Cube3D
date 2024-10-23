/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:09:39 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/22 15:54:12 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	key_move(t_data *data)
{
	if (data->key.key_w == 1)
	{
		data->new_pl_x = data->pl_x + data->dirX * 0.1;
		data->new_pl_y = data->pl_y + data->dirY * 0.1;
		if (data->map[(int)data->new_pl_y][(int)data->new_pl_x] != '1')
		{
			data->pl_x = data->new_pl_x;
			data->pl_y = data->new_pl_y;
		}
	}
	else if (data->key.key_s == 1)
	{		
		data->new_pl_x = data->pl_x - data->dirX * 0.1;
		data->new_pl_y = data->pl_y - data->dirY * 0.1;
		if (data->map[(int)data->new_pl_y][(int)data->new_pl_x] != '1')
		{
			data->pl_x = data->new_pl_x;
			data->pl_y = data->new_pl_y;
		}
	}
	else if (data->key.key_d == 1)
	{
		data->newdirX = data->dirX * cos(PI / 2) - data->dirY * sin(PI / 2);
		data->newdirY = data->dirX * sin(PI / 2) + data->dirY * cos(PI / 2);
		data->new_pl_x = data->pl_x + data->newdirX * 0.07;
		data->new_pl_y = data->pl_y + data->newdirY * 0.07;
		if (data->map[(int)data->new_pl_y][(int)data->new_pl_x] != '1')
		{
			data->pl_x = data->new_pl_x;
			data->pl_y = data->new_pl_y;
		}
	}
	else if (data->key.key_a == 1)
	{
		data->newdirX = data->dirX * cos(PI / 2) - data->dirY * sin(PI / 2);
		data->newdirY = data->dirX * sin(PI / 2) + data->dirY * cos(PI / 2);
		data->new_pl_x = data->pl_x - data->newdirX * 0.07;
		data->new_pl_y = data->pl_y - data->newdirY * 0.07;
		if (data->map[(int)data->new_pl_y][(int)data->new_pl_x] != '1')
		{
			data->pl_x = data->new_pl_x;
			data->pl_y = data->new_pl_y;
		}
	}
	else if (data->key.key_L)
	{
		double angle = -0.03;
		data->newdirX = data->dirX * cos(angle) - data->dirY * sin(angle);
		data->newdirY = data->dirX * sin(angle) + data->dirY * cos(angle);
		data->new_planeX = data->planeX * cos(angle) - data->planeY * sin(angle);
		data->new_planeY = data->planeX * sin(angle) + data->planeY * cos(angle);
		data->dirX = data->newdirX;
		data->dirY = data->newdirY;
		data->planeX = data->new_planeX;
		data->planeY = data->new_planeY;
	}
	else if (data->key.key_R)
	{
		double angle = 0.03;
		data->newdirX = data->dirX * cos(angle) - data->dirY * sin(angle);
		data->newdirY = data->dirX * sin(angle) + data->dirY * cos(angle);
		data->new_planeX = data->planeX * cos(angle) - data->planeY * sin(angle);
		data->new_planeY = data->planeX * sin(angle) + data->planeY *cos(angle);
		data->dirX = data->newdirX;
		data->dirY = data->newdirY;
		data->planeX = data->new_planeX;
		data->planeY = data->new_planeY;
	}
	else if (data->key.key_esc)
		exit(0);

}

void draw_point(t_data *data, int x, int y, long color)
{
int pixel;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
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

int	loop(t_data	*data)
{
	int	x;

	x = 0;
	//calculer le raytracing
	while (x < 1920)
	{
		raycasting(data, x);
		raycasting_suite(data);
		ray_while_hit(data);
		data->ray.drawend = data->ray.lineHeight / 2 + 1080 / 2;
		if (data->ray.drawend >= 1080)
			data->ray.drawend = 1080 - 1;
		//choose wall color
		int	y = 0;
		while (y < 1080)
		{
			if (y >= data->ray.drawStart && y <= data->ray.drawend)
			{
				int color = RGB_Red;
				if (data->ray.side == 0)
					color = RGB_Red;
				else if (data->ray.side == 1)
					color = RGB_Green;
				if (data->ray.side == 2)
					color = RGB_White;
				else if  (data->ray.side == 3)
					color = RGB_Yellow;
				draw_point(data, x, y, color);
			}
			else
				draw_point(data, x, y, data->ray.color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	key_move(data);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key.key_w = 1;
	else if (keycode == KEY_A)
		data->key.key_a = 1;
	else if (keycode == KEY_S)
		data->key.key_s = 1;
	else if (keycode == KEY_D)
		data->key.key_d = 1;
	else if (keycode == KEY_ESC)
		data->key.key_esc = 1;
	else if (keycode == KEY_LEFT)
		data->key.key_L = 1;
	else if (keycode == KEY_RIGHT)
		data->key.key_R = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key.key_w = 0;
	else if (keycode == KEY_A)
		data->key.key_a = 0;
	else if (keycode == KEY_S)
		data->key.key_s = 0;
	else if (keycode == KEY_D)
		data->key.key_d = 0;
	else if (keycode == KEY_ESC)
		data->key.key_esc = 0;
	else if (keycode == KEY_LEFT)
		data->key.key_L = 0;
	else if (keycode == KEY_RIGHT)
		data->key.key_R = 0;
	return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->img.addr + (y * 1080 + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void cube3d(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Cube3D");
	data->img.img = mlx_new_image(data->mlx, 1920, 1080);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

int main(int ac, char **av)
{
	t_data data;
	int fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	data = init_map(fd);
	cube3d(&data);
	mlx_hook(data.win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, &key_release, &data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
}
