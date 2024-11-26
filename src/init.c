/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:25:44 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/26 21:43:25 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	look_dir(t_data *data)
{
	if (data->map[(int)data->pl_y][(int)data->pl_x] == 'N')
	{
		data->dirX = 0;
		data->dirY = -1;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'S')
	{
		data->dirX = 0;
		data->dirY = 1;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'E')
	{
		data->dirX = 1;
		data->dirY = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'W')
	{
		data->dirX = -1;
		data->dirY = 0;
	}
}

void	look_plane(t_data *data)
{
	if (data->map[(int)data->pl_y][(int)data->pl_x] == 'N')
	{
		data->planeX = 0.66;
		data->planeY = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'S')
	{
		data->planeX = -0.66;
		data->planeY = 0;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'E')
	{
		data->planeX = 0;
		data->planeY = 0.66;
	}
	else if (data->map[(int)data->pl_y][(int)data->pl_x] == 'W')
	{
		data->planeX = 0;
		data->planeY = -0.66;
	}	
}

size_t	ft_strlen2(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	str = (char *)s;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = (ft_strlen2(s1) + ft_strlen2(s2));
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (free(str), free(s1), NULL);
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}

char	*recup_map(int fd)
{
	char	*line;
	char	*buffer;
	int		bs;

	bs = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (line);
	while (bs >= 0)
	{
		bs = read(fd, buffer, 1);
		if (bs == -1)
			return (free(buffer), free(line), NULL);
		if (bs == 0)
			break ;
		buffer[bs] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	line = ft_strjoin(line, buffer);
	close(fd);
	return (free(buffer), line);
}

void	player_pos(char *line, t_data *data)
{
	int	i;

	data->pl_x = 0;
	data->pl_y = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			break ;
		else if (line[i] == '\n')
		{
			data->pl_x = 0;
			data->pl_y++;
		}
		else
		{
			data->pl_x++;
		}
	}
}

t_data	init_map(int map, int x)
{
	t_data	data;
	int		y;

	y = 0;
	data.ray.stepX = 0;
	data.ray.stepY = 0;
	data.ray.hit = 0;
	data.ray.side = 0;
	data.ray.mapY = 0;
	data.ray.mapX = 0;
	data.ray.drawStart = 0;
	data.ray.drawend = 0;
	data.ray.lineHeight = 0;
	data.ray.color = 0;
	data.ray.cameraX = 0;
	data.ray.raydirX = 0;
	data.ray.raydirY = 0;
	data.ray.sideDistX = 0;
	data.ray.sideDistY = 0;
	data.ray.deltaDistY = 0;
	data.ray.deltaDistX = 0;
	data.ray.perpWallDist = 0;
	data.key.key_R = 0;
	data.key.key_L = 0;
	data.key.key_w = 0;
	data.key.key_s = 0;
	data.key.key_a = 0;
	data.key.key_d = 0;
	data.key.key_esc = 0;
	data.ray.color = RGB_Blue;
	data.line = recup_map(map);
	data.map = ft_split(data.line, '\n');
	while (data.map[y][x])
		x++;
	data.map_x = x;
	while (data.map[y])
		y++;
	data.map_y = y;
	player_pos(data.line, &data);
	look_dir(&data);
	look_plane(&data);
	data.pl_x += 0.5;
	data.pl_y += 0.5;
	return (data);
}
