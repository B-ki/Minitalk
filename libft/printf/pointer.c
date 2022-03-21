/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:20:46 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:53:21 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_p(t_conv *stock)
{
	unsigned long int	ul_p;
	int					size;

	ul_p = (unsigned long int)stock->arg_p;
	size = 2 + get_size_hex_ulp(ul_p, stock);
	if (stock->width == 0)
		stock->width = size;
	if (!stock->minus && stock->width >= size)
		print_p_no_minus(stock, size, ul_p);
	else if (stock->minus && stock->width >= size)
		print_p_minus(stock, size, ul_p);
	else
	{
		ft_putstr_ret("0x", 2);
		ft_putnbr_base(ul_p, "0123456789abcdef", stock);
	}
	return ;
}

void	print_p_no_minus(t_conv *stock, int size, unsigned long int ul_p)
{
	while (stock->width > size)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	ft_putstr_ret("0x", 2);
	ft_putnbr_base(ul_p, "0123456789abcdef", stock);
	return ;
}

void	print_p_minus(t_conv *stock, int size, unsigned long int ul_p)
{
	ft_putstr_ret("0x", 2);
	ft_putnbr_base(ul_p, "0123456789abcdef", stock);
	while (stock->width > size)
	{
		ft_putchar_ret(' ', 1, 1);
		stock->width--;
	}
	return ;
}
