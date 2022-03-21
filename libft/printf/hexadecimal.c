/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:10 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:55:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_x(t_conv *stock, char *base)
{
	int	size_num;
	int	max;

	size_num = get_size_hex_ulp(stock->arg_u, stock);
	max = max_two_int(size_num, stock->i_point);
	if (stock->hashtag && stock->width && stock->arg_u)
		stock->width -= 2;
	if (stock->minus)
	{
		if (stock->width)
			print_hex_minus_width(stock, size_num, max, base);
		else if (!stock->width)
			print_hex_minus(stock, size_num, base);
	}
	else if (!stock->minus)
	{
		if (stock->zero && !stock->point)
			print_hex_zero_no_point(stock, size_num, base);
		else
			print_hex_no_zero(stock, size_num, max, base);
	}
	return ;
}

void	print_hex_minus_width(t_conv *stock, int size_num, int max, char *base)
{
	if (stock->hashtag && stock->arg_u && stock->convert == 'x')
		ft_putstr_ret("0x", 2);
	else if (stock->hashtag && stock->arg_u && stock->convert == 'X')
		ft_putstr_ret("0X", 2);
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr_base(stock->arg_u, base, stock);
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	return ;
}

void	print_hex_minus(t_conv *stock, int size_num, char *base)
{
	if (stock->hashtag && stock->arg_u && stock->convert == 'x')
		ft_putstr_ret("0x", 2);
	else if (stock->hashtag && stock->arg_u && stock->convert == 'X')
		ft_putstr_ret("0X", 2);
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr_base(stock->arg_u, base, stock);
	return ;
}

void	print_hex_zero_no_point(t_conv *stock, int size_num, char *base)
{
	if (stock->hashtag && stock->arg_u && stock->convert == 'x')
		ft_putstr_ret("0x", 2);
	else if (stock->hashtag && stock->arg_u && stock->convert == 'X')
		ft_putstr_ret("0X", 2);
	while (stock->width - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->width--;
	}
	ft_putnbr_base(stock->arg_u, base, stock);
	return ;
}

void	print_hex_no_zero(t_conv *stock, int size_num, int max, char *base)
{
	while (stock->width - max > 0)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	if (stock->hashtag && stock->arg_u && stock->convert == 'x')
		ft_putstr_ret("0x", 2);
	else if (stock->hashtag && stock->arg_u && stock->convert == 'X')
		ft_putstr_ret("0X", 2);
	while (stock->i_point - size_num > 0)
	{
		ft_putchar_ret('0', 1, 1);
		stock->i_point--;
	}
	ft_putnbr_base(stock->arg_u, base, stock);
	return ;
}
