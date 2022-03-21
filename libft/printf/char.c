/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:19:32 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 16:15:08 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char(t_conv *stock)
{
	if (!stock->minus && stock->width > 1)
	{
		while (stock->width > 1)
		{
			ft_putchar_ret(' ', 1, 1);
			stock->width--;
		}
		ft_putchar_ret(stock->arg_c, 1, 1);
	}
	else if (stock->minus && stock->width > 1)
	{
		ft_putchar_ret(stock->arg_c, 1, 1);
		stock->width--;
		while (stock->width > 0)
		{
			ft_putchar_ret(' ', 1, 1);
			stock->width--;
		}
	}
	else
		ft_putchar_ret(stock->arg_c, 1, 1);
	return ;
}
