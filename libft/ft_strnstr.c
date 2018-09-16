/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:32:09 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/08 17:32:12 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	need;
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	need = ft_strlen(needle);
	i = 0;
	while (haystack[0] != '\0' && i <= len - need && need <= len)
	{
		if (ft_strncmp(haystack, needle, need) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
