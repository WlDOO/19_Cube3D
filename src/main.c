/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:37:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/14 16:48:41 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * 1080 + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	cube3d(t_data *data)
{
	int		x;
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
	double 	sideDistX;
	double 	sideDistY;
	double 	deltaDistY;
	double 	deltaDistX;
	double	perpWallDist;

	hit = 0;
	x = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Cube3D");
	data->img.img = mlx_new_image(data->mlx, 1920, 1080);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	mapX = (int)data->pl_x;
	mapY = (int)data->pl_y;
	//calculer le raytracing
	while (x < 1920)
	{
		cameraX = 2 * x / 1920 - 1;
		raydirX = data->dirX + data->planeX * cameraX; //position X de la camera
		raydirY = data->dirY + data->planeY * cameraX; //position Y de la camera
		if (raydirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1.0 / raydirX);
		if (raydirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1.0 / raydirY);
		if (raydirX < 0)
		{
			stepX = -1;
			sideDistX = (data->pl_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->pl_x) * deltaDistX;
		}
		if (raydirY < 0)
		{
			stepY = -1;
			sideDistY = (data->pl_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->pl_y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map[mapX][mapY] == '1')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		lineHeight = 1080 / perpWallDist;
		drawStart = -1 * lineHeight / 2 + 1080 / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawend = lineHeight / 2 + 1080 / 2;
		if (drawend >= 1080)
			drawend = 1080 - 1;
		//choose wall color
		switch(data->map[mapX][mapY])
		{
			case 1:  color = RGB_Red;  break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}
		if (side == 1)
			color = color / 2;
		x++;
		int	y = 0;
		while (y < 1080)
		{
			my_mlx_pixel_put(data, y, x, color);
			y++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	//-----------//
	mlx_loop(data->mlx);
}
int	main(int ac, char **av)
{
	t_data data;
	int	fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	data = init_map(fd);
	cube3d(&data);
	printf("x = %f, y = %f\n", data.pl_x, data.pl_y);
}