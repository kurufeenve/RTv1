/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:18:29 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 18:56:39 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		a->content = NULL;
		a->next = NULL;
		return (a);
	}
	a->content_size = content_size;
	a->content = ft_strnew(content_size);
	if (content != NULL)
		ft_memcpy(a->content, content, content_size);
	else
		a->content_size = 0;
	a->next = NULL;
	return (a);
}
