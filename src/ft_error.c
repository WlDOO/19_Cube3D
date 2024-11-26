/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:23:33 by sadegrae          #+#    #+#             */
/*   Updated: 2024/11/26 22:12:00 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_map(t_data *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S')
				count++;
			else if (game->map[i][j] == 'E' || game->map[i][j] == 'W')
				count++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
			{
				if (game->map[i][j] != 32 && game->map[i][j] != '\t')
					return (0);
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

