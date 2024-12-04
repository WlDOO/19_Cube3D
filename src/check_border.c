/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:01:56 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/04 17:50:29 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_border(t_data *game, int i, int j)
{
	int	start;
	int	last;

	start = 0;
	last = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			while (game->map[i][j] == ' ')
				j++;
			start = j;
			while (game->map[i][j] != ' ' && game->map[i][j] != '\0'
				&& game->map[i][j] != '\n')
				j++;
			last = j - 1;
			if (game->map[i][start] != '1' || game->map[i][last] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_border2(t_data *game, int j, int i, int start)
{
	int	last;

	last = 0;
	while (game->map[i] && game->map[i][j])
	{
		while (game->map[i])
		{
			while (game->map[i] && game->map[i][j] == 32)
				i++;
			if (game->map[i] && game->map[i][j] && game->map[i][j] != ' ')
			{
				start = i;
				while (game->map[i] && game->map[i][j]
					&& game->map[i][j] != ' ')
					i++;
				last = i - 1;
				if (game->map[start][j] != '1' || game->map[last][j] != '1')
					return (0);
			}
			if (game->map[i] && !game->map[i][j])
				i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
