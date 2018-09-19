/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:14:49 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/01 12:02:52 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	i;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	res[l] = '\0';
	i = 0;
	while (i < l)
	{
		if (*s1 != '\0')
		{
			res[i++] = *s1;
			s1++;
		}
		if (*s1 == '\0' && *s2 != '\0')
		{
			res[i++] = *s2;
			s2++;
		}
	}
	return (res);
}
