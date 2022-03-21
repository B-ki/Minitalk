/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:36:05 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:55:13 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size_hex_ulp(unsigned long int ul_p, t_conv *stock)
{
	int	i;

	i = 0;
	if (stock->n_case == 'n')
		return (0);
	if (ul_p == 0)
		return (1);
	while (ul_p)
	{
		ul_p = ul_p / 16;
		i++;
	}
	return (i);
}

int	get_size_all_int(t_conv *stock)
{
	int	ret;
	int	i;

	ret = 0;
	i = stock->arg_i;
	if (stock->arg_i == 0 && (stock->plus || stock->space))
		return (2);
	if (stock->arg_i == 0)
		return (1);
	if (i < 0)
		ret++;
	else if (stock->plus || stock->space)
		ret++;
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

int	get_size_only_num(t_conv *stock)
{
	int	ret;
	int	i;

	ret = 0;
	i = stock->arg_i;
	if (stock->n_case == 'n')
		return (0);
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

int	get_size_u(t_conv *stock)
{
	int				ret;
	unsigned int	i;

	ret = 0;
	i = stock->arg_u;
	if (stock->n_case == 'n')
		return (0);
	if (stock->arg_u == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}
