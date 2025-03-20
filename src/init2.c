/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:45:53 by najeuneh          #+#    #+#             */
/*   Updated: 2024/12/10 17:39:03 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init4_xpm(t_data *data)
{
	data->recup.texture[S].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.so, &data->recup.texture[S].height,
			&data->recup.texture[S].width);
	if (!data->recup.texture[S].img_ptr)
	{
		printf("Error texture\n");
		exit(1);
	}
	data->recup.texture[S].img_pixels_ptr
		= mlx_get_data_addr(data->recup.texture[S].img_ptr,
			&(data->recup.texture[S].bits_per_pixel),
			&(data->recup.texture[S].size_line),
			&(data->recup.texture[S].endian));
}

void	init3_xpm(t_data *data)
{
	data->recup.texture[E].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.eo, &data->recup.texture[E].height,
			&data->recup.texture[E].width);
	if (!data->recup.texture[E].img_ptr)
	{
		printf("Error texture\n");
		exit(1);
	}
	data->recup.texture[E].img_pixels_ptr
		= mlx_get_data_addr(data->recup.texture[E].img_ptr,
			&(data->recup.texture[E].bits_per_pixel),
			&(data->recup.texture[E].size_line),
			&(data->recup.texture[E].endian));
}

void	init2_xpm(t_data *data)
{
	data->recup.texture[W].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.wo, &data->recup.texture[W].height,
			&data->recup.texture[W].width);
	if (!data->recup.texture[W].img_ptr)
	{
		printf("Error texture\n");
		exit(1);
	}
	data->recup.texture[W].img_pixels_ptr
		= mlx_get_data_addr(data->recup.texture[W].img_ptr,
			&(data->recup.texture[W].bits_per_pixel),
			&(data->recup.texture[W].size_line),
			&(data->recup.texture[W].endian));
}

void	init_xpm(t_data *data)
{
	data->recup.texture[N].img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->recup.no, &data->recup.texture[N].height,
			&data->recup.texture[N].width);
	if (!data->recup.texture[N].img_ptr)
	{
		printf("Error texture\n");
		exit(1);
	}
	data->recup.texture[N].img_pixels_ptr
		= mlx_get_data_addr(data->recup.texture[N].img_ptr,
			&(data->recup.texture[N].bits_per_pixel),
			&(data->recup.texture[N].size_line),
			&(data->recup.texture[N].endian));
	init2_xpm(data);
	init3_xpm(data);
	init4_xpm(data);
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
