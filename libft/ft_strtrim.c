/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:13:28 by rmorel            #+#    #+#             */
/*   Updated: 2021/11/30 16:06:12 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_belong(char c, const char *s)
{
	int	i;

	i = 0;
	if (!c || !s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	j = 0;
	k = -1;
	if (!s1)
		return (0);
	while (s1[i] && ft_belong(s1[i], set))
		i++;
	while (s1[i + j])
		j++;
	while (ft_belong(s1[i + j - 1], set) && j > 0)
		j--;
	dest = malloc (sizeof(*dest) * (j + 1));
	if (!dest)
		return (0);
	while (++k < j)
		dest[k] = s1[i + k];
	dest[k] = '\0';
	return (dest);
}
