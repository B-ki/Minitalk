/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:30 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/21 17:30:00 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"

/* CLIENT.C */
void	error(void);
char	*binary_converter(char *str);
void	handler(int signum);
char	*int_to_bin(int n);

/* CLIENT_UTILS.C */
void	send_message(char *bin, pid_t pid, int end_mess);
void	send_signal(pid_t pid, int sig);
void	exit_all(void);

/* LIBFT */
int		ft_printf(const char *s, ...);

typedef struct s_mess {
	char	*mess;
	char	*size;
}	t_mess;

#endif
