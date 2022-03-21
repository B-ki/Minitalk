/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:43:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/11 19:01:11 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_message(char *bin, pid_t pid, int end_mess)
{
	int	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
		{
			send_signal(pid, SIGUSR1);
			ft_printf("bin[%d] : 0\n", i);
		}
		else
		{
			send_signal(pid, SIGUSR2);
			ft_printf("bin[%d] : 1\n", i);
		}
		usleep(1000);
		i++;
	}
	i = 0;
	if (end_mess == 1)
	{
		while (i <= 7)
		{
			kill(pid, SIGUSR1);
			i++;
			usleep(1000);
		}
	}
}

void	send_signal(pid_t pid, int sig)
{
	static int	try;

	if (sig == SIGUSR1)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
		ft_printf("SIGUSR1\n");
	}
	if (sig == SIGUSR2)
	{
		if (kill(pid, SIGUSR2) == -1)
		    exit(1);
		ft_printf("SIGUSR2\n");
	}
	if (usleep(100000) == 0)
	{
		try++;
		if (try == 3)
		{
			ft_printf("Acknowledgement signal not received");
			exit(1);
		}
		send_signal(pid, sig);
	}
	try = 0;
	usleep(100);
}
