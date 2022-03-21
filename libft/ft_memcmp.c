/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:37:47 by rmorel            #+#    #+#             */
/*   Updated: 2021/11/25 17:02:39 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*i1;
	const unsigned char	*i2;

	i1 = (const unsigned char *)s1;
	i2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i1[i] == i2[i] && i < n - 1)
		i++;
	return (i1[i] - i2[i]);
}
