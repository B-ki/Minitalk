/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:06:10 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 15:04:35 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(t_conv *stock)
{
	int	size;

	size = 0;
	if (!stock->point || stock->i_point > (int)ft_strlen(stock->arg_str))
		size = ft_strlen(stock->arg_str);
	else
		size = stock->i_point;
	if (stock->width == 0)
		stock->width = size;
	if (!stock->minus)
	{
		if (stock->width > size)
			print_str_no_minus_width(stock, size);
		else
			ft_putstr_ret(stock->arg_str, size);
	}
	else if (stock->minus)
	{
		if (stock->width > size)
			print_str_minus_width(stock, size);
		else
			ft_putstr_ret(stock->arg_str, size);
	}
	return ;
}

void	print_str_no_minus_width(t_conv *stock, int size)
{
	while (stock->width > size)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	ft_putstr_ret(stock->arg_str, size);
	return ;
}

void	print_str_minus_width(t_conv *stock, int size)
{
	ft_putstr_ret(stock->arg_str, size);
	while (stock->width > size)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	return ;
}
