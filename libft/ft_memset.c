/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:04:17 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 18:39:10 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ps;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		ps[i] = uc;
		i++;
	}
	return (ps);
}
