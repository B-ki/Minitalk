/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:47:55 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/21 17:35:58 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_stock	g_st;

int	size_bin_char(char *msg)
{
	int	i;
	int	z_count;

	i = 0;
	z_count = 0;
	while (msg[i] && z_count < 8)
	{
		if (msg[i] == '1')
			z_count = 0;
		else if (msg[i] == '0')
			z_count++;
		i++;
	}
	return (i / 8);
}

char	*bin_to_str(char *msg)
{
	char	*str;
	int		i;
	int		b_count;

	str = malloc(sizeof(char) * (size_bin_char(msg) + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size_bin_char(msg));
	i = 0;
	b_count = 7;
	while (i < size_bin_char(msg))
	{
		while (b_count >= 0)
		{
			if (msg[i * 8 + b_count] == '1')
				str[i] += 1 << (7 - b_count);
			b_count--;
		}
		i++;
		b_count = 7;
	}
	str[i] = '\0';
	return (str);
}

void	refresh_global(void)
{
	int	i;

	i = -1;
	g_st.pidclient = 0;
	g_st.i = 0;
	free(g_st.message);
	g_st.message = NULL;
	if (g_st.size_mess)
		free(g_st.size_mess);
	g_st.size_mess = malloc(sizeof(char) * (32 + 1));
	if (!g_st.size_mess)
		exit(1);
	while (++i < 32)
		g_st.size_mess[i] = 0;
	g_st.size_mess[32] = '\0';
	return ;
}

void	malloc_message(void)
{
	g_st.message = malloc(sizeof(char) * (bin_to_int(g_st.size_mess) * 8 + 1));
	if (!g_st.message)
		exit(1);
}
