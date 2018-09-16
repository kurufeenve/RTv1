/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:29:36 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/06 16:29:41 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(char const *s)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup[len] = '\0';
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
