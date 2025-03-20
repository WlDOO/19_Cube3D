/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:38:55 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/10 17:39:14 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	look_plane(t_data *data)
{
	if (data->map[(int)data->pl_y][(int)data->pl_x] == 'N')
	{
		data->planex = 0.66;
		data->planey = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'S')
	{
		data->planex = -0.66;
		data->planey = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'E')
	{
		data->planex = 0;
		data->planey = 0.66;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'W')
	{
		data->planex = 0;
		data->planey = -0.66;
	}
	data->pl_x += 0.5;
	data->pl_y += 0.5;
}

void	initvalue(t_data *data)
{
	data->ray.stepx = 0;
	data->ray.stepy = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.mapy = 0;
	data->ray.mapx = 0;
	data->ray.drawstart = 0;
	data->ray.drawend = 0;
	data->ray.lineheight = 0;
	data->ray.color = 0;
	data->ray.camerax = 0;
	data->ray.raydirx = 0;
	data->ray.raydiry = 0;
	data->ray.sidedistx = 0;
	data->ray.sidedisty = 0;
	data->ray.deltadisty = 0;
	data->ray.deltadistx = 0;
	data->ray.perpwalldist = 0;
	data->key.key_ri = 0;
	data->key.key_le = 0;
	data->key.key_w = 0;
	data->key.key_s = 0;
	data->key.key_a = 0;
	data->key.key_d = 0;
	data->key.key_esc = 0;
}
