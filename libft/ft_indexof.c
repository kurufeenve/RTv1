/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:16:19 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/30 20:16:21 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_indexof(char const *h, char const *n, size_t start, int f)
{
	size_t	i;

	i = 0;
	while (h[start] != '\0' && n[i] != '\0')
	{
		if (n[i] == '\0')
			return (f);
		if (h[start] == n[i] && f == -1)
			f = (int)start;
		if (h[start] == n[i])
		{
			i++;
			start++;
			continue ;
		}
		if (h[start] != n[i])
		{
			f = -1;
			i = 0;
		}
		if (h[start] != n[i] && h[start + 1] == '\0')
			return (-1);
		start++;
	}
	return (f);
}
