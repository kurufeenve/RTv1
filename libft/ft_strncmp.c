/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:00:20 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 19:05:28 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < len && s1[i] != '\0' && s2[i] != '\0')
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (i != len)
		return (a[i] - b[i]);
	return (0);
}
