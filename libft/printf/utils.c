/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:41:39 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:35:11 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isconvert(char c)
{
	if (!c)
		return (0);
	else if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	else
		return (0);
}

int	ft_isnumeric(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_check_nonum_before(const char *s, int i)
{
	while (s[i] != '%')
	{
		if (ft_isnumeric(s[i]))
			return (0);
		i--;
	}
	return (1);
}

int	max_two_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	max_stock(t_conv *stock, int size_num)
{
	int	ret;

	ret = 0;
	if (stock->space || stock->plus || stock->arg_i < 0)
		ret++;
	ret = ret + max_two_int(stock->i_point, size_num);
	return (ret);
}
