/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:03:55 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/02 19:21:58 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	char			*copy;

	if (s == NULL || f == NULL)
		return (NULL);
	j = (unsigned int)ft_strlen(s);
	if (!(copy = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	copy[j] = '\0';
	while (j--)
		copy[j] = f(j, s[j]);
	return (copy);
}
