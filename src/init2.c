/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:45:53 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/29 14:03:08 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_xpm(t_data *data)
{
	data->recup.texture[N].img_ptr = mlx_xpm_file_to_image(data->mlx, data->recup.no, &data->recup.texture[N].height, &data->recup.texture[N].width);
	data->recup.texture[N].img_pixels_ptr = mlx_get_data_addr(data->recup.texture[N].img_ptr, &(data->recup.texture[N].bits_per_pixel), &(data->recup.texture[N].size_line), &(data->recup.texture[N].endian));
	data->recup.texture[W].img_ptr = mlx_xpm_file_to_image(data->mlx, data->recup.no, &data->recup.texture[W].height, &data->recup.texture[W].width);
	data->recup.texture[W].img_pixels_ptr = mlx_get_data_addr(data->recup.texture[W].img_ptr, &(data->recup.texture[W].bits_per_pixel), &(data->recup.texture[W].size_line), &(data->recup.texture[W].endian));
	data->recup.texture[E].img_ptr = mlx_xpm_file_to_image(data->mlx, data->recup.eo, &data->recup.texture[E].height, &data->recup.texture[E].width);
	data->recup.texture[E].img_pixels_ptr = mlx_get_data_addr(data->recup.texture[E].img_ptr, &(data->recup.texture[E].bits_per_pixel), &(data->recup.texture[E].size_line), &(data->recup.texture[E].endian));
	data->recup.texture[S].img_ptr = mlx_xpm_file_to_image(data->mlx, data->recup.so, &data->recup.texture[S].height, &data->recup.texture[S].width);
	data->recup.texture[S].img_pixels_ptr = mlx_get_data_addr(data->recup.texture[S].img_ptr, &(data->recup.texture[S].bits_per_pixel), &(data->recup.texture[S].size_line), &(data->recup.texture[S].endian));
}