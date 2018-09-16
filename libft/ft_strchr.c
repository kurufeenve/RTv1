/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:31:08 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/08 14:31:46 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	*buf;

	buf = (char *)s;
	while (*buf != (char)c)
	{
		if ((char)c != '\0' && *buf == '\0')
			return (NULL);
		buf++;
	}
	return (buf);
}
