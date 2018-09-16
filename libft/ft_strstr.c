/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:41:59 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/08 16:42:02 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	char	*buf;
	size_t	s;

	if (needle[0] == '\0')
		return ((char *)haystack);
	s = ft_strlen(needle);
	buf = (char *)malloc(sizeof(char) * (s + 1));
	while (*haystack != '\0')
	{
		ft_strclr(buf);
		ft_strncpy(buf, haystack, s);
		buf[s] = '\0';
		if (ft_strcmp(buf, needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
