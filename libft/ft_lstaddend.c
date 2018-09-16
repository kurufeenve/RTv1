/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:14:31 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/21 14:14:33 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*buff;

	if (new == NULL || (*alst == NULL && (*alst = new)))
		return ;
	buff = *alst;
	while (buff->next != NULL)
		buff = buff->next;
	buff->next = new;
}
