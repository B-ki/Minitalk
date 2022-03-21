/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:07:50 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:42:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_d_i(t_conv *stock)
{
	int	size_all;
	int	size_num;
	int	max;

	size_all = get_size_all_int(stock);
	size_num = get_size_only_num(stock);
	max = max_stock(stock, size_num);
	if (stock->minus)
	{
		if (stock->width)
			print_int_minus_width(stock, size_num, max);
		else if (!stock->width)
			print_int_minus(stock, size_num);
	}
	else if (!stock->minus)
	{
		if (stock->zero && !stock->point)
			print_int_zero_no_point(stock, size_all);
		else
			print_int_no_zero(stock, max, size_num);
	}
}

void	print_int_minus_width(t_conv *stock, int size_num, int max)
{
	if (stock->plus && stock->arg_i >= 0)
		ft_putchar_ret('+', 1, 1);
	else if (stock->space && stock->arg_i >= 0)
		ft_putchar_ret(' ', 1, 1);
	if (stock->arg_i < 0)
	{
		ft_putchar_ret('-', 1, 1);
		stock->arg_i *= -1;
	}
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_i, stock);
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	return ;
}

void	print_int_minus(t_conv *stock, int size_num)
{
	if (stock->plus && stock->arg_i >= 0)
		ft_putchar_ret('+', 1, 1);
	else if (stock->space && stock->arg_i >= 0)
		ft_putchar_ret(' ', 1, 1);
	if (stock->arg_i < 0)
	{
		ft_putchar_ret('-', 1, 1);
		stock->arg_i *= -1;
	}
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_i, stock);
	return ;
}

void	print_int_zero_no_point(t_conv *stock, int size_all)
{
	if (stock->plus && stock->arg_i >= 0)
		ft_putchar_ret('+', 1, 1);
	else if (stock->space && stock->arg_i >= 0)
		ft_putchar_ret(' ', 1, 1);
	else if (stock->arg_i < 0)
	{
		ft_putchar_ret('-', 1, 1);
		stock->arg_i *= -1;
	}
	while (stock->width - size_all > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->width--;
	}
	ft_putnbr(stock->arg_i, stock);
	return ;
}

void	print_int_no_zero(t_conv *stock, int max, int size_num)
{
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	if (stock->plus && stock->arg_i >= 0)
		ft_putchar_ret('+', 1, 1);
	else if (stock->space && stock->arg_i >= 0)
		ft_putchar_ret(' ', 1, 1);
	else if (stock->arg_i < 0)
	{
		ft_putchar_ret('-', 1, 1);
		stock->arg_i *= -1;
	}
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr(stock->arg_i, stock);
	return ;
}
