/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:53:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/11/26 22:34:37 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	pars_map_text(t_data *game)
{
	int	i;
	int	j;
	int	k;
	
	j = 0;
	i = 0;
	k = 0;
	while (game->map2[i])
	{
		if (game->map2[i] && game->map2[i][j] && (game->map2[i][j] == '1' || game->map2[i][j] == '0' || game->map2[i][j] == ' '))
		{
			while (game->map2[i + k] && (game->map2[i + k][0] == '1' || game->map2[i + k][0] == '0' || game->map2[i + k][0] == ' '))
				k++;
			game->map = malloc(sizeof(char *) * (k + 1));
			k = 0;
			while (game->map2[i] && (game->map2[i][0] == '1' || game->map2[i][0] == '0' || game->map2[i][0] == ' '))
			{
				game->map[k] = ft_strdup(game->map2[i]);
				printf("deux ; <%s>\n", game->map[k]);
				k++;
				i++;
			}
			game->map[k] = NULL;
			printf("deux ; <%s>\n", game->map[k]);
			while (game->map2[i])
			{
				printf("premierrrr ; <%s>\n", game->map2[i]);
				i++;
			}
		}
		else
		{
			while (game->map2[i] && game->map2[i][0] != '1' && game->map2[i][0] != '0' && game->map2[i][0] != ' ')
			{
				printf("premierrrr ; <%s>\n", game->map2[i]);
				i++;
			}
			while (game->map2[i + k] && (game->map2[i + k][0] == '1' || game->map2[i + k][0] == '0' || game->map2[i + k][0] == ' '))
				k++;
			game->map = malloc(sizeof(char *) * (k + 1));
			k = 0;
			while (game->map2[i] && (game->map2[i][0] == '1' || game->map2[i][0] == '0' || game->map2[i][0] == ' '))
			{
				game->map[k] = ft_strdup(game->map2[i]);
				printf("deux ; <%s>\n", game->map[k]);
				k++;
				i++;
			}
			game->map[k] = NULL;
			printf("deux ; <%s>\n", game->map[k]);
			while (game->map2[i])
			{
				printf("premierrrr ; <%s>\n", game->map2[i]);
				i++;
			}
		}
	}
}
