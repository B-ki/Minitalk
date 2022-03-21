/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:58:15 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 16:36:21 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_convert(va_list args, const char *s)
{
	t_conv	stock;

	newstock(&stock);
	fill_stock_all(args, s, &stock);
	if (stock.convert)
		print_stock(&stock);
	return ;
}

void	print_stock(t_conv *stock)
{
	if (stock->convert == 'c')
		print_char(stock);
	else if (stock->convert == 's')
		print_str(stock);
	else if (stock->convert == 'p')
		print_p(stock);
	else if (stock->convert == 'd')
		print_d_i(stock);
	else if (stock->convert == 'i')
		print_d_i(stock);
	else if (stock->convert == 'u')
		print_u(stock);
	else if (stock->convert == 'x')
		print_x(stock, "0123456789abcdef");
	else if (stock->convert == 'X')
		print_x(stock, "0123456789ABCDEF");
	else if (stock->convert == '%')
		print_percent(stock);
	return ;
}

int	print_all(va_list args, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			ft_putchar_ret(s[i], 1, 1);
			i++;
		}
		if (s[i] && s[i] == '%')
		{
			i++;
			print_convert(args, &s[i]);
			while (s[i] && !ft_isconvert(s[i]))
				i++;
		}
		if (s[i])
			i++;
	}
	return (ft_putchar_ret(1, 1, 0));
}
