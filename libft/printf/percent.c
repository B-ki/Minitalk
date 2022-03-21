/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:09:44 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 17:51:58 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_percent(t_conv *stock)
{
	if (!stock->minus && stock->width > 1)
	{
		while (stock->width > 1)
		{
			if (stock->zero)
				ft_putchar_ret('0', 1, 1);
			else
				ft_putchar_ret(' ', 1, 1);
			stock->width--;
		}
		ft_putchar_ret(stock->convert, 1, 1);
	}
	else if (stock->minus && stock->width > 1)
	{
		ft_putchar_ret(stock->convert, 1, 1);
		stock->width--;
		while (stock->width > 0)
		{
			ft_putchar_ret(' ', 1, 1);
			stock->width--;
		}
	}
	else
		ft_putchar_ret(stock->convert, 1, 1);
	return ;
}
