/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:03:14 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/09 19:43:55 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	recup_texture_wall_floor(t_data *game, int i, int j, int start)
{
	if (ft_strncmp(game->map2[i], "F ", 2) == 0)
	{
		texture_floor(game, i, j, start);
		game->recup.f[3] = ft_strjoin(game->recup.f[0], game->recup.f[1]);
		game->recup.f[3] = ft_strjoin(game->recup.f[3], game->recup.f[2]);
		game->recup.color_plafon = hexa_to_deci(game->recup.f[3]);
		free(game->recup.f[1]);
		free(game->recup.f[2]);
		free(game->recup.f[3]);
	}
	else if (ft_strncmp(game->map2[i], "C ", 2) == 0)
	{
		texture_wall(game, i, j, start);
		game->recup.c[3] = ft_strjoin(game->recup.c[0], game->recup.c[1]);
		game->recup.c[3] = ft_strjoin(game->recup.c[3], game->recup.c[2]);
		game->recup.color_sol = hexa_to_deci(game->recup.c[3]);
		free(game->recup.c[1]);
		free(game->recup.c[2]);
		free(game->recup.c[3]);
	}
}

void	recup_texture(t_data *game, int i, int j, int start)
{
	while (game->map2[i])
	{
		j = 0;
		recup_texture_compass(game, i, &j);
		recup_texture_wall_floor(game, i, j, start);
		i++;
	}
}

void	pars_map_attr(t_data *game, int *i, int *k)
{
	while (game->map2[*i + *k] && (game->map2[*i + *k][0] == '1'
		|| game->map2[*i + *k][0] == '0' || game->map2[*i + *k][0] == ' '))
	{
		*k = *k + 1;
	}
	game->map = malloc(sizeof(char *) * (*k + 1));
	if (!game->map)
		return ;
	*k = 0;
	while (game->map2[*i] && (game->map2[*i][0] == '1'
		|| game->map2[*i][0] == '0' || game->map2[*i][0] == ' '))
	{
		game->map[*k] = ft_strdup(game->map2[*i]);
		*k = *k + 1;
		*i = *i + 1;
	}
	game->map[*k] = NULL;
	while (game->map2[*i])
		*i = *i + 1;
}

void	pars_map_other_attr(t_data *game, int *i, int *k)
{
	while (game->map2[*i] && game->map2[*i][0] != '1'
		&& game->map2[*i][0] != '0' && game->map2[*i][0] != ' ')
		*i = *i + 1;
	while (game->map2[*i + *k] && (game->map2[*i + *k][0] == '1'
		|| game->map2[*i + *k][0] == '0' || game->map2[*i + *k][0] == ' '))
		*k = *k + 1;
	game->map = malloc(sizeof(char *) * (*k + 1));
	if (!game->map)
		return ;
	*k = 0;
	while (game->map2[*i] && (game->map2[*i][0] == '1'
		|| game->map2[*i][0] == '0' || game->map2[*i][0] == ' '))
	{
		game->map[*k] = ft_strdup(game->map2[*i]);
		*k = *k + 1;
		*i = *i + 1;
	}
	game->map[*k] = NULL;
	while (game->map2[*i])
		*i = *i + 1;
}

void	pars_map_text(t_data *game, int i, int j, int k)
{
	recup_texture(game, 0, 0, 0);
	while (game->map2[i])
	{
		if (game->map2[i] && game->map2[i][j] && (game->map2[i][j] == '1'
				|| game->map2[i][j] == '0' || game->map2[i][j] == ' '))
		{
			pars_map_attr(game, &i, &k);
		}
		else
		{
			pars_map_other_attr(game, &i, &k);
		}
	}
	free_map2(game);
}
