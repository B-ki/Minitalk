/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:33:38 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/27 16:48:42 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_ret(int c, int fd, int a)
{
	static int	ret = 0;
	int			reset;

	reset = 0;
	if (a)
	{
		write (fd, &c, 1);
		ret++;
		return (ret);
	}
	else
	{
		reset = ret;
		ret = 0;
		return (reset);
	}
}

void	ft_putstr_ret(char *s, int size)
{
	int	i;

	i = 0;
	while (s && s[i] && i < size)
	{
		ft_putchar_ret(s[i], 1, 1);
		i++;
	}
	return ;
}

void	ft_putnbr_base(unsigned long int i, char *base, t_conv *stock)
{
	unsigned long int	s_base;

	s_base = ft_strlen(base);
	if (stock->n_case == ' ')
	{
		ft_putchar_ret(' ', 1, 1);
		return ;
	}
	if (stock->n_case == 'n')
		return ;
	if (i >= s_base)
	{
		ft_putnbr_base(i / s_base, base, stock);
		ft_putnbr_base(i % s_base, base, stock);
	}
	else
		ft_putchar_ret(base[i], 1, 1);
	return ;
}

void	ft_putnbr(long int i, t_conv *stock)
{
	long long int	l;

	l = i;
	if (stock->n_case == ' ')
	{
		ft_putchar_ret(' ', 1, 1);
		return ;
	}
	if (stock->n_case == 'n')
		return ;
	if (l < 0)
	{
		l *= -1;
		ft_putchar_ret('-', 1, 1);
	}
	if (l >= 10)
	{
		ft_putnbr(l / 10, stock);
		ft_putnbr(l % 10, stock);
	}
	else
		ft_putchar_ret(l + 48, 1, 1);
	return ;
}

void	ft_putunbr(unsigned int i, t_conv *stock)
{
	if (stock->n_case == ' ')
	{
		ft_putchar_ret(' ', 1, 1);
		return ;
	}
	if (stock->n_case == 'n')
		return ;
	if (i >= 10)
	{
		ft_putunbr(i / 10, stock);
		ft_putunbr(i % 10, stock);
	}
	else
		ft_putchar_ret(i + 48, 1, 1);
	return ;
}
