/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:43:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/21 17:36:01 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern t_mess	g_m;

void	send_message(char *bin, pid_t pid, int end_mess)
{
	int	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	i = 0;
	if (end_mess == 1)
	{
		while (i <= 7)
		{
			kill(pid, SIGUSR1);
			i++;
			usleep(100);
		}
	}
}

void	send_signal(pid_t pid, int sig)
{
	static int	try;

	if (sig == SIGUSR1)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_all();
	}
	if (sig == SIGUSR2)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit_all();
	}
	if (usleep(100000) == 0)
	{
		try++;
		if (try == 3)
			exit_all();
	}
	try = 0;
	usleep(100);
}

void	exit_all(void)
{
	ft_printf("Server's acknowledgement not received !\n");
	free(g_m.size);
	free(g_m.mess);
	exit(1);
}
