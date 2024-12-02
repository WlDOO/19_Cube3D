/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:01:28 by najeuneh          #+#    #+#             */
/*   Updated: 2024/12/02 13:46:06 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	clean_all(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->recup.texture[W].img_ptr);
	mlx_destroy_image(data->mlx, data->recup.texture[E].img_ptr);
	mlx_destroy_image(data->mlx, data->recup.texture[N].img_ptr);
	mlx_destroy_image(data->mlx, data->recup.texture[S].img_ptr);
}
