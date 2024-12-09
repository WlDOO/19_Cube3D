/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:52:43 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/09 19:55:24 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	free_map2(t_data *game)
{
	int	i;

	i = 0;
	while (game->map2[i])
	{
		free(game->map2[i]);
		i++;
	}
	free(game->map2[i]);
}

void	texture_wall2(char *tmp, t_data *game)
{
	tmp = malloc(sizeof(char) * 3);
	if (!tmp)
		return ;
	tmp[0] = '0';
	tmp[1] = game->recup.c[2][0];
	tmp[2] = '\0';
	free(game->recup.c[2]);
	game->recup.c[2] = ft_strdup(tmp);
	free(tmp);
}

void	texture_wall(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = NULL;
	game->recup.c = malloc(sizeof(char *) * 5);
	if (!game->recup.c)
		return ;
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
		texture_wall2(tmp, game);
}

void	texture_floor2(char *tmp, t_data *game)
{
	tmp = malloc(sizeof(char) * 3);
	if (!tmp)
		return ;
	tmp[0] = '0';
	tmp[1] = game->recup.f[2][0];
	tmp[2] = '\0';
	free(game->recup.f[2]);
	game->recup.f[2] = ft_strdup(tmp);
	free(tmp);
}

void	texture_floor(t_data *game, int i, int j, int start)
{
	char	*tmp;

	tmp = NULL;
	game->recup.f = malloc(sizeof(char *) * 5);
	if (!game->recup.f)
		return ;
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
		texture_floor2(tmp, game);
}
