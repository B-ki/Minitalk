/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:14:07 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 18:37:19 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_uc;

	p_uc = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n > 1)
	{
		if (*p_uc == (unsigned char)c)
			return ((void *)p_uc);
		n--;
		p_uc++;
	}
	if (*p_uc == (unsigned char)c)
		return ((void *)p_uc);
	return (NULL);
}
