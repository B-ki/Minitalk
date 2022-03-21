/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:31:41 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:50:47 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_stock_all(va_list args, const char *s, t_conv *stock)
{
	fill_stock1(s, stock);
	fill_stock2(s, stock);
	if (stock->convert == 'c')
		stock->arg_c = va_arg (args, int);
	else if (stock->convert == 's')
	{		
		stock->arg_str = va_arg (args, char *);
		if (!stock->arg_str)
			stock->arg_str = "(null)";
	}
	else if (stock->convert == 'p')
		stock->arg_p = va_arg (args, void *);
	else if (stock->convert == 'u')
		stock->arg_u = va_arg (args, unsigned int);
	else if (stock->convert == 'x')
		stock->arg_u = va_arg (args, int);
	else if (stock->convert == 'X')
		stock->arg_u = va_arg (args, int);
	else if (stock->convert == 'i' || stock->convert == 'd')
		stock->arg_i = va_arg (args, int);
	fill_stock_null(stock);
	return ;
}

/* On commence fill_stock un caractere apres le % */
void	fill_stock1(const char *s, t_conv *stock)
{
	int	i;

	i = 0;
	while (s && s[i] && !ft_isconvert(s[i]))
	{
		if (s[i] == '#')
			stock->hashtag = '#';
		else if (s[i] == '+')
			stock->plus = '+';
		else if (s[i] == '-')
			stock->minus = '-';
		else if (s[i] == ' ')
			stock->space = ' ';
		else if (s[i] == '0')
		{
			if (ft_check_nonum_before(s, i - 1))
				stock->zero = '0';
		}
		i++;
	}
	stock->convert = s[i];
	return ;
}

void	fill_stock2(const char *s, t_conv *stock)
{
	int	i;

	i = 0;
	while (s && s[i] && !ft_isconvert(s[i]))
	{
		if (ft_isnumeric(s[i]) && stock->point != '.')
		{
			stock->width = ft_atoi(&s[i]);
			while (ft_isnumeric(s[i]))
				i++;
		}
		if (s[i] == '.')
		{
			stock->point = '.';
			i++;
			if (ft_isnumeric(s[i]))
			{
				stock->i_point = ft_atoi(&s[i]);
				while (ft_isnumeric(s[i]))
					i++;
			}
		}
		i++;
	}
	return ;
}

void	newstock(t_conv *stock)
{
	stock->hashtag = '\0';
	stock->space = '\0';
	stock->plus = '\0';
	stock->minus = '\0';
	stock->zero = '\0';
	stock->point = '\0';
	stock->i_point = 0;
	stock->width = 0;
	stock->convert = '\0';
	stock->arg_c = 0;
	stock->arg_str = NULL;
	stock->arg_p = NULL;
	stock->arg_i = 0;
	stock->arg_u = 0;
	stock->n_case = '\0';
	return ;
}

void	fill_stock_null(t_conv *stock)
{
	if (!stock->arg_i && !stock->arg_u)
	{
		if (stock->plus || stock->space)
		{
			if (stock->width > 0 && stock->point && stock->i_point == 0)
				stock->n_case = 'n';
		}
		else if (stock->width > 0 && stock->point && stock->i_point == 0)
			stock->n_case = ' ';
		if (stock->width == 0 && stock->point && stock->i_point == 0)
			stock->n_case = 'n';
	}
	return ;
}
