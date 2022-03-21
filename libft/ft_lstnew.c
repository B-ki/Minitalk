/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:15:53 by rmorel            #+#    #+#             */
/*   Updated: 2021/11/30 17:30:53 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(*lstnew));
	if (lstnew)
	{
		lstnew->content = content;
		lstnew->next = NULL;
		return (lstnew);
	}
	return (NULL);
}
