/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:38:36 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/11 12:45:55 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"
# include <stdbool.h>

void	handler(int signo, siginfo_t *info, void *context);
_Bool	printer(void);
int		size_bin_char(char *msg);
char	*bin_to_str(char *msg);
int		check_end(void);
int		ft_printf(const char *s, ...);
void	ft_bzero(void *s, size_t n);
int		bin_to_int(char *str);
void	refresh_global(void);

typedef struct s_stock {
	pid_t			pidclient;
	int				i;
	char			*message;
	char			*size_mess;
}	t_stock;

#endif
