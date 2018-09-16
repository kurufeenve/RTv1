/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:07:16 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 18:55:56 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*buf;

	if (lst == NULL || f == NULL)
		return ;
	buf = lst;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
	lst = buf;
}
