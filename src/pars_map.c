/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:53:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/04 20:02:59 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	recup_texture_compass(t_data *game, int i, int *j)
{
	if (ft_strncmp(game->map2[i], "NO", 2) == 0)
	{
		skip_space(game, i, j);
		game->recup.no = ft_strdup(&game->map2[i][*j]);
	}
	else if (ft_strncmp(game->map2[i], "SO", 2) == 0)
	{
		skip_space(game, i, j);
		game->recup.so = ft_strdup(&game->map2[i][*j]);
	}
	else if (ft_strncmp(game->map2[i], "WE", 2) == 0)
	{
		skip_space(game, i, j);
		game->recup.wo = ft_strdup(&game->map2[i][*j]);
	}
	else if (ft_strncmp(game->map2[i], "EA", 2) == 0)
	{
		skip_space(game, i, j);
		game->recup.eo = ft_strdup(&game->map2[i][*j]);
	}
}

void	temp_texture(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = ft_strndup(&game->map2[i][start], j - start);
	game->recup.f[game->k] = ft_puthex(ft_atoi(tmp), NULL);
	free(tmp);
	if (ft_strlen(game->recup.f[0]) == 1)
	{
		tmp = malloc(sizeof(char) * 3);
		tmp[0] = '0';
		tmp[1] = game->recup.f[game->k][0];
		tmp[2] = '\0';
		free(game->recup.f[game->k]);
		game->recup.f[game->k] = ft_strdup(tmp);
		free(tmp);
	}
}

void	temp_texture_wall(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = ft_strndup(&game->map2[i][start], j - start);
	game->recup.c[game->k] = ft_puthex(ft_atoi(tmp), NULL);
	free(tmp);
	if (ft_strlen(game->recup.c[0]) == 1)
	{
		tmp = malloc(sizeof(char) * 3);
		tmp[0] = '0';
		tmp[1] = game->recup.c[game->k][0];
		tmp[2] = '\0';
		free(game->recup.c[game->k]);
		game->recup.c[game->k] = ft_strdup(tmp);
		free(tmp);
	}
}

void	texture_wall(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = NULL;
	game->recup.c = malloc(sizeof(char *) * 5);
	skip_virgule_space(game, i, &j, &start);
	game->k = 0;
	temp_texture_wall(game, i, j, start);
	start = ++j;
	while (game->map2[i][j] != ',')
		j++;
	game->k = 1;
	temp_texture_wall(game, i, j, start);
	tmp = ft_strdup(&game->map2[i][++j]);
	game->recup.c[2] = ft_puthex(ft_atoi(tmp), NULL);
	free(tmp);
	if (ft_strlen(game->recup.c[2]) == 1)
	{
		tmp = malloc(sizeof(char) * 3);
		tmp[0] = '0';
		tmp[1] = game->recup.c[2][0];
		tmp[2] = '\0';
		free(game->recup.c[2]);
		game->recup.c[2] = ft_strdup(tmp);
		free(tmp);
	}
}

void	texture_floor(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = NULL;
	game->recup.f = malloc(sizeof(char *) * 5);
	skip_virgule_space(game, i, &j, &start);
	game->k = 0;
	temp_texture(game, i, j, start);
	start = ++j;
	while (game->map2[i][j] != ',')
		j++;
	game->k = 1;
	temp_texture(game, i, j, start);
	tmp = ft_strdup(&game->map2[i][++j]);
	game->recup.f[2] = ft_puthex(ft_atoi(tmp), NULL);
	free(tmp);
	if (ft_strlen(game->recup.f[2]) == 1)
	{
		tmp = malloc(sizeof(char) * 3);
		tmp[0] = '0';
		tmp[1] = game->recup.f[2][0];
		tmp[2] = '\0';
		free(game->recup.f[2]);
		game->recup.f[2] = ft_strdup(tmp);
		free(tmp);
	}
}
