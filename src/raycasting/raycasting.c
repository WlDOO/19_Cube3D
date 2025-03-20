/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:50:19 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/29 15:45:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	raycasting(t_data *data, int x)
{
	data->ray.hit = 0;
	data->ray.camerax = (2 * (double)x / (double)WIDTH - 1);
	data->ray.raydirx = data->dirx + data->planex * data->ray.camerax;
	data->ray.raydiry = data->diry + data->planey * data->ray.camerax;
	if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1e30;
	else
		data->ray.deltadistx = fabs(1.0 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1e30;
	else
		data->ray.deltadisty = fabs(1.0 / data->ray.raydiry);
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->pl_x - data->ray.mapx)
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->pl_x)
			* data->ray.deltadistx;
	}
}

void	raycasting_suite(t_data *data)
{
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->pl_y - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->pl_y)
			* data->ray.deltadisty;
	}
}

void	ray_while_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = W;
			if (data->ray.raydirx > 0)
				data->ray.side = E;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = N;
			if (data->ray.raydiry > 0)
				data->ray.side = S;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
	if (data->ray.side == 0 || data->ray.side == 1)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltadistx;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltadisty;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

void	cube3d(t_data *data)
{
	data->img.width = 64;
	data->img.height = 64;
	data->recup.texture[0].width = 64;
	data->recup.texture[0].height = 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}
