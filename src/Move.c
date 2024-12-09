/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:11:09 by najeuneh          #+#    #+#             */
/*   Updated: 2024/12/09 19:56:59 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	key_move4(t_data *data, double angle)
{
	if (data->key.key_ri)
	{
		angle = 0.03;
		data->newdirx = data->dirx * cos(angle) - data->diry * sin(angle);
		data->newdiry = data->dirx * sin(angle) + data->diry * cos(angle);
		data->new_planex = data->planex * cos(angle) - data->planey
			* sin(angle);
		data->new_planey = data->planex * sin(angle) + data->planey
			* cos(angle);
		data->dirx = data->newdirx;
		data->diry = data->newdiry;
		data->planex = data->new_planex;
		data->planey = data->new_planey;
	}
}

void	key_move3(t_data *data, double angle)
{
	if (data->key.key_le)
	{
		angle = -0.03;
		data->newdirx = data->dirx * cos(angle) - data->diry * sin(angle);
		data->newdiry = data->dirx * sin(angle) + data->diry * cos(angle);
		data->new_planex = data->planex * cos(angle) - data->planey
			* sin(angle);
		data->new_planey = data->planex * sin(angle) + data->planey
			* cos(angle);
		data->dirx = data->newdirx;
		data->diry = data->newdiry;
		data->planex = data->new_planex;
		data->planey = data->new_planey;
	}
	else
		key_move4(data, angle);
}

void	key_move2(t_data *data, double angle)
{
	if (data->key.key_d == 1)
	{
		if (data->map[(int)(data->pl_y + data->planey * (0.1
					+ 0.01))][(int)data->pl_x] != '1')
			data->pl_y += data->planey * 0.1;
		if (data->map[(int)data->pl_y][(int)(data->pl_x + data->planex * (0.1
				+ 0.01))] != '1')
			data->pl_x += data->planex * 0.1;
	}
	else if (data->key.key_a == 1)
	{
		if (data->map[(int)(data->pl_y - data->planey * (0.1
					+ 0.01))][(int)data->pl_x] != '1')
			data->pl_y -= data->planey * 0.1;
		if (data->map[(int)data->pl_y][(int)(data->pl_x - data->planex * (0.1
				+ 0.01))] != '1')
			data->pl_x -= data->planex * 0.1;
	}
	else if (data->key.key_esc)
	{
		clean_all(data);
		exit(0);
	}
	else
		key_move3(data, angle);
}

void	key_move(t_data *data)
{
	double	angle;

	angle = 0.0;
	if (data->key.key_w == 1)
	{
		if (data->map[(int)(data->pl_y + data->diry * (0.1
					+ 0.01))][(int)data->pl_x] != '1')
			data->pl_y += data->diry * 0.1;
		if (data->map[(int)data->pl_y][(int)(data->pl_x + data->dirx * (0.1
				+ 0.01))] != '1')
			data->pl_x += data->dirx * 0.1;
	}
	else if (data->key.key_s == 1)
	{
		if (data->map[(int)(data->pl_y - data->diry * (0.1
					+ 0.01))][(int)data->pl_x] != '1')
			data->pl_y -= data->diry * 0.1;
		if (data->map[(int)data->pl_y][(int)(data->pl_x - data->dirx * (0.1
				+ 0.01))] != '1')
			data->pl_x -= data->dirx * 0.1;
	}
	else
		key_move2(data, angle);
}

int	close_window(t_data *data)
{
	clean_all(data);
	system("leaks cube3d");
	exit(0);
}
