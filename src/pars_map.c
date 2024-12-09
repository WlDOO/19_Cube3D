/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:53:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/09 19:55:20 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include <stdbool.h>

void	recup_texture_comp_we_ea(t_data *game, int i, int *j)
{
	if (ft_strncmp(game->map2[i], "WE", 2) == 0)
	{
		skip_space(game, i, j);
		if (game->recup.wo)
			free(game->recup.wo);
		game->recup.wo = ft_strdup(&game->map2[i][*j]);
	}
	else if (ft_strncmp(game->map2[i], "EA", 2) == 0)
	{
		skip_space(game, i, j);
		if (game->recup.eo)
			free(game->recup.eo);
		game->recup.eo = ft_strdup(&game->map2[i][*j]);
	}
}

void	recup_texture_compass(t_data *game, int i, int *j)
{
	if (ft_strncmp(game->map2[i], "NO", 2) == 0)
	{
		skip_space(game, i, j);
		if (game->recup.no)
			free(game->recup.no);
		game->recup.no = ft_strdup(&game->map2[i][*j]);
	}
	else if (ft_strncmp(game->map2[i], "SO", 2) == 0)
	{
		skip_space(game, i, j);
		if (game->recup.so)
			free(game->recup.so);
		game->recup.so = ft_strdup(&game->map2[i][*j]);
	}
	recup_texture_comp_we_ea(game, i, j);
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
		if (!tmp)
			return ;
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
		if (!tmp)
			return ;
		tmp[0] = '0';
		tmp[1] = game->recup.c[game->k][0];
		tmp[2] = '\0';
		free(game->recup.c[game->k]);
		game->recup.c[game->k] = ft_strdup(tmp);
		free(tmp);
	}
}
