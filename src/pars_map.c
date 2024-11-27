/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:53:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/11/27 03:43:53 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// void	ft_puthex(int nbr)
// {
// 	int				size;
// 	unsigned int	len;
// 	char 			*base;

// 	base = "0123456789ABCDEF"
// 	size = 0;
// 	len = 16;
// 	if (len > nbr)
// 	{
// 		ft_putchar(base[nbr]); 
// 	}
// 	else
// 	{
// 		ft_puthex((nbr / len), base);
// 		ft_putchar(base[nbr % len]);
// 	}

// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*st1;
	char		*st2;

	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] && st1[i] == st2[i] && i < n - 1)
		i++;
	if ((unsigned char)st1[i] > (unsigned char)st2[i])
		return (1);
	else if ((unsigned char)st1[i] < (unsigned char)st2[i])
		return (-1);
	else
		return (0);
}

// void	recup_texture(t_data *game)
// {
// 	int	i;
// 	int	j;
// 	int	start;
	
// 	start = 0;
// 	j = 0;
// 	i = 0;
// 	while (game->map2[i])
// 	{
// 		j = 0;
// 		if (ft_strncmp(game->map2[i], "NO", 2) == 0)
// 		{
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			game->recup.no = ft_strdup(&game->map2[i][j]);
// 			printf("recup no = <%s>\n", game->recup.no);
// 		}
// 		else if (ft_strncmp(game->map2[i], "SO", 2) == 0)
// 		{
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			game->recup.so = ft_strdup(&game->map2[i][j]);
// 			printf("recup so = <%s>\n", game->recup.so);
// 		}
// 		else if (ft_strncmp(game->map2[i], "WE", 2) == 0)
// 		{
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			game->recup.wo = ft_strdup(&game->map2[i][j]);
// 			printf("recup wo = <%s>\n", game->recup.wo);
// 		}
// 		else if (ft_strncmp(game->map2[i], "EA", 2) == 0)
// 		{
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			game->recup.eo = ft_strdup(&game->map2[i][j]);
// 			printf("recup eo = <%s>\n", game->recup.eo);
// 		}
// 		else if (ft_strncmp(game->map2[i], "F ", 2) == 0)
// 		{
// 			game->recup.f = malloc(sizeof(char *) * 4);
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			start = j;
// 			while (game->map2[i][j] != ',')
// 				j++;
// 			game->recup.f[0] = ft_strndup(ft_puthex(&game->map2[i][start], j - start));
// 			printf("recup f[0] = <%s>\n", game->recup.f[0]);
// 			j++;
// 			start = j;
// 			while (game->map2[i][j] != ',')
// 				j++;
// 			game->recup.f[1] = ft_strndup(ft_puthex(&game->map2[i][start], j - start));
// 			printf("recup f[1] = <%s>\n", game->recup.f[1]);
// 			j++;
// 			game->recup.f[2] = ft_strdup(ft_puthex(&game->map2[i][start]));
// 			printf("recup f[2] = <%s>\n", game->recup.f[2]);
// 		}
// 		else if (ft_strncmp(game->map2[i], "C ", 2) == 0)
// 		{
// 			game->recup.c = malloc(sizeof(char *) * 4);
// 			while (game->map2[i][j] != ' ')
// 				j++;
// 			while (game->map2[i][j] == ' ')
// 				j++;
// 			start = j;
// 			while (game->map2[i][j] != ',')
// 				j++;
// 			game->recup.c[0] = ft_strndup(&game->map2[i][start], j - start);
// 			printf("recup c[0] = <%s>\n", game->recup.c[0]);
// 			j++;
// 			start = j;
// 			while (game->map2[i][j] != ',')
// 				j++;
// 			game->recup.c[1] = ft_strndup(&game->map2[i][start], j - start);
// 			printf("recup c[1] = <%s>\n", game->recup.c[1]);
// 			j++;
// 			game->recup.c[2] = ft_strdup(&game->map2[i][j]);
// 			printf("recup c[2] = <%s>\n", game->recup.c[2]);
// 		}
// 		i++;
// 	}
// }

void	pars_map_text(t_data *game)
{
	int	i;
	int	j;
	int	k;
	
	j = 0;
	i = 0;
	k = 0;
	//recup_texture(game);
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
				k++;
				i++;
			}
			game->map[k] = NULL;
			while (game->map2[i])
				i++;
		}
		else
		{
			while (game->map2[i] && game->map2[i][0] != '1' && game->map2[i][0] != '0' && game->map2[i][0] != ' ')
				i++;
			while (game->map2[i + k] && (game->map2[i + k][0] == '1' || game->map2[i + k][0] == '0' || game->map2[i + k][0] == ' '))
				k++;
			game->map = malloc(sizeof(char *) * (k + 1));
			k = 0;
			while (game->map2[i] && (game->map2[i][0] == '1' || game->map2[i][0] == '0' || game->map2[i][0] == ' '))
			{
				game->map[k] = ft_strdup(game->map2[i]);
				k++;
				i++;
			}
			game->map[k] = NULL;
			while (game->map2[i])
				i++;
		}
	}
}
