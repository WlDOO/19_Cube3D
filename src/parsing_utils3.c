/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:52:40 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/11 18:45:30 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	*ft_putchar_next(char *tmp, char *str, int i, char c)
{
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

char	*ft_putchar(char c, char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strlen(str) == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[i] = c;
		str[i + 1] = '\0';
	}
	else
		str = ft_putchar_next(tmp, str, i, c);
	return (str);
}

char	*ft_puthex(long long nbr, char *str)
{
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	len = 16;
	if (len > nbr)
	{
		str = ft_putchar(base[nbr], str, 0);
	}
	else
	{
		str = ft_puthex((nbr / len), str);
		str = ft_putchar(base[nbr % len], str, 0);
	}
	return (str);
}

void	skip_space(t_data *game, int i, int *j)
{
	while (game->map2[i][*j] != ' ' && !(game->map2[i][*j] >= 9
			&& game->map2[i][*j] <= 13))
		*j = *j + 1;
	while (game->map2[i][*j] == ' ' || (game->map2[i][*j] >= 9
			&& game->map2[i][*j] <= 13))
		*j = *j + 1;
}

void	skip_virgule_space(t_data *game, int i, int *j, int *start)
{
	while (game->map2[i][*j] != ' ')
		*j = *j + 1;
	while (game->map2[i][*j] == ' ')
		*j = *j + 1;
	*start = *j;
	while (game->map2[i][*j] != ',')
		*j = *j + 1;
}
