/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:18:44 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 19:06:48 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*new;
	t_list	*buf_new;

	if (lst == NULL || f == NULL)
		return (NULL);
	buf = lst;
	new = f(buf);
	buf_new = new;
	while (buf->next != NULL)
	{
		new->next = f(buf->next);
		buf = buf->next;
		new = new->next;
	}
	return (buf_new);
}
