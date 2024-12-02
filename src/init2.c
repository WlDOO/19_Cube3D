/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:45:53 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/29 17:52:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init2_xpm(t_data *data)
{
	data->recup.texture[S].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.so, &data->recup.texture[S].height,
			&data->recup.texture[S].width);
	data->recup.texture[S].img_pixels_ptr = mlx_get_data_addr
		(data->recup.texture[S].img_ptr,
			&(data->recup.texture[S].bits_per_pixel),
			&(data->recup.texture[S].size_line),
			&(data->recup.texture[S].endian));
}

void	init_xpm(t_data *data)
{
	data->recup.texture[N].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.no, &data->recup.texture[N].height,
			&data->recup.texture[N].width);
	data->recup.texture[N].img_pixels_ptr = mlx_get_data_addr
		(data->recup.texture[N].img_ptr,
			&(data->recup.texture[N].bits_per_pixel),
			&(data->recup.texture[N].size_line),
			&(data->recup.texture[N].endian));
	data->recup.texture[W].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.wo, &data->recup.texture[W].height,
			&data->recup.texture[W].width);
	data->recup.texture[W].img_pixels_ptr = mlx_get_data_addr
		(data->recup.texture[W].img_ptr,
			&(data->recup.texture[W].bits_per_pixel),
			&(data->recup.texture[W].size_line),
			&(data->recup.texture[W].endian));
	data->recup.texture[E].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.eo, &data->recup.texture[E].height,
			&data->recup.texture[E].width);
	data->recup.texture[E].img_pixels_ptr = mlx_get_data_addr
		(data->recup.texture[E].img_ptr,
			&(data->recup.texture[E].bits_per_pixel),
			&(data->recup.texture[E].size_line),
			&(data->recup.texture[E].endian));
	init2_xpm(data);
}

void	look_dir(t_data *data)
{
	if (data->map[(int)data->pl_y][(int)data->pl_x] == 'N')
	{
		data->dirx = 0;
		data->diry = -1;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'S')
	{
		data->dirx = 0;
		data->diry = 1;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'E')
	{
		data->dirx = 1;
		data->diry = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'W')
	{
		data->dirx = -1;
		data->diry = 0;
	}
}

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
