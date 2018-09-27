/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:12:18 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/27 21:12:20 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnsub(char const *s, size_t start, size_t end)
{
	char	*res;
	char	*buf;

	if (s == NULL)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	buf = res;
	res[end - start] = '\0';
	while (start <= end && s[start] != '\0')
	{
		*res = s[start];
		res++;
		start++;
	}
	return (buf);
}
