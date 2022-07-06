/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:39:02 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/21 17:22:55 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_stock		g_st = {0, 0, NULL, NULL};

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	refresh_global();
	pid = getpid();
	ft_printf("PID is : %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_printf("Erreur de signal SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_printf("Erreur de signal SIGUSR2");
	while (1)
	{
		pause();
		if (check_end())
			print_string();
	}
	return (0);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	g_st.pidclient = info->si_pid;
	if (g_st.i <= 31)
	{
		if (signo == SIGUSR1)
			g_st.size_mess[g_st.i] = '0';
		else
			g_st.size_mess[g_st.i] = '1';
		if (kill(g_st.pidclient, SIGUSR2) == -1)
			ft_printf("Cannot reach back client !");
	}
	else if (g_st.i >= 32)
	{
		if (signo == SIGUSR1)
			g_st.message[g_st.i - 32] = '0';
		else if (signo == SIGUSR2)
			g_st.message[g_st.i - 32] = '1';
		if (kill(g_st.pidclient, SIGUSR2) == -1)
			ft_printf("Cannot reach back client !");
	}
	if (g_st.i == 31)
		malloc_message();
	g_st.i += 1;
}

int	bin_to_int(char *str)
{
	int	i;
	int	b_count;

	i = 0;
	b_count = 31;
	while (b_count >= 0)
	{
		if (str[b_count] == '1')
			i += 1 << (31 - b_count);
		b_count--;
	}
	return (i + 1);
}

int	check_end(void)
{
	int	i;
	int	count;

	i = g_st.i - 32;
	if (g_st.i < 39)
		return (0);
	count = 0;
	if (i > 0 && i % 8 == 0)
	{
		i = i - 8;
		while (i < g_st.i - 32)
		{
			if (g_st.message[i] == '0')
				count++;
			i++;
		}
		if (count == 8)
		{
			if (kill(g_st.pidclient, SIGUSR1) == -1)
				ft_printf("Cant send signal to client");
			return (1);
		}
	}
	return (0);
}

void	print_string(void)
{
	char	*str;

	str = NULL;
	str = bin_to_str(g_st.message);
	ft_printf("%s\n", str);
	free(str);
	refresh_global();
	return ;
}
