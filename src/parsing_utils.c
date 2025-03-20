/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:44:44 by sadegrae          #+#    #+#             */
/*   Updated: 2024/12/04 19:49:16 by sadegrae         ###   ########.fr       */
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

char	*ft_strndup(char *s1, int n)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (len < n && s1[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest || !s1)
	{
		f_f(dest, '1', 1);
		f_f(s1, '1', 1);
		return (NULL);
	}
	while (i < n && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
				return (&str[i]);
			else
				return (NULL);
		}
		i++;
	}
	return (&str[0]);
}
