/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:05:28 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/01 14:07:42 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*copy;

	if (s == NULL)
		return (0);
	start = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strdup((char *)s + i));
	start = i;
	i = ft_strlen(s) - 1;
	end = i;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	end = i;
	if (!(copy = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	s += start;
	ft_strncpy(copy, s, (end - start + 1));
	copy[end - start + 1] = '\0';
	return (copy);
}
