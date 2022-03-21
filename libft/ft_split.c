/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:56:44 by rmorel            #+#    #+#             */
/*   Updated: 2021/11/30 16:08:33 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strtocr(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static int	ft_strsize(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_freeall(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static char	**ft_fillsplit(char const *s, char c, char **dest)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			dest[j] = malloc(sizeof(char) * (ft_strsize(s + i, c) + 1));
			if (!dest[j])
			{
				ft_freeall(dest);
				return (0);
			}
			ft_strlcpy(dest[j], &s[i], ft_strsize(s + i, c) + 1);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (0);
	dest = malloc(sizeof(*dest) * (ft_strtocr(s, c) + 1));
	if (!dest)
	{
		free (dest);
		return (0);
	}
	ft_fillsplit(s, c, dest);
	return (dest);
}
