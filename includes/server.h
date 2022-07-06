/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:38:36 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/21 17:19:09 by rmorel           ###   ########.fr       */
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

/* SERVER.C */
void	handler(int signo, siginfo_t *info, void *context);
int		bin_to_int(char *str);
int		check_end(void);
void	print_string(void);

/* SERVER_UTILS.C */
int		size_bin_char(char *msg);
char	*bin_to_str(char *msg);
void	refresh_global(void);
void	malloc_message(void);

/* LIBFT */
int		ft_printf(const char *s, ...);
void	ft_bzero(void *s, size_t n);

typedef struct s_stock {
	pid_t			pidclient;
	int				i;
	char			*message;
	char			*size_mess;
}	t_stock;

#endif
