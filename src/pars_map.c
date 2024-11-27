/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:53:21 by sadegrae          #+#    #+#             */
/*   Updated: 2024/11/27 06:10:11 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int hexa_to_deci(char *hex) 
{
    int decimal = 0, base = 1, len, i, value;

    len = ft_strlen(hex);
    i = len - 1;
	while (i >= 0)
	{
        if(hex[i] >= '0' && hex[i] <= '9') 
		{
            value = hex[i] - '0';
        } 
		else if(hex[i] >= 'A' && hex[i] <= 'F') 
		{
            value = hex[i] - 'A' + 10;
        }
        decimal += value * base;
        base = base * 16;
		i--;
	}
    return (decimal);
}

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
static int	check_arg(const char *str, int i)
{
	if ((str[i] == '-' && ft_strncmp(str, "-9223372036854775808", 21) > 0)
		|| ((str[i] == '+' || str[i] == '-')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		|| !(str[i] == '+' || str[i] == '-'
			|| (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((ft_strncmp(str, "9223372036854775807", 19) > 0)
		&& ft_strlen((char *)str) > 19 && str[i] >= '0' && str[i] <= '9')
		return (2);
	return (0);
}

int	ft_atoi(const char *str1)
{
	int		i;
	int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str1[i] == 32 || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (check_arg(str1, i) == 1)
		return (0);
	if (check_arg(str1, i) == 2)
		return (-1);
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str1[i++] - 48);
	}
	return (nb * sign);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_putchar(char c, char *str)
{
	int i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (ft_strlen(str) == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[i] = c;
		str[i + 1] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
		while(str[i])
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_puthex(int nbr, char *str)
{
	int	len;
	char 			*base;

	base = "0123456789ABCDEF";
	len = 16;
	if (len > nbr)
	{
		str = ft_putchar(base[nbr], str); 
	}
	else
	{
		str = ft_puthex((nbr / len), str);
		str = ft_putchar(base[nbr % len], str);
	}
	return (str);
}


void	recup_texture(t_data *game)
{
	int	i;
	int	j;
	int	start;
	char *str;
	
	str = NULL;
	start = 0;
	j = 0;
	i = 0;
	while (game->map2[i])
	{
		j = 0;
		if (ft_strncmp(game->map2[i], "NO", 2) == 0)
		{
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			game->recup.no = ft_strdup(&game->map2[i][j]);
			printf("recup no = <%s>\n", game->recup.no);
		}
		else if (ft_strncmp(game->map2[i], "SO", 2) == 0)
		{
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			game->recup.so = ft_strdup(&game->map2[i][j]);
			printf("recup so = <%s>\n", game->recup.so);
		}
		else if (ft_strncmp(game->map2[i], "WE", 2) == 0)
		{
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			game->recup.wo = ft_strdup(&game->map2[i][j]);
			printf("recup wo = <%s>\n", game->recup.wo);
		}
		else if (ft_strncmp(game->map2[i], "EA", 2) == 0)
		{
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			game->recup.eo = ft_strdup(&game->map2[i][j]);
			printf("recup eo = <%s>\n", game->recup.eo);
		}
		else if (ft_strncmp(game->map2[i], "F ", 2) == 0)
		{
			game->recup.f = malloc(sizeof(char *) * 5);
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			start = j;
			while (game->map2[i][j] != ',')
				j++;
			game->recup.f[0] = ft_puthex(ft_atoi(ft_strndup(&game->map2[i][start], j - start)), NULL);
			if (ft_strlen(game->recup.f[0]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.f[0][0];
				tmp[2] = '\0';
				free(game->recup.f[0]);
				game->recup.f[0] = tmp;
			}
			printf("recup f[0] = <%s>\n", game->recup.f[0]);
			j++;
			start = j;
			while (game->map2[i][j] != ',')
				j++;
			game->recup.f[1] = ft_puthex(ft_atoi(ft_strndup(&game->map2[i][start], j - start)), NULL);
			if (ft_strlen(game->recup.f[1]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.f[1][0];
				tmp[2] = '\0';
				free(game->recup.f[1]);
				game->recup.f[1] = tmp;
			}
			printf("recup f[1] = <%s>\n", game->recup.f[1]);
			j++;
			game->recup.f[2] = ft_puthex(ft_atoi(ft_strdup(&game->map2[i][j])), NULL);
			if (ft_strlen(game->recup.f[2]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.f[2][0];
				tmp[2] = '\0';
				free(game->recup.f[2]);
				game->recup.f[2] = tmp;
			}
			printf("recup f[2] = <%s>\n", game->recup.f[2]);
			game->recup.f[3] = ft_strjoin(game->recup.f[0], game->recup.f[1]);
			game->recup.f[3] = ft_strjoin(game->recup.f[3], game->recup.f[2]);
			game->recup.color_plafon = hexa_to_deci(game->recup.f[3]);
			printf("recup f final = <%d>\n", hexa_to_deci(game->recup.f[3]));
		}
		else if (ft_strncmp(game->map2[i], "C ", 2) == 0)
		{
			game->recup.c = malloc(sizeof(char *) * 5);
			while (game->map2[i][j] != ' ')
				j++;
			while (game->map2[i][j] == ' ')
				j++;
			start = j;
			while (game->map2[i][j] != ',')
				j++;
			game->recup.c[0] = ft_puthex(ft_atoi(ft_strndup(&game->map2[i][start], j - start)), NULL);
			if (ft_strlen(game->recup.c[0]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.c[0][0];
				tmp[2] = '\0';
				free(game->recup.c[0]);
				game->recup.c[0] = tmp;
			}
			printf("recup c[0] = <%s>\n", game->recup.c[0]);
			j++;
			start = j;
			while (game->map2[i][j] != ',')
				j++;
			game->recup.c[1] = ft_puthex(ft_atoi(ft_strndup(&game->map2[i][start], j - start)), NULL);
			if (ft_strlen(game->recup.c[1]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.c[1][0];
				tmp[2] = '\0';
				free(game->recup.c[1]);
				game->recup.c[1] = tmp;
			}
			printf("recup c[1] = <%s>\n", game->recup.c[1]);
			j++;
			game->recup.c[2] = ft_puthex(ft_atoi(ft_strdup(&game->map2[i][j])), NULL);
			if (ft_strlen(game->recup.c[2]) == 1)
			{
				char *tmp;
				tmp = malloc(sizeof(char) * 3);
				tmp[0] = '0';
				tmp[1] = game->recup.c[2][0];
				tmp[2] = '\0';
				free(game->recup.c[2]);
				game->recup.c[2] = tmp;
			}
			printf("recup c[2] = <%s>\n", game->recup.c[2]);
			game->recup.c[3] = ft_strjoin(game->recup.c[0], game->recup.c[1]);
			game->recup.c[3] = ft_strjoin(game->recup.c[3], game->recup.c[2]);
			game->recup.color_sol = hexa_to_deci(game->recup.c[3]);
			printf("recup c final = <%d>\n",  hexa_to_deci(game->recup.c[3]));
		}
		i++;
	}
}

void	pars_map_text(t_data *game)
{
	int	i;
	int	j;
	int	k;
	
	j = 0;
	i = 0;
	k = 0;
	recup_texture(game);
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
			{
				i++;
			}
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
