/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:50:19 by najeuneh          #+#    #+#             */
/*   Updated: 2024/10/22 15:58:29 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	raycasting(t_data *data, int x)
{
	data->ray.mapX = (int)data->pl_x;
	data->ray.mapY = (int)data->pl_y;
	data->ray.hit = 0;
	data->ray.cameraX = (2 * (double)x / (double)1920 - 1);
	data->ray.raydirX = data->dirX + data->planeX * data->ray.cameraX; //position X de la camera
	data->ray.raydirY = data->dirY + data->planeY * data->ray.cameraX; //position Y de la camera
	if (data->ray.raydirX == 0)
		data->ray.deltaDistX = 1e30;
	else
		data->ray.deltaDistX = fabs(1.0 / data->ray.raydirX);
	if (data->ray.raydirY == 0)
		data->ray.deltaDistY = 1e30;
	else
	data->ray.deltaDistY = fabs(1.0 / data->ray.raydirY);
	if (data->ray.raydirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->pl_x - data->ray.mapX) * data->ray.deltaDistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapX + 1.0 - data->pl_x) * data->ray.deltaDistX;
	}
}

void	raycasting_suite(t_data *data)
{
	if (data->ray.raydirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->pl_y - data->ray.mapY) * data->ray.deltaDistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapY + 1.0 - data->pl_y) * data->ray.deltaDistY;
	}
}

void	ray_while_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX += data->ray.deltaDistX;
			data->ray.mapX += data->ray.stepX;
			data->ray.side = 0;
			if (data->ray.raydirX > 0)
				data->ray.side = 1;
		}
		else
		{
			data->ray.sideDistY += data->ray.deltaDistY;
			data->ray.mapY += data->ray.stepY;
			data->ray.side = 2;
			if (data->ray.raydirY > 0)
				data->ray.side = 3;
		}
		if (data->map[data->ray.mapY][data->ray.mapX] == '1')
			data->ray.hit = 1;
	}
	if (data->ray.side == 0 || data->ray.side == 1)
		data->ray.perpWallDist = data->ray.sideDistX - data->ray.deltaDistX;
	else
		data->ray.perpWallDist = data->ray.sideDistY - data->ray.deltaDistY;
	data->ray.lineHeight = 1080 / data->ray.perpWallDist;
	data->ray.drawStart = -1 * data->ray.lineHeight / 2 + 1080 / 2;
	if (data->ray.drawStart < 0)
		data->ray.drawStart = 0;
}
