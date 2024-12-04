/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:51:36 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/04 19:56:55 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	hexa_to_deci(char *hex)
{
	int	decimal;
	int	base;
	int	i;
	int	value;

	base = 1;
	decimal = 0;
	i = ft_strlen(hex) - 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			value = hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			value = hex[i] - 'A' + 10;
		decimal += value * base;
		base = base * 16;
		i--;
	}
	return (decimal);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*st1;
	char	*st2;

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
		|| ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0'
				&& str[i + 1] <= '9')) || !(str[i] == '+' || str[i] == '-'
			|| (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((ft_strncmp(str, "9223372036854775807", 19) > 0)
		&& ft_strlen((char *)str) > 19 && str[i] >= '0' && str[i] <= '9')
		return (2);
	return (0);
}

int	ft_atoi(const char *str1)
{
	int	i;
	int	nb;
	int	sign;

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
