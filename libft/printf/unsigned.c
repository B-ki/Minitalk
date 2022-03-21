/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:19:42 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 13:55:29 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_u(t_conv *stock)
{
	int	size_num;
	int	max;

	size_num = get_size_u(stock);
	max = max_two_int(size_num, stock->i_point);
	if (stock->minus)
	{
		if (stock->width)
			print_ui_minus_width(stock, size_num, max);
		else if (!stock->width)
			print_ui_minus(stock, size_num);
	}
	else if (!stock->minus)
	{
		if (stock->zero && !stock->point)
			print_ui_zero_no_point(stock, size_num);
		else
			print_ui_no_zero(stock, size_num, max);
	}
	return ;
}

void	print_ui_minus_width(t_conv *stock, int size_num, int max)
{
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_u, stock);
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	return ;
}

void	print_ui_minus(t_conv *stock, int size_num)
{
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_u, stock);
	return ;
}

void	print_ui_zero_no_point(t_conv *stock, int size_num)
{
	while (stock->width - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->width--;
	}
	ft_putnbr(stock->arg_u, stock);
	return ;
}

void	print_ui_no_zero(t_conv *stock, int size_num, int max)
{
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_u, stock);
	return ;
}
