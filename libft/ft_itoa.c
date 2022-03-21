/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:32:56 by rmorel            #+#    #+#             */
/*   Updated: 2021/11/30 16:07:51 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenb(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		size += 1;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	ln;
	char		*dest;

	ln = n;
	i = ft_sizenb(n);
	dest = malloc(sizeof(*dest) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	dest[0] = '0';
	if (ln == 0)
		return (dest);
	if (ln < 0)
	{
		ln *= -1;
		dest[0] = '-';
	}
	while (ln > 0)
	{
		dest[i - 1] = ln % 10 + 48;
		ln /= 10;
		i--;
	}
	return (dest);
}
