/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:26:44 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/02 19:20:34 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*copy;
	size_t	j;

	if (s == NULL || f == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (!(copy = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	copy[j] = '\0';
	while (s[--j])
		copy[j] = f(s[j]);
	return (copy);
}
