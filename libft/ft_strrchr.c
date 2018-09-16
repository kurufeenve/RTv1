/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:25:52 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/08 15:25:55 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	*buf;

	i = ft_strlen(s);
	buf = (char *)s;
	while (i > -1)
	{
		if (buf[i] == (char)c)
			return ((buf + i));
		i--;
	}
	return (NULL);
}
