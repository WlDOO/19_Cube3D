/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:08:34 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/04 19:45:29 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	pars(char **av, int ac, int fd)
{
	if (ac != 2)
		return (printf("Error\nArguments invalid\n"), 0);
	if (fd < 0)
		return (printf("Error\nMap invalid\n"), 0);
	if (ft_strcmp(ft_strchr2(av[1]), "cub") != 0)
		return (printf("Error\nMap invalid\n"), 0);
	return (1);
}

void	free_struct(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map[i]);
	return ;
}

int	pars_map(t_data *game)
{
	pars_map_text(game, 0, 0, 0);
	if (check_border2(game, 0, 0, 0) == 0)
		return (free_struct(game), printf("Error\nMap invalid\n"), 0);
	if (check_border(game, 0, 0) == 0)
		return (free_struct(game), printf("Error\nMap invalid\n"), 0);
	if (check_map(game) == 0)
		return (free_struct(game), printf("Error\nMap invalid\n"), 0);
	return (1);
}
