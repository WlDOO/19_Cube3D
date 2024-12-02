/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:09:39 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/29 17:13:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < 1920)
	{
		data->ray.mapx = (int)data->pl_x;
		data->ray.mapy = (int)data->pl_y;
		raycasting(data, x);
		raycasting_suite(data);
		ray_while_hit(data);
		data->ray.lineheight = HEIGHT / data->ray.perpwalldist;
		data->ray.drawstart = -1 * data->ray.lineheight / 2 + HEIGHT / 2;
		if (data->ray.drawstart < 0)
			data->ray.drawstart = 0;
		data->ray.drawend = data->ray.lineheight / 2 + HEIGHT / 2;
		if (data->ray.drawend >= HEIGHT)
			data->ray.drawend = HEIGHT - 1;
		draw_floor(data, x);
		draw_all(data, x);
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
		data->key.key_le = 1;
	else if (keycode == KEY_RIGHT)
		data->key.key_ri = 1;
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
		data->key.key_le = 0;
	else if (keycode == KEY_RIGHT)
		data->key.key_ri = 0;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * HEIGHT + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (pars(av, ac, fd) == 0)
		return (0);
	data = init_map(fd, 0);
	cube3d(&data);
	init_xpm(&data);
	mlx_hook(data.win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, &key_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
}
