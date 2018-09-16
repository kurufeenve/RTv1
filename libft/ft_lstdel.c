/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:05 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/13 15:56:07 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*buf;

	ptr = *alst;
	if (del == NULL || alst == NULL || *alst == NULL)
		return ;
	while (ptr != NULL)
	{
		buf = ptr->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = buf;
	}
	*alst = NULL;
}
