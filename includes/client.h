/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:30 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/10 19:00:05 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"

void	error(void);
char	*binary_converter(char *str);
void	send_message(char *bin, pid_t pid, int end_mess);
void	send_signal(pid_t pid, int sig);
int		ft_printf(const char *s, ...);
void	handler(int signum);
char	*int_to_bin(int n);

#endif
