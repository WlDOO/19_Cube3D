/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:08:34 by sadegrae          #+#    #+#             */
/*   Updated: 2024/11/26 22:25:09 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	f_f(char *str, char c, int t)
{
	int	i;

	i = -1;
	if (t == 1)
	{
		if (str)
			free(str);
		str = NULL;
		return (0);
	}
	else
	{
		if (!str)
			return (0);
		while (str[++i])
			if (str[i] == c)
				return (1);
		return (0);
	}
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest || !s1)
	{
		f_f(dest, '1', 1);
		f_f(s1, '1', 1);
		return (NULL);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strchr2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i])
				return (ft_strdup(&str[i]));
			else
				return (NULL);
		}
		i++;
	}
	return (&str[0]);
}


int	pars(char **av,int ac, int fd)
{
	if (ac != 2)
		return (printf("Error\nArguments invalid\n"), 0);
	if (fd < 0)
		return (printf("Error\nMap invalid\n"), 0);
	if (ft_strcmp(ft_strchr2(av[1]), "cub") != 0)
		return (printf("Error\nMap invalid\n"), 0);
	return (1);
}

int	pars_map(t_data *game)
{
	pars_map_text(game);
	if (check_border2(game,0 ,0 ,0) == 0)
		return (printf("Error\nMap invalid\n"), 0);
	if (check_border(game, 0, 0) == 0)
		return (printf("Error\nMap invalid\n"), 0);
	if (check_map(game) == 0)
		return (printf("Error\nMap invalid\n"), 0);
	return (1);
}
